#include "utility.h"
using namespace std;


vector<string> split(string str, char del) {
    // declaring temp string to store the curr "word" up to del
    string temp = "";
    vector<string> result;

    for (int i = 0; i < (int)str.size(); i++) {

        if (str[i] != del) {
            temp += str[i];
        }
        else {
            result.push_back(temp);
            temp = "";
        }
    }

    result.push_back(temp);
    return result;
}


void removeDuplicate(vector<std::string>& v) {
    vector<std::string>::iterator ip;
    ip = std::unique(v.begin(), v.begin() + v.size());
    v.resize(std::distance(v.begin(), ip));
}

std::string AttValString(AttValPair p) {
    return p.attribute + DELIMITER + p.value;
}

AttValPair strToPair(std::string s) {
    size_t pos = s.find(DELIMITER);
    std::string att = s.substr(0, pos);
    std::string val = s.substr(pos+1, s.length() - att.length() - 1);
    return AttValPair(att, val);
}
