#include "CarMap.h"
#include <iostream>

// Create an empty car map.
CarMap::CarMap() 
:m_map() 
{
	
}

// If a car with the given license plate is not currently in the map, 
// and there is room in the map, add an entry for that car recording
// that it has been driven 0 miles, and return true.  Otherwise,
// make no change to the map and return false.
bool CarMap::addCar(std::string license) {
	if (!m_map.contains(license) && m_map.size() < DEFAULT_MAX_ITEMS) {
		m_map.insert(license, 0);
		return true;
	}
	return false;
}

// If a car with the given license plate is in the map, return how
// many miles it has been driven; otherwise, return -1.
double CarMap::miles(std::string license) const {
	if (m_map.contains(license)) {
		double v;
		m_map.get(license, v);
		return v;
	}
	return -1;
}

// If no car with the given license plate is in the map or if
// distance is negative, make no change to the map and return
// false.  Otherwise, increase by the distance parameter the number
// of miles the indicated car has been driven and return true.
bool CarMap::drive(std::string license, double distance) {
	if(!m_map.contains(license) || miles(license) < 0)
		return false;
	m_map.update(license, distance + miles(license));
	return true;
}

// Return the number of cars in the CarMap.
int CarMap::fleetSize() const {
	return m_map.size();
}

// Write to cout one line for every car in the map.  Each line
// consists of the car's license plate, followed by one space,
// followed by the number of miles that car has been driven.  Write
// no other text.  The lines need not be in any particular order.
void CarMap::print() const {
	std::string k;
	double v;
	for (int i = 0; i < fleetSize(); i++) {
		m_map.get(i, k, v);
		std::cout << k << " " << v << std::endl;
	}
}
