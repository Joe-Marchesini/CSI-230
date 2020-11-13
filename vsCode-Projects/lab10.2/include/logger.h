/**
* @file lab10.2.cpp
* @brief  logger.h file
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits bilbo baggins
* 
*/

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <unistd.h>

bool log(std::string msg, std::string progamName, std::ofstream& logFile);
#endif