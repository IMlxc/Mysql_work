#include "log.hpp"
#include "db.hpp"
#include <iostream>

Logger logger;

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
        // C和C++代码默认编码为ascii码，如果不修改就是中文乱码
        mysql_query(_conn, "set names gbk");

        // 将数据库作为gbk访问
        mysql_options(_conn, MYSQL_SET_CHARSET_NAME, "GBK");

        logger << "connect Mysql Successed !";
    }
    else
    {
        std::cerr << "connect Mysql failed !" << std::endl;

        logger << mysql_error(_conn);
    }
    return p;
}

// 更新操作
bool MySQL::update(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        std::cerr << sql << "update failed" << std::endl;

        logger << mysql_error(_conn);
        return false;
    }
    return true;
}
// 查询操作
MYSQL_RES *MySQL::query(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        std::cerr << sql << "query failed!" << std::endl;
        logger << mysql_error(_conn);
        return nullptr;
    }
    return mysql_use_result(_conn);
}

// 获取连接
MYSQL *MySQL::getConnection()
{
    return _conn;
}