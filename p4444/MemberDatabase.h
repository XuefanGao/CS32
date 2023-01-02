#ifndef MEMBERDATABASE_H
#define MEMBERDATABASE_H
// holds at least 100k personal profiles
// search for members that have particular pair
#include <string>
#include <vector>
#include "PersonProfile.h"
#include <set>
class MemberDatabase {
public:
	MemberDatabase();
	~MemberDatabase();
	bool LoadDatabase(std::string filename);
	std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
	const PersonProfile* GetMemberByEmail(std::string email) const;
private:
	// map AttValPairString to vector of email
	RadixTree<std::vector<std::string>>* m_emailTree;

	// map email to PersonProfile obj
	RadixTree<PersonProfile*>* m_profileTree;

};

#endif