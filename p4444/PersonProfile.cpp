#include "PersonProfile.h"
#include "utility.h"

PersonProfile::PersonProfile(const std::string name, const std::string email) {
	m_name = name;
	m_email = email;
	m_treeSize = 0;
	m_pairTree = new RadixTree<AttValPair>;
}

PersonProfile::~PersonProfile() {
	// destruct radix tree
}

std::string PersonProfile::GetName() const {
	return m_name;
}

std::string PersonProfile::GetEmail() const {
	return m_email;
}

// since we search pairs by value, key-value correponds to value-AttValPair
void PersonProfile::AddAttValPair(const AttValPair& attval) {
	// do nothing if value duplicates
	std::string pairString = AttValString(attval);
	if (m_pairTree->search(pairString) != nullptr)
		return;
	m_pairTree->insert(pairString, attval);
	m_treeSize += 1;
}

int PersonProfile::GetNumAttValPairs() const {
	return m_treeSize;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	// implement a function in utility to traverse a radix tree
	// while loop, traverse the tree, decrement num every time we see end of string node
	if (0 < attribute_num || attribute_num >= m_treeSize)
		return false;
	
	// traverse num steps
	AttValPair* curr = nullptr; // m_pairTree.root->value  (AttValPair) 
	while (attribute_num > 0) {
		// curr = pairTree traverse 1 step 
		attribute_num--;
	}

	// if accessible, return
	if (curr != nullptr) {
		attval = *curr;
		return true;
	}
}