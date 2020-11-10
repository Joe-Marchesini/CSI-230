/**
* @file util.h
* @brief  Header file for util, holds functions definition
*
* @author Joseph Marchesini
* @assignment Lecture 10.1
* @date 11/9/2020
* @credits
* 
*/
#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

string randomElement(vector<string> list);
double sum(vector<double> list2);
double avg(vector<double> list2);
double lowest(vector<double> list2);
string camelCase(string multiWord);

#endif