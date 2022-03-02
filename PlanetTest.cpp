/******************************************************
 *
 * File         : PlanetTest.cpp
 *
 * Date         : Tuesday 18th January 2022
 *
 * Author       : Igor Stepanenko
 *
 * Description  : Cpp class with unit-testing and test-harness
 *                for Planet.h class
 *
 *
 ***************************************************** */

#include <iostream>
#include <cassert>
#include "Planet.h"
using namespace std;

bool test1(){
    double habitability = 8;
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);
    p.setHabitability(habitability);
    if (p.getHabitability()!=habitability) {
        cout << "test 1 failed, habitability should be " << habitability << endl;
        return false;
    }
    assert(p.getHabitability()==8);
    return true;
}

bool test2(){
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);
    p.setHabitability(88.8);
    Planet p2= Planet("HAT-P-3 b", "HAT-P-3", "Transit",
                      2007, "HATNet", 10.211, 189.109, 1170,0);
    p2.setHabitability(99.9);

    if(p>p2){
        cout << "test 2 failed, Planet p {" << p << "} should be counted as smaller" << endl;
        return false;
    }
    assert(p<p2);
    return true;
}

bool test3(){
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);
    p.setHabitability(88.8);
    Planet p2= Planet("HAT-P-3 b", "HAT-P-3", "Transit",
                      2007, "HATNet", 10.211, 189.109, 1170,0);
    p2.setHabitability(88.8);

    if(p!=p2){
        cout << "test 3 failed, Planet p {" << p << "} should have same habitability" << endl;
        return false;
    }
    assert(p==p2);
    return true;
}

bool test4(){
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);
    p.setHabitability(-1);
    Planet p2= Planet("HAT-P-3 b", "HAT-P-3", "Transit",
                      2007, "HATNet", 10.211, 189.109, 1170,0);
    p2.setHabitability(1);

    if(p>p2){
        cout << "test 4 failed, Planet p {" << p << "} should be counted as smaller because it is negative" << endl;
        return false;
    }
    assert(p<p2);
    return true;
}

bool test5(){
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);
    p.setHabitability(-1);
    Planet p2= Planet("HAT-P-3 b", "HAT-P-3", "Transit",
                      2007, "HATNet", 10.211, 189.109, 1170,0);
    p2.setHabitability(1);

    if(p>p2){
        cout << "test 5 failed, Planet p {" << p << "} should be counted as smaller because it is negative" << endl;
        return false;
    }
    assert(p<p2);
    return true;
}
bool test6(){
    Planet p = Planet("K2-34 b", "K2-34", "Transit",
                      2016, "K2", 15.132, 559.381, 1742,0);

    if (p.getName()!=("K2-34 b")){
        cout<< "test 6 failed: format doesn't match the one specified" << endl;
        return false;
    }
    assert(p.getName()==("K2-34 b"));
    return true;
}

bool testPlanet(){
    bool passed = false;

    passed &= test1();
    passed &= test2();
    passed &= test3();
    passed &= test4();
    passed &= test5();
    passed &= test6();

    return passed;
}
