/**
* @file lab10.2.cpp
* @brief  Lab 10.2 driver
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits bilbo baggins
* 
*/

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"
#include "earth_utils.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue;
    string kmlValue;
    bool optErr = true;
    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k':
                kmlFlag = true;
                kmlValue = optarg;
                break;
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr = true;
                break;
        }
    }
    cout << "flags - kmlFlag:" << kmlFlag << " logFlag:" << logFlag << endl;

    if(kmlFlag && logFlag)
    {
        cout << "Flags set!" << endl;
        if(logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            cout << "option arguments are not set" << endl;
        }
        else
        {
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "The kmlfile is:" + kmlValue + " and logfile is: " + logValue;
                log(msg, programName, flog);
                optErr = false;
                flog.close();

                ifstream inFile;
                inFile.open(kmlValue);
                if(inFile)
                {
                    int recordCount = processCSV(inFile, kmlValue + ".kml");
                    inFile.close();
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl;
                        optErr = false;
                    }
                    else
                    {
                        optErr = true;
                    }

                }
            }
            else
            {
                cout << "couldn't open " << logValue << endl;
                optErr = true;
            }
        }
    }
    else
    {
        cout << "error - flags are not set!" << endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }

    cout << "The kmlfile is:" << kmlValue << " and logfile is:" << logValue << endl;
    cout << "optErr:" << optErr << endl;

    return EXIT_SUCCESS;
}