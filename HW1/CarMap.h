#ifndef CarMap_h
#define CarMap_h
#include "Map.h"
#include <iostream>

class CarMap
{
public:
    CarMap();       

    bool addCar(std::string license);
    
    double miles(std::string license) const;
    
    bool drive(std::string license, double distance);
    
    int fleetSize() const;  // Return the number of cars in the CarMap.

    void print() const;
    
private:
    
    Map m_map;

}; 

#endif
