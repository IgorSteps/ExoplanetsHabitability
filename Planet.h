/******************************************************
 *
 * File         : Planet.h
 *
 * Date         : Tuesday 18th January 2022
 *
 * Author       : Igor Stepanenko
 *
 * Description  : Header file for Planet class with accessor
 *                methods, constructors and overloaded rela-
 *                tional operators.
 *
 *
 ***************************************************** */

#ifndef CPPSUMMATIVE_PLANET_H
#define CPPSUMMATIVE_PLANET_H


#include <string>

class Planet {

private:
    std::string name, system, method, facility;
    int year, temperature;
    double radius, mass, habitability;

public:
    //Getters and setters
    inline const std::string& getName() const{return name;}
    inline const std::string& getSystem() const{return system;}
    inline const std::string& getMethod() const{return method;}
    inline const std::string& getFacility() const{return facility;}
    inline int getYear() const{return year;}
    inline int getTemperature() const{return temperature;}
    inline double getRadius() const{return radius;}
    inline double getMass() const{return mass;}
    inline double getHabitability() const{return habitability;}
    inline double setHabitability(double newHabty){return habitability=newHabty;}

    //Constructors
    Planet()=default;
    Planet(const std::string name, std::string system, std::string method,
           int year, std::string facility,  double radius, double mass,
           int temperature,  double habitability)
    {
        this->name          = name;
        this->system        = system;
        this->method        = method;
        this->year          = year;
        this->facility      = facility;
        this->radius        = radius;
        this->mass          = mass;
        this->temperature   = temperature;
        this->habitability  = habitability;
    }

};


//Overloaded operators
std::ostream& operator<<(std::ostream &os, const Planet& p);
std::istream& operator>>(std::istream &is, Planet &p);

inline bool operator==(Planet &D, Planet &F){
    return (D.getHabitability() == F.getHabitability());
}
inline bool operator!=(Planet &D, Planet &F){
    return !(D == F);
}
inline bool operator<(const Planet &D, const Planet &F){
    return (D.getHabitability() < F.getHabitability());
}
inline bool operator>(const Planet &D, const Planet &F){
    return (D.getHabitability() > F.getHabitability());
}
inline bool operator<=(const Planet &D, const Planet &F){
    return !(D > F);
}
inline bool operator>=(const Planet &D, const Planet &F) {
    return !(D < F);
}


#endif //CPPSUMMATIVE_PLANET_H
