/*
 * @Author: Xinkong 2790109834@qq.com
 * @Date: 2024-10-30 23:25:09
 * @LastEditors: Xinkong 2790109834@qq.com
 * @LastEditTime: 2024-11-05 23:52:51
 * @FilePath: \Mysql_work\src\model\table.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#include "db.hpp"
#include "table.hpp"
#include <iostream>
#include <functional>

// 组装语句

// HACK 将注册表中的所有列及其类型
// 初始化
Table::Table(std::string table)
{
    _table = table;
    // _column = &column;
}

// 释放
Table::~Table()
{
    _table = std::string();
    _column = nullptr;
}

// 例子 "insert into txt(id, name), values(1, "Xin")"
// 其中txt的column有多个列, 每一个列对应一个value => json形式

/**
 * @description: 添加数据
 * @return {bool} 操作成功是否
 */
bool Table::Insert_data(json data)
{
    MySQL* mysql = new MySQL();
    if (!mysql->connect())
    {
        return false;
    }

    char sql[1024];

    // 获取输入内容, 转化例子txt()的内容
    // 获取输入内容, 转化为values
    json columns = json::array();
    json values = json::array();
    // 读取json文件, 进行转化
    for (auto& [key, value] : data.items())
    {
        columns.push_back(key);
        values.push_back(value);
    }
    // json转string
    std::string columns_str = columns.dump();
    std::string values_str = values.dump();
    // 将columns中的 " 移除
    columns_str.erase(std::remove(columns_str.begin(), columns_str.end(), '"'), columns_str.end());
    // 组装sql语句, 注意转化,是const char*的类型, 否则无法输入
    sprintf(sql, "insert into %s (%s) values(%s);", 
            _table.c_str(), 
            columns_str.substr(1, columns_str.size() - 2).c_str(), 
            values_str.substr(1, values_str.size() - 2).c_str()
    );
    // 调用update, 更新数据库
    return mysql->update(sql);
}

// TODO 调用MySQL类的update实现
// 删除数据
bool Table::Delete_data(json data)
{
    MySQL* mysql = new MySQL();

    if (!mysql->connect())
    {
        return false;
    }

    std::string condition; //存放要删的条件

    for(auto&[key, value] : data.items())
    {
        condition += key + "=";

        if(value.is_string()){//判断是不是字符串类型
            condition += "'" + value.get<std::string>() + "'";
        }

        else if(value.is_number())//是数字类型的话
        {
            condition += std::to_string(value.get<int>()); //将数字转换为字符串
        }

        else{
            condition += value.dump(); //其他类型会用dump自动转化为字符串
        }

        condition += " and ";
    }

    //移除多余的and
    if(!condition.empty())
    {
        condition.erase(condition.size() - 5);
    }
    char sql[1024];
    sprintf(sql, "delete from %s where %s;",
            _table.c_str(),
            condition.c_str()
    );

    std::cout << "generate sql: " << sql << std::endl; //生成一遍MySQL语句便于查找错误

    return mysql->update(sql);
}

// TODO 调用MySQL类的update实现
// 修改数据
bool Table::Update_data(json data)
{
    MySQL* mysql = new MySQL();

    if (!mysql->connect())
    {
        return false;
    }
    return true;
}

// HACK 调用MySQL类的query实现
// 查询操作1
std::string Table::Query_data(json data)
{

    MySQL* mysql =  new MySQL();
    if (!mysql->connect())
    {
        logger << "连接失败" << mysql_error(mysql->getConnection());
        return std::string();
    }
    
    char sql[1024];

    // 获取查询数据
    MYSQL_RES* res = mysql->query(sql);
    if (res != nullptr)
    {
        // 将数据转化为 => json => string返回
        json data;
        MYSQL_ROW row;

        while((row = mysql_fetch_row(res)) != nullptr)
        {
            data.push_back({
                {"id", std::atoi(row[0])},
                {"name", row[1]}
            });
        }        
        return data.dump();
    }
    
    logger << mysql_error(mysql->getConnection());
    // 失败返回空
    return std::string();
}