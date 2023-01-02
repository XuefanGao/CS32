#ifndef RADIXTRE_H
#define RADIXTRE_H

#include <map>
// map strings to any data type
// MUST NOT add any new public member functions or variables
// char 1-127

template <typename ValueType>
class RadixTree {
public:
	// constructor & destructor
	RadixTree() {
		// m_map = new map<std::string, ValueType>;
		root = new RadixTreeNode("", true, false);

	}
	~RadixTree() {
		if (root == nullptr)
			return;
			
		RadixTreeNode* curr = root;
	}


	// update the Radix Tree to associate the specified key string with a copy of the passed in value
	// Inserting the same item twice should simply replace value
	// 
	void insert(std::string key, const ValueType& value) {
		RadixTreeNode* curr = root;
		std::string restOfKey = key;
		// iterate untill restOfKey empty 
		while (curr.startWord == true || (!restOfKey.empty())) {
			if (curr == nullptr)  // this won't happen bc we start at dummy root every time
				return nullptr; // insert?

			if()

			if (restOfKey == curr.word) {
				if (curr.endWord == true) {
					// already exist in map, replave value
					curr.val = value;
				}
					
				else {
					curr.endWord = true; 
					curr.val = value
				}
			}
			else { // restOfKey is not identical with curr.word, check duplicate portion
				int prefix = isPrefix(curr.word, restOfKey);
				// if no common char at all (this only happens )
				if (prefix < 0) {

				}
			}
			// if curr.word and restOfKey have common prefix
			// key could be in tree only if entire curr.word is a prefix of restOfKey
			// if curr.word and restOfKey has no common part, return nullptr
			
			if (isPrefix == curr.word.length() && isPrefix < restOfKey.length()) {

				//take away the common part, go to next node
				restOfKey = restOfKey.substr(prefix);
				// go to rest of key 
				int first = restOfKey[0];
				curr = curr.edges[first];
			}
			else {
				return false;
			}
		}

		//=========================
		m_map[key] = value;
	}

	//  return nullptr if not found
	// template <typename ValueType>
	ValueType* search(std::string key) const {
		RadixTreeNode* curr = root;
		// int firstLetter = key[0] - 'a';
		std::string restOfKey = key;
		// iterate untill currWord empty
		while (curr.startWord == true || (!restOfKey.empty())){
			if (curr == nullptr)
				return nullptr;
			
			if (restOfKey == curr.word){
				if (curr.endWord == true)
					return curr.val;
				else
					return nullptr;
			}
			// if curr.word and restOfKey have common prefix
			// key could be in tree only if entire curr.word is a prefix of restOfKey
			// if curr.word and restOfKey has no common part, return nullptr
			int prefix = isPrefix(curr.word, restOfKey);
			if (isPrefix == curr.word.length() && isPrefix < restOfKey.length()) {
				
				//take away the common part, go to next node
				restOfKey = restOfKey.substr(prefix);
				// go to rest of key 
				int first = restOfKey[0];
				curr = curr.edges[first];
			}
			
			else {
				return false;
			}
		}

		//======================
		/*if (m_map.find(key) == m_map.end())
			return nullptr;
		ValueType v = (m_map.find(key)->second);
		return &v;*/
		/*typename std::map<std::string, ValueType>::const_iterator iter;
		     iter = m_map.find(key);
		     if (iter == m_map.end()) {
		         return nullptr;
		     }
		     return const_cast<ValueType *>(&(iter->second));*/
	}



private:
	struct RadixTreeNode {
		std::string word;
		bool endWord;  // initialized to false
		bool startWord;  // initialized to true
		RadixTreeNode* edges[127];
		typename ValueType val;
		RadixTreeNode(std::string w = "", bool start = false, bool end = false) {
			word = w;
			endWord = end;
			startWord = start;
			
			// for (int i = 0; i < 127; i++) 
				// edges[i] = nullptr;
		}
	};

	RadixTreeNode* root;

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


