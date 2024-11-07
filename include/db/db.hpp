/*
 * @Author: Xinkong 2790109834@qq.com
 * @Date: 2024-10-30 20:52:25
 * @LastEditors: Xinkong 2790109834@qq.com
 * @LastEditTime: 2024-11-05 21:28:59
 * @FilePath: \Mysql_work\include\db\db.hpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef DB_HPP
#define DB_HPP

#include "mysql.h"
#include "log.hpp"

#include <iostream>


#include <string>

/**
 * @description: 定义连接Mysql的基本信息
 */
extern std::string host;
extern std::string user;
extern std::string password;
extern std::string db;
extern std::string port;

class MySQL
{
public:
    // 初始化数据库连接
    MySQL();
    // 释放数据库连接资源
    ~MySQL();
    // 连接数据库
    bool connect();
    // 更新操作
    bool update(std::string sql);
    // 查询操作
    MYSQL_RES* query(std::string sql);
    // 获取连接
    MYSQL *getConnection();

private:
    MYSQL *_conn;
    Logger logger;
};

#endif