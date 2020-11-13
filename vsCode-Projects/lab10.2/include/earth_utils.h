/**
* @file lab10.2.cpp
* @brief  earth_utils.h file
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits bilbo baggins
* 
*/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int processCSV(std::ifstream& inFile, std::string kmlFileName);

void WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude);

#endif