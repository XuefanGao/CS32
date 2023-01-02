#include "AttributeTranslator.h"
#include <cassert>

//This is the AttributeTranslator constructor.
//It must take no arguments.
AttributeTranslator::AttributeTranslator()
{}

//A destructor for AttributeTranslator
//AttributeTranslator:: ~AttributeTranslator()
//{ }

//Loads the attribute-value translation data from the data file
bool AttributeTranslator::Load(std::string filename) {
    std::ifstream inFile;
    inFile.open(filename);

    if (!inFile) {
        std::cerr << "Unable to open " << filename << std::endl;
        return false;   // call system to stop
    }

    //Read data from file
    std::string Line;
    //int count = 0;

    while (getline(inFile, Line)) {
        //std::cout << count++ << std::endl;
        std::string line = Line;
        //std::cout << line << std::endl;
        std::vector<std::string> res = split(line, ",");
        if (res.size() != 4) {
            std::cerr << "Attribute Pair error!\n";
        }
        AttValPair* source_attval = new AttValPair(res[0], res[1]);
        AttValPair* target_attval = new AttValPair(res[2], res[3]);
        if (AttValTranslate.search(res[0] + "," + res[1]) != nullptr) {
            AttValTranslate.search(res[0] + "," + res[1])->push_back(*target_attval);
        }
        else {
            std::vector<AttValPair> val;
            val.push_back(*(target_attval));
            AttValTranslate.insert(res[0] + "," + res[1], val);
        }
    }
    inFile.close();
    return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const
{
    std::vector<AttValPair> res;
    //AttValPair * avp = AttValTranslate.search(s_avp);
    if (AttValTranslate.search(source.attribute + "," + source.value)->size() != 0) {
        //AttValPair *s_avp = *(AttValTranslate.search(s_avp)));
        std::vector<AttValPair>* ptr = AttValTranslate.search(source.attribute + "," + source.value);
        for (std::vector<AttValPair>::iterator iter = ptr->begin(); iter != ptr->end(); iter++) {
            res.push_back(*(iter));
        }

    }
    return res;
}
