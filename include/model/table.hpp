#ifndef TABLEMODEL_HPP
#define TABLEMODEL_HPP

#include <iostream>

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
    virtual bool Insert_data(std::string sql);
    // 删除数据
    virtual bool Delete_data(std::string sql);
    // 修改数据
    virtual bool Update_data(std::string sql) ;
    // 查询操作
    virtual std::string Query_data(std::string sql);
protected:
    std::string _table;
    Logger logger;
};

#endif