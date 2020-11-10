/**
* @file util.cpp
* @brief  Cpp file for util, holds functions code
*
* @author Joseph Marchesini
* @assignment Lecture 10.1
* @date 11/9/2020
* @credits
* 
*/

#include "util.h"

string randomElement(vector<string> list)
{
    srand (time(NULL));
    int randomNum = rand() % 5;
    return list[randomNum];
}

double sum(vector<double> list2)
{
    int i;
    double sum = 0;

    for(i = 0; i < list2.size(); i++)
    {
        sum += list2[i];
    }

    return sum;
}

double avg(vector<double> list2)
{
    double avg;

    avg = sum(list2) / list2.size();
    
    return avg;
}

double lowest(vector<double> list2)
{
    int i;
    double lowest;

    lowest = list2[0];
    for(i = 0; i < list2.size(); i++)
    {
       if(list2[i] < lowest)
           lowest = list2[i];
    }

    return lowest;
}

string camelCase(string multiWord)
{
    int i, count = 0;

    multiWord[0] = tolower(multiWord[0]);
    for(i = 0; i < multiWord.size(); i++)
    {
        if(multiWord[i] == ' ')
            multiWord[i + 1] = toupper(multiWord[i + 1]);
        else
            multiWord[count++] = multiWord[i];
    }
    return multiWord;
}