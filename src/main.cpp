#include "mysql.h"
#include "db.hpp"
#include <iostream>
#include <string>

#include "json.hpp"
using namespace nlohmann;

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


	MySQL* mysql = new MySQL();
	if (!mysql->connect())
	{
		return -1;
	}

	// // mysql->update("insert into student values(1, 'Xinkong')");
	// MYSQL_RES* res = mysql->query("select * from student");

	// MYSQL_ROW row;
	// json data;
	// while((row = mysql_fetch_row(res)) != NULL)
	// {
	// 	data.push_back({
	// 		{"id", std::atoi(row[0])},
	// 		{"name", row[1]}
	// 	});
	// }

	// std::cout << data.dump() << std::endl;
	while(true);

	return 0;

}
