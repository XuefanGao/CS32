#include "MatchMaker.h"
#include "provided.h"
#include "utility.h"
#include <cassert>
#include <set>
#include <map>
#include <unordered_set>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {
	m_mdb = mdb;
	m_at = at;
}


MatchMaker::~MatchMaker() {

}
	
std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const {
	
	PersonProfile srcPP = *m_mdb.GetMemberByEmail(email);
	
	// vector of pairs in source PP
	int srcNumPairs = srcPP.GetNumAttValPairs();
	std::vector<AttValPair> srcPairsVec;
	AttValPair temp = AttValPair();
	for (int i = 0; i < srcNumPairs; i++) {
		if(srcPP.GetAttVal(i, temp))
			srcPairsVec[i] = temp;
	}

	// unordered_set of compatible pairs
	std::unordered_set<std::string> compPairsSet;
	for (int i = 0; i < srcNumPairs; i++) { // for each pair in srcPP
		// vector of compatible pairs in ith pair in source PP
		vector<AttValPair> tempVec = m_at.FindCompatibleAttValPairs(srcPairsVec[i]);
		// insert each AttValPair into the string unordered_set
		for (int j = 0; j < tempVec.size(); j++) {
			std::string sb = AttValString(tempVec[j]);
			compPairsSet.insert(sb);
		}
	}

	// find members with compatible pairs and count # compatible pairs
	// vector of emails of all matching member 
	std::vector<std::string> compEmailVec;
	for (unordered_set<std::string>::iterator it = compPairsSet.begin(); 
		it != compPairsSet.end(); it++) { // for each pair in compatible set
		// convert AttValString back to AttValPair 
		// vector of email of matching member for ith compatible pair
		std::vector<std::string> tempVec = m_mdb.FindMatchingMembers(strToPair(*it));
		merge(compEmailVec.begin(), compEmailVec.end(), tempVec.begin(), tempVec.end(), compEmailVec.begin());
	}

	// convert email vector to EmailCount container map     ====can also use RadixTree
	// map email string to EmailCount
	// (define < operator for EmailCount)
	std::map<std::string, EmailCount> ECMap;
	for (int i = 0; i < compEmailVec.size(); i++) {
		std::string compEmailStr = compEmailVec[i];
		std::map<std::string, EmailCount>::iterator inMap = ECMap.find(compEmailStr);
		// if email not in map, insert EmailCount to map
		if (inMap != ECMap.end()) {
			ECMap.insert(std::pair<std::string, EmailCount>(compEmailStr, EmailCount(compEmailStr, 1)));
		}

		// else, update EmailCount.count
		else {
			int incrementedCount = inMap->second.count + 1;
			inMap->second = EmailCount(compEmailStr, incrementedCount);
		}
	}
	// now we have a map of email - EmailCount, next copy value to a vector
	// vector of EmailCount, to return
	std::vector<EmailCount> ECVec;
	for (std::map<std::string, EmailCount>::iterator it = ECMap.begin(); it != ECMap.end(); it++) {
		ECVec.push_back(it->second);
	}
	return ECVec;
}