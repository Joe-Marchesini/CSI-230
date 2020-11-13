/**
* @file lab10.2.cpp
* @brief  logger.cpp file
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits bilbo baggins
* 
*/

#include "logger.h"

bool log(std::string msg, std::string progamName, std::ofstream& logFile)
{
    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }

    std::string strProgramName = progamName;
    pid_t pid = getpid();
    char hostname[1024];
    gethostname(hostname, 1024);
    std::string strHostName = hostname;
    if(logFile)
    {
        logFile << strTime << strHostName << " " << strProgramName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }

}