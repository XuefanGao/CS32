#ifndef RADIXTREE_H
#define RADIXTREE_H

#include <map>
// map strings to any data type
// MUST NOT add any new public member functions or variables
// char 1-127

template <typename ValueType>
class RadixTree {
public:
	// constructor & destructor
	RadixTree() {
		//m_map = new map<string, ValueType>;

	}
	~RadixTree() {

	}


	// update the Radix Tree to associate the specified key string with a copy of the passed in value
	// Inserting the same item twice should simply replace value
	// 
	void insert(std::string key, const ValueType& value) {
		//RadixTreeNode* curr = root;
		//std::string restOfKey = key;
		//// iterate untill currWord empty 
		//while (curr.startWord == true || (!restOfKey.empty())) {
		//	if (curr == nullptr)
		//		return nullptr;

		//	if (restOfKey == curr.word) {
		//		if (curr.endWord == true)
		//			return curr.val;
		//		else
		//			return nullptr;
		//	}
		//	// if curr.word and restOfKey have common prefix
		//	// key could be in tree only if entire curr.word is a prefix of restOfKey
		//	// if curr.word and restOfKey has no common part, return nullptr
		//	int prefix = isPrefix(curr.word, restOfKey);
		//	if (isPrefix == curr.word.length() && isPrefix < restOfKey.length()) {

		//		//take away the common part, go to next node
		//		restOfKey = restOfKey.substr(prefix);
		//		// go to rest of key 
		//		int first = restOfKey[0];
		//		curr = curr.edges[first];
		//	}

		//	else {
		//		return false;
		//	}
		//}


		m_map[key] = value;
	}

	//  return nullptr if not found
	// template <typename ValueType>
	ValueType* search(std::string key) const {
		//RadixTreeNode* curr = root;
		//// int firstLetter = key[0] - 'a';
		//std::string restOfKey = key;
		//// iterate untill currWord empty
		//while (curr.startWord == true || (!restOfKey.empty())){
		//	if (curr == nullptr)
		//		return nullptr;
		//	
		//	if (restOfKey == curr.word){
		//		if (curr.endWord == true)
		//			return curr.val;
		//		else
		//			return nullptr;
		//	}
		//	// if curr.word and restOfKey have common prefix
		//	// key could be in tree only if entire curr.word is a prefix of restOfKey
		//	// if curr.word and restOfKey has no common part, return nullptr
		//	int prefix = isPrefix(curr.word, restOfKey);
		//	if (isPrefix == curr.word.length() && isPrefix < restOfKey.length()) {
		//		
		//		//take away the common part, go to next node
		//		restOfKey = restOfKey.substr(prefix);
		//		// go to rest of key 
		//		int first = restOfKey[0];
		//		curr = curr.edges[first];
		//	}
		//	
		//	else {
		//		return false;
		//	}
		//}

		ValueType v = (m_map.find(key)->second);
		return &v;
	}



private:
	//struct RadixTreeNode {
	//	std::string word;
	//	bool endWord;  // initialized to false
	//	bool startWord;  // initialized to true
	//	RadixTreeNode* edges[127];
	//	valueType* val;

	//	RadixTreeNode() {
	//		word = "";
	//		endWord = false;
	//		startWord = false;
	//		
	//		// for (int i = 0; i < 127; i++) 
	//			// edges[i] = nullptr;
	//	}
	//};

	//RadixTreeNode* root;

	std::map<std::string, ValueType> m_map;

	// returns the index just pass the common prefix (where ai != bi)
	// returns zero if they have different prefix
	// this is also length of prefix
	int isPrefix(std::string a, std::string b) {
		if (a == b) {
			return a.length();
		}
		int alength = a.length();
		int blength = b.length();
		int i = 0;
		for (i = 0; i < alength && i < blength; i++) {
			if (a[i] != b[i]) {
				return i;
			}
		}
		// if we reach end of a or b, return min(alength, blength)
		return i;
	}
};

#endif