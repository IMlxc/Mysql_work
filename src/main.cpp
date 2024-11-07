/*
 * @Author: Xinkong 2790109834@qq.com
 * @Date: 2024-10-30 08:24:57
 * @LastEditors: Xinkong 2790109834@qq.com
 * @LastEditTime: 2024-11-05 23:26:03
 * @FilePath: \Mysql_work\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include "json.hpp"
using namespace nlohmann;
#include "mysql.h"


#include "db.hpp"
#include "table.hpp"


// 数据库配置信息, 默认
const std::string init_host = "127.0.0.1";
const std::string init_user = "xinkong";
const std::string init_password = "123456";
const std::string init_db = "txt";
const std::string init_port = "3306";

std::string host = init_host;
std::string user = init_user;
std::string password = init_password;
std::string db = init_db;
std::string port = init_port;


int main(int argc, char* argv[])
{
	// // 连接前端

	// // 连接信息
	// if (argc > 4)
	// {
	// 	std::string s = argv[0];
	// 	int target = 5;
	// 	if (s.find("Godot")) ++target;
		
	// 	port = argv[--target];
	// 	db = argv[--target];
	// 	password = argv[--target];
	// 	user = argv[--target];
	// 	host = argv[--target];
	// }

	// db = ""

	// Table* Student = new Table("student");
	Table* T = new Table("T");
	// std::string res = T->Query_data("select * from Student");
	// json data = {
	// 	{"id", 1},
	// 	{"name", "xin"}
	// };

	json data = {
		{"name", "xinkong"},
		{"Sno", "23001"},
		{"Sex", "man"}
	};
	
	bool f = T->Insert_data(data);
	if (f)
	{
		std::cout << "YES" << std::endl;
	}
	// if (!res.empty())
	// {
		// std::cout << res << std::endl;
	// }
	while(true);
	return 0;

}
