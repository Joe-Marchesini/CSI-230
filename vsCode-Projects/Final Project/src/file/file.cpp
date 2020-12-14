/**
* @file file.cpp
* @brief  Shared Object Library for file manipulation
*
* @author Joseph Marchesini
* @assignment Final Prject
* @date 12/13/2020
* 
*/
#include "file.h"

vector<hurricane> fileInput(string filename)
{
    vector<hurricane> ret;
    int i;
    string line;

    ifstream data;
    data.open(filename);

    while (getline(data, line))
    {
        stringstream   linestream(line);
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string name, location, categoryStr, dayStr, monthStr, yearStr, junk;
        int category, day, month, year;
        date d;

        getline(linestream, location, '\t');
        getline(linestream, name, '\t');
        getline(linestream, categoryStr, '\t');
        getline(linestream, dayStr, '-');
        getline(linestream, monthStr, '-');
        getline(linestream, junk, '\t');
        getline(linestream, yearStr, '\n');

        stringstream c(categoryStr);
        stringstream da(dayStr);
        stringstream y(yearStr);

        c >> category;
        da >> day;
        y >> year;

        for(i = 0; i < 12; i++)
        {
            if(monthStr == months[i])
                month = i + 1;
        }

        d = {year, month, day};

        hurricane h = {name, location, category, d};

        ret.push_back(h);
    }

    data.close();
    return ret;
}

void fileOutput(string filename, vector<hurricane> hs, vector<days> daysBetween)
{
    int i;
    double avgDaysTotal, avgDays1950, avgDays1999, avgDays2017;
    double hsTotal, hs1950, hs1999, hs2017;
    double daysTotal, days1950, days1999, days2017;
    date d1951 = {1951, 1, 1};
    date d2000 = {2000, 1, 1};

    hsTotal = hs.size();

    for(i = 0; i < hsTotal; i++)
    {
        if(hs[i].d < d1951)
            hs1950++;
        else if(hs[i].d < d2000)
            hs1999++;
        else
            hs2017++;
    }

    for(i = 0; i < daysBetween.size(); i++)
    {
        int numDays = daysBetween[i].days();
        if(hs[i].d < d1951)
            days1950 += numDays;
        else if(hs[i].d < d2000)
            days1999 += numDays;
        else
            days2017 += numDays;

        daysTotal += numDays;
    }

    avgDaysTotal = daysTotal / hsTotal;
    avgDays1950 = days1950 / hs1950;
    avgDays1999 = days1999 / hs1999;
    avgDays2017 = days2017 / hs2017;

    ofstream out;
    out.open(filename);

    out << "Total average days inbetween hurricanes: " << avgDaysTotal << endl;
    out << "Average days inbetween hurricanes from 1900-1950: " << avgDays1950 << endl;
    out << "Average days inbetween hurricanes from 1952-1999: " << avgDays1999 << endl;
    out << "Average days inbetween hurricanes from 2003-2017: " << avgDays2017 << endl;
    out << endl;
    out << "List of days inbetween each hurricane:" << endl;

    for(i = 0; i < hsTotal; i++)
    {
        out << "Hurricane: " << hs[i].name << ", category " << hs[i].category << ", in " << hs[i].location << ", on " << hs[i].d << endl;
        if(i+1 < hsTotal)
            out << "Days between hurricanes: " << daysBetween[i].days() << endl;
    }

    out.close();
}