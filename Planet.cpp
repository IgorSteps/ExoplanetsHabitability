/******************************************************
 *
 * File         : Planet.cpp
 *
 * Date         : Tuesday 18th January 2022
 *
 * Author       : Igor Stepanenko
 *
 * Description  : Cpp class with overloaded I/0 operators to
 *                read in a text file.
 *
 ***************************************************** */

#include <iomanip>
#include "Planet.h"
using namespace std;

std::ostream& operator<<(std::ostream &os, const Planet& p){
    return os << std::quoted(p.getName()) << ", "
              << std::quoted(p.getSystem()) << ", "
              << std::quoted(p.getMethod()) << ", "
              << p.getYear() << ", "
              << std::quoted(p.getFacility()) << ", "
              << p.getRadius() << ", "
              << p.getMass() << ", "
              << p.getTemperature() ;
}

istream& operator>>(istream &is, Planet &p)
{
    std::string name, system, method, facility, year,
    temperature, radius, mass;
    char c1, c2, c3, c4;

    if (is >> quoted(name) >> c1 >> quoted(system) >> c2
           >> quoted(method) >> c3 >> year
           >> quoted(facility) >> c4 >> radius >> mass >> temperature)
    {
        if (c1 == ',' &&
            c2 == ',' &&
            c3 == ',' &&
            year.back() == ',' &&
            c4 == ',' &&
            radius.back() == ',' &&
            mass.back() == ',')
        {
            p = Planet(name.substr(0, name.length()),
                       system.substr(0, system.length()),
                       method.substr(0, method.length()),
                       stoi(year),
                       facility.substr(0, facility.length()),
                       stod(radius),
                       stod(mass),
                       stoi(temperature), 0);
        }
        else
        {
            is.clear(std::ios_base::failbit);
        }
    }
    return is;
}