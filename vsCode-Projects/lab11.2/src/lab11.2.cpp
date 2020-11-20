/**
* @file lab11.2.cpp
* @brief  Lab 11.2 driver
*
* @author Joseph Marchesini
* @assignment Lecture 10.2
* @date 11/19/2020
* @credits https://sites.google.com/site/sbobovyc/home/Programming/CC-code-snippets/boost-command-line-parsing AND https://www.boost.org/doc/libs/1_71_0/doc/html/accumulators/user_s_guide.html
* 
*/

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>

using namespace std;
using namespace boost::program_options;
using namespace boost::accumulators;
namespace po = boost::program_options;

int main(int argc, char **argv)
{
    double var1, var2, var3, var4;
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("var1", po::value<double>(&var1), "set var1");

    //Parse options
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);   

    if (vm.count("var1")) {
        cout << "var1 was set to "
            << vm["var1"].as<double>() << ".\n";
    } else {
        cout << "var1 was not set.\n";
    }

    cout << "Setting extra values for calculations..." << endl; 
    var2 = 40.1;
    var3 = 15.0;
    var4 = 23.5;

    cout << "Creating acc..." << endl;
    accumulator_set<double, stats<tag::mean, tag::moment<2> > > acc;

    cout << "Adding values to acc..." << endl;
    acc(var1);
    acc(var2);
    acc(var3);
    acc(var4);

    cout << "Calculating mean and moment:" << endl;
    cout << "Mean:   " << mean(acc) << endl;
    cout << "Moment: " << moment<2>(acc) << endl;
    

    return EXIT_SUCCESS;
}