#include "MemberDatabase.h"
#include "utility.h"
#include <iostream>
#include <fstream>

MemberDatabase::MemberDatabase() {
    m_emailTree = new RadixTree<std::vector<std::string>>;
    m_profileTree = new RadixTree<PersonProfile*>;
}
MemberDatabase::~MemberDatabase() {
    
}
bool MemberDatabase::LoadDatabase(std::string filename) {
    // open and read file
    std::ifstream infile;
    infile.open(filename);
    if (!infile) {
        return false;
    }

    std::string line;
    while (!infile.eof()) { // read to end of file

        std::string name, email, c, pairString, emptyLine;
        int count;
        std::vector<AttValPair> pairVec;

        getline(infile, name);
        getline(infile, email);
        // if email duplicate, return false
//        if (m_profileTree->search(email) != nullptr)
//            return false;
        getline(infile, c);
        count = std::stoi(c);
        
        // construct PersonProfile
        PersonProfile* pp = new PersonProfile(name, email);

        for (int i = 0; i < count; i++) {
            getline(infile, pairString);
            std::vector<std::string> result = split(pairString, ',');
            pairString = result[0] + "`" + result[1]; 
            // insert email to emailTree's pair node
            std::vector<std::string> temp;
            if (m_emailTree->search(pairString) != nullptr)
                temp = *m_emailTree->search(pairString);
            temp.push_back(email);
            m_emailTree->insert(pairString, temp);
            // insert to PersonProfile's pairTree
            pp->AddAttValPair(AttValPair(result[0], result[1]));
        }
        m_profileTree->insert(email, pp);
        getline(infile, emptyLine);
    }

    infile.close();
    return true;
}
std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    std::string sourcePairString = AttValString(input);
    std::vector<std::string> result = *(m_emailTree->search(sourcePairString));
    removeDuplicate(result);
    return result;
}
const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const {
    return *m_profileTree->search(email);
}

//  MemberDatabase::