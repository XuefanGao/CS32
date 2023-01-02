#ifndef PERSONPROFILE_H
#define PERSONPROFILE_H

#include "provided.h"
#include <iostream>
#include <string>
#include "RadixTree.h"
#include "utility.h"

// MUST NOT ADD NEW PUBLIC MEMBER FUNCTIONS OR VAR
class PersonProfile {
public:
    //constructor & destructor
    PersonProfile(const std::string name, const std::string email);
    ~PersonProfile();

    // accessors and mutators
    std::string GetName() const;
    std::string GetEmail() const;

    // add pairs, doesn't allow duplicates
    // logN complexity -> radix tree 
    // AttValPair could be stored in any order
    void AddAttValPair(const AttValPair& attval);

    int GetNumAttValPairs() const;

    bool GetAttVal(int attribute_num, AttValPair& attval) const;

private:
    std::string m_name;
    std::string m_email;
    // tree of attribute value pairs sorted by values
    RadixTree<AttValPair>* m_pairTree;
    int m_treeSize;
};

#endif