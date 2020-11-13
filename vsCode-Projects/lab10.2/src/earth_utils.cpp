/**
* @file lab10.2.cpp
* @brief  earth_utils.cpp file
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits bilbo baggins
* 
*/

#include "earth_utils.h"

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    std::ofstream kmlFile;
    kmlFile.open (kmlFileName);

    kmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    kmlFile << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << std::endl;
    kmlFile << "<Document>" << std::endl;

    if(inFile)
    {
        getline(inFile, strLine);
        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strCountry, ',');
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');

            //debug line
            std::cout << strCountry << "~" << strCapital << "~" << strLat << "~" << strLong << std::endl;

            std::string name = strCountry + ", " + strCapital;

            WritePlacemark(kmlFile, name, strLat, strLong);
        }
    }

    kmlFile << "</Document>" << std::endl;
    kmlFile << "</kml>" << std::endl;

    kmlFile.close();
    return recordCount;
}

void WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << "<Placemark>" << std::endl;
    kmlFile << "<name>" << name << "</name>" << std::endl;
    kmlFile << "<Point>" << "<coordinates>" << latitude << "," << longitude << "</coordinates>" << "</Point>" << std::endl;
    kmlFile << "</Placemark>" << std::endl;
}