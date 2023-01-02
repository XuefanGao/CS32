#ifndef ATTRIBUTETRANSLATOR_H
#define ATTRIBUTETRANSLATOR_H


#include "provided.h"
#include <iostream>
#include <string>
#include "RadixTree.h"
#include "utility.h"

// translate input attributes to set of attributes 
// MUST NOT ADD NEW PUBLIC MEMBER FUNCTIONS OR VARIABLES

class AttributeTranslator {
public:
	//constructor & destructor
	AttributeTranslator();
	~AttributeTranslator();

	bool Load(std::string filename);

	std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
	RadixTree<std::vector<AttValPair>>* m_translatorTree;

};

#endif