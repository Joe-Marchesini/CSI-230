/**
* @file file.h
* @brief  Shared Object Library for file manipulation declaration
*
* @author Joseph Marchesini
* @assignment Final Prject
* @date 12/13/2020
* 
*/
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;
using namespace boost::gregorian;

struct hurricane {
    string name;
    string location;
    int category;
    date d;
};

vector<hurricane> fileInput(string filename);

void fileOutput(string filename, vector<hurricane> hs, vector<days> daysBetween);

#endif