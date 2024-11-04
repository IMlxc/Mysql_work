#ifndef CONTROLMODEL_HPP
#define CONTROLMODEL_HPP

#include <string>

// 控制模块
class Control_Model
{
public:
    // 添加加数据
    virtual bool Insert_data(std::string sql);
    // 删除数据
    virtual bool Delete_data(std::string sql);
    // 修改数据
    virtual bool Update_data(std::string sql);
    //HACK 引入json文件, 应该是string导出
    // 查询操作
    virtual std::string Query_data(std::string sql);
protected:
    std::string table;
};

#endif