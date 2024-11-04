#include "log.hpp"

Logger& Logger::operator<<(const std::string& Msg)
{
    std::ofstream logFile("log.txt", std::ios_base::app);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char now_time[256];
    sprintf(now_time, "%04d-%02d-%02d %02d:%02d:%02d  ",
        1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
        ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    if (logFile.is_open())
    {
        logFile << now_time << Msg << std::endl;
        logFile.close();
    }
    return *this;
}