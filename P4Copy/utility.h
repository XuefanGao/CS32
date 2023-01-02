#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>
#include <vector>
#include "provided.h"
#include <algorithm>
using namespace std;

//class Utility {

	// split string s based on deliminator del, returns a string vector
	vector<string> split(string str, char del);

	// take AttValPair as parameter, return a string = att+val.
	std::string AttValString(AttValPair p);

	// remove duplicate elements in a vector of string type
	void removeDuplicate(vector<std::string>& v);

	// returns true if the first argument goes before the second argument
	// in the strict weak ordering it defines, and false otherwise.
	// > operator for AttValPairs
	// used to construct set<AttValPair>


	// convert AttValString back to AttValPair
	AttValPair strToPair(std::string s);
//};


#endif