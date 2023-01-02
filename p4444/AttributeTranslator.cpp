#include "AttributeTranslator.h"
#include "RadixTree.h"
#include <iostream>
#include <fstream>

AttributeTranslator::AttributeTranslator() {
    m_translatorTree = new RadixTree<std::vector<AttValPair>>;
}

AttributeTranslator::~AttributeTranslator() {
    
}

bool AttributeTranslator::Load(std::string filename) {
    // open and read file
    std::ifstream infile;
    infile.open(filename);
    if (!infile) {
        return false;  
    }

    std::string line;
	while (getline(infile, line)) {
        std::vector<std::string> result = split(line, ',');
        std::string sourcePairString = result[0] + result[1];
        // there might be duplicates in compatible pairs
        std::vector<AttValPair> compatiblePairVec = *(m_translatorTree->search(sourcePairString));
        compatiblePairVec.push_back(AttValPair(result[2], result[3]));
        m_translatorTree->insert(sourcePairString, compatiblePairVec);
	}

    infile.close();
	return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    std::string sourcePairString = AttValString(source);
    std::vector<AttValPair> result = *(m_translatorTree->search(sourcePairString));
    // remove duplicate
    // removeDuplicate(result);
    return result;
}
