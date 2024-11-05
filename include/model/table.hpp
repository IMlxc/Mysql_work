/*
 * @Author: Xinkong 2790109834@qq.com
 * @Date: 2024-10-30 23:12:06
 * @LastEditors: Xinkong 2790109834@qq.com
 * @LastEditTime: 2024-11-05 15:31:08
 * @FilePath: \Mysql_work\include\model\table.hpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#ifndef TABLEMODEL_HPP
#define TABLEMODEL_HPP

#include <iostream>
#include <map>
#include <string>
#include "json.hpp"
using namespace nlohmann;

#include "log.hpp"

// 控制模块
class Table
{
public:
    // 初始化
    Table(std::string table);
    // 释放
    ~Table();
    // 添加加数据
    virtual bool Insert_data(json data);
    // 删除数据
    virtual bool Delete_data(json data);
    // 修改数据
    virtual bool Update_data(json data);
    // 查询操作
    virtual std::string Query_data(json data);

protected:
    // table的名称
    std::string _table;
    // 错误日志
    Logger logger;
    // table的结构注册
    std::map<std::string, std::string>* _column;
};

#endif