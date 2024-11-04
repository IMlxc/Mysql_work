#include "db.hpp"
#include "controlmodel.hpp"
#include <iostream>
#include <functional>

// 添加加数据
bool Control_Model::Insert_data(std::string sql)
{
    MySQL* mysql;
    if (!mysql->connect())
    {
        // std::cerr << ""
        return false;
    }
    return true;
}
// 删除数据
bool Control_Model::Delete_data(std::string sql)
{
    MySQL* mysql;
    if (!mysql->connect())
    {
        // std::cerr << ""
        return false;
    }
    return true;
}
// 修改数据
bool Control_Model::Update_data(std::string sql)
{
    MySQL* mysql;
    if (!mysql->connect())
    {
        // std::cerr << ""
        return false;
    }
    return true;
}
//HACK 引入json文件, 应该是string导出
// 查询操作
std::string Control_Model::Query_data(std::string sql)
{
    MySQL* mysql;
    if (!mysql->connect())
    {
        // std::cerr << ""
        return nullptr;
    }

    // TODO 查询转化为json
    // return mysql->query(sql);
}