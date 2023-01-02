//
//  AttributeTranslator.h
//  RadixTree
//
//  Created by Yiqu on 3/15/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <stdio.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>
#include <list>
#include "provided.h"
#include "RadixTree.h"
#include "utility.h"

class AttributeTranslator {
public:
    //This is the AttributeTranslator constructor.
    //It must take no arguments.
    AttributeTranslator();

    //A destructor for AttributeTranslator
    ~AttributeTranslator();

    //Loads the attribute-value translation data from the data file
    bool Load(std::string filename);

    //Identify all compatible attribute-value pairs and return
    //a vector containing them. I
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
    RadixTree<std::vector<AttValPair>> AttValTranslate;
};

#endif /* AttributeTranslator_h */
