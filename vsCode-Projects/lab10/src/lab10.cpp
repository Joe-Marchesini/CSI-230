/**
* @file lab10.cpp
* @brief  C++ warm up program stub driver
*
* @author Joseph Marchesini
* @assignment Lecture 10.1
* @date 11/9/2020
* @credits Bilbo Baggins
* 
*/

#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

int main()
{
    vector<string> list;
    vector<double> list2;
    string word, multiWord = "A little bird with a yellow bill";
    double num;
    int i;

    for(i = 0; i < 5; i++)
    {
        word = "Word" + to_string(i);
        list.push_back(word);
        cout << word << endl;
    }

    cout << "Random string from list: " << randomElement(list) << endl;

    for(i = 0; i < 5; i++)
    {
        num = i;
        list2.push_back(num);
    }

    cout << "Sum of list2: " << to_string(sum(list2)) << endl;
    cout << "Avg of list2: " << to_string(avg(list2)) << endl;
    cout << "Lowest of list2: " << to_string(lowest(list2)) << endl;

    cout << "camelCase fucntion called with: " << multiWord << endl;
    cout << "String after camelCase call: " << camelCase(multiWord) << endl;

    return EXIT_SUCCESS;
}