/**
* @file DateCalc.cpp
* @brief  Final project, designed to take from a dataset and calculate the times between hurricane and log them.
*
* @author Joseph Marchesini
* @assignment Final Prject
* @date 12/13/2020
* @credits https://sites.google.com/site/sbobovyc/home/Programming/CC-code-snippets/boost-command-line-parsing AND https://www.boost.org/doc/libs/1_47_0/doc/html/date_time/examples.html AND https://theboostcpplibraries.com/boost.datetime-calendar
* 
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/program_options.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "file.h"

using namespace std;
using namespace boost::program_options;
using namespace boost::gregorian;

int main(int argc, char **argv)
{
    string inputFile, outputFile;

    // Declare supported options.
    options_description desc("Options");
    desc.add_options()
        ("inputFile", value<string>(&inputFile), "set inputFile")
        ("outputFile", value<string>(&outputFile), "set outputFile");

    //Parse options
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);  

    //Checking options
    if (vm.count("inputFile"))
        cout << "inputFile: " << inputFile << "\n";
    else
    {
        cout << "Missing input file name..." << "\n";
        return 0;
    }
    if (vm.count("outputFile"))
        cout << "outputFile: " << outputFile << "\n";
    else
    {
        cout << "Missing output file name..." << "\n";
        return 0;
    }

    //Days between dates calculations
    vector<hurricane> hs = fileInput(inputFile);
    vector<days> daysBetween;
    days numDays;
    int i, k;

    for(i = 1, k = 0; i < hs.size(); i++, k++)
    {
        numDays = hs[i].d - hs[k].d;
        daysBetween.push_back(numDays);
    }

    fileOutput(outputFile, hs, daysBetween);

    return EXIT_SUCCESS;
}