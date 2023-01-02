//#include "CarMap.h"
//#include <cassert>
//using namespace std;
//
//int main() {
//
//	CarMap a;
//	assert(a.fleetSize() == 0);
//	assert(a.miles("l1") == -1);
//	assert(a.addCar("l1"));
//	assert(a.fleetSize() == 1);
//	assert(a.miles("l1") == 0);
//	assert(a.addCar("l2"));
//	assert(a.fleetSize() == 2);
//	assert(a.miles("l2") == 0);
//	assert(!a.addCar("l1"));
//	assert(a.fleetSize() == 2);
//	assert(!a.drive("l",10));
//	assert(a.drive("l1", 10));
//	assert(a.drive("l2", 0));
//	//a.print();
//	return 0;
//}