#include "db.hpp"
#include "table.hpp"
#include <iostream>
#include <functional>

// 组装语句

// 初始化
Table::Table(std::string table)
{
    _table = table;
}

// 释放
Table::~Table()
{
    _table = std::string();
}

// 添加加数据
bool Table::Insert_data(std::string sql)
{
    MySQL* mysql = new MySQL();
    if (!mysql->connect())
    {
        return false;
    }
    return true;
}
// 删除数据
bool Table::Delete_data(std::string sql)
{
    MySQL* mysql = new MySQL();

    if (!mysql->connect())
    {
        return false;
    }
    return true;
}
// 修改数据
bool Table::Update_data(std::string sql)
{
    MySQL* mysql = new MySQL();

    if (!mysql->connect())
    {
        return false;
    }
    return true;
}
// 查询操作
std::string Table::Query_data(std::string sql)
{

    MySQL* mysql =  new MySQL();
    if (!mysql->connect())
    {
        logger << mysql_error(mysql->getConnection());

        return nullptr;
    }
    
    MYSQL_RES* res = mysql->query(sql);
    if (res != nullptr)
    {
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

    std::cout << "query failed" << std::endl;

    return std::string();
}