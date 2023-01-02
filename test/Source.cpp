#include <string>
#include <iostream>     // std::cout
#include <algorithm>    // std::mismatch
using namespace std;
//bool isPrefix(std::string prefix, std::string word) {
//	if (prefix.length() == 0)
//		return false;
//	return std::mismatch(prefix.begin(), prefix.end(), word.begin(), word.end()).first == prefix.end();
//}


int isPrefix(std::string a, std::string b) {
	if (a == b) {
		return a.length();
	}
	int alength = a.length();
	int blength = b.length();
	int i = 0;
	for (i = 0; i < alength && i < blength; i++) {
		if (a[i] != b[i]) {
			return i;
		}
	}
	// if we reach end of a or b, return min(alength, blength)
	return i;
}

void strToPair(std::string s) {
	size_t pos = s.find("`");
	std::string att = s.substr(0, pos);
	std::string val = s.substr(pos+1, s.length() - att.length() - 1);
	cout << att << endl << val;
}

int main() {
	strToPair("123`4666");
	return 0;
}