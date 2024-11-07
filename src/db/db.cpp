/*
 * @Author: Xinkong 2790109834@qq.com
 * @Date: 2024-10-30 21:01:11
 * @LastEditors: Xinkong 2790109834@qq.com
 * @LastEditTime: 2024-11-05 23:37:06
 * @FilePath: \Mysql_work\src\db\db.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "db.hpp"

// 初始化数据库连接
MySQL::MySQL()
{
    _conn = mysql_init(nullptr);
}
// 释放数据库连接资源
MySQL::~MySQL()
{
    if (_conn != nullptr)
        mysql_close(_conn);
}
// 连接数据库
bool MySQL::connect()
{
    // 创建mysql表的指针
    MYSQL *p = mysql_real_connect(_conn, host.c_str(), 
                                        user.c_str(),
                                        password.c_str(), 
                                        db.c_str(), 
                                        std::atoi(port.c_str()), NULL, 0);

    if (p != nullptr)
    {

        // 将数据库作为gbk访问
        mysql_options(_conn, MYSQL_SET_CHARSET_NAME, "GBK");

        logger << "Mysql 连接成功 !";
    }
    
    else
    {
        logger << "Mysql 连接失败 !" << mysql_error(_conn);
    }
    return p;
}

// 更新操作
bool MySQL::update(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        logger << "更新失败" << mysql_error(_conn);
        return false;
    }
    return true;
}
// 查询操作
MYSQL_RES *MySQL::query(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        logger << "查询失败" << mysql_error(_conn);
        return nullptr;
    }
    return mysql_use_result(_conn);
}

// 获取连接
MYSQL *MySQL::getConnection()
{
    return _conn;
}