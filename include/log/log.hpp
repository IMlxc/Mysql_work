#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <string>
#include <ctime>

// 日志
class Logger
{
public:
    Logger& operator<<(const std::string& Msg);
};

#endif