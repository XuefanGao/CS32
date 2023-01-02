#include "Map.h"

Map::Map() {
	head = NULL;
	tail = NULL;
	length = 0;
}

// destructor
Map::~Map() {
	if (length != 0) {
		Node* current = head;
		while (current->next != NULL) {
			Node* n = current->next;
			delete current;
			current = n;
		}
		delete current;
	}
	
}


// copy constructor
Map::Map(const Map& old) {
	Node* p = old.head;
	while (p != NULL) {
		insert(p->key, p->value);
		p = p->next;
	}
}


// assignment operator
Map& Map::operator=(const Map &src) {
	if (this == &src) 
		return *this;
	if (length != 0) {
		Node* current = head;
		while (current->next != NULL) {
			Node* n = current->next;
			delete current;
			current = n;
		}
		delete current;
	}

	Node* p = src.head;
	while (p != NULL) {
		insert(p->key, p->value);
		p = p->next;
	}

}


bool Map::empty() const {
	if (length == 0) {
		return true;
	}
	return false;
}


int Map::size() const {
	return length;
}

// If key is not equal to any key currently in the map, insert and return true.
// Otherwise, make no change to the map and return false (indicating
// that the key is already in the map).
// Insert to sorted linked list (ascending order).
bool Map::insert(const KeyType& key, const ValueType& value) {
	// if key in map, insert
	if (contains(key) == false) {   
		Node* p = new Node;
		p->key = key;
		p->value = value;
		length = length + 1;

		// If map is empty
		if (length == 1) {
			head = p;
			tail = p;
			p->prev = NULL;
			p->next = NULL;
			return true;
		}

		else {
			Node* cursor = head;
			//insert at heat
			if (cursor->key > key) {
				p->prev = NULL;
				p->next = head;
				cursor->prev = p;
				head = p;
				return true;
			}
			// insert in the middle
			while (cursor != NULL) {
				if (cursor->key > key) {   // stop iterating and insert before cursor
					p->prev = cursor->prev;
					p->next = cursor;
					cursor->prev->next = p;
					cursor->prev = p;
					return true;
				}
				cursor = cursor->next;
			}
			// insert as tail
			tail->next = p;
			p->prev = tail;
			p->next = NULL;
			tail = p;
			return true;
		}
	}
	return false;
}


// If key is equal to a key currently in the map, then make that key instead map to
// the value of the second parameter; return true in this case.
// Otherwise, make no change to the map and return false.
bool Map::update(const KeyType& key, const ValueType& value) {
	// if key in map
	if (contains(key) == true) {
		Node* cursor = head;
		// find the node contains key and update its value
		while (cursor != NULL) {
			if (cursor->key == key) {
				cursor->value = value;
			}
			cursor = cursor->next;
		}
		return true;
	}
	return false;
}


// If key is equal to a key currently in the map, then make that key map to
// the value of the second parameter; return true in this case.
// If key is not equal to any key currently in the map and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that the key is not already in the map and the map has a fixed
// capacity and is full).
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
	if (contains(key)) {
		update(key, value);
		return true;
	}
	else {
		insert(key, value);
		return true;
	}
	return false;
}


// If key is equal to a key currently in the map, remove the key/value
// pair with that key from the map and return true.  Otherwise, make
// no change to the map and return false.
bool Map::erase(const KeyType& key) {
	if (contains(key)) {
		// erase
		// cases: head middle tail
		length = length - 1;
		Node* cursor = head;
		// if map has only one node, 
		if (length == 0) {
			head = NULL;
			tail = NULL;
			delete cursor;
			return true;
		}
		//if map has more than one node
		for (int i = 0; i <= length; i++) {
			if (cursor->key == key) {
				// case of removing head
				if (i == 0) {
					cursor->next->prev = NULL;
					head = cursor->next;
				}
				// case of removong tail
				else if (i == length) {
					cursor->prev->next = NULL;
					tail = cursor->prev;
				}
				// removing middle
				else {
					cursor->next->prev = cursor->prev;
					cursor->prev->next = cursor->next;
				}
				delete cursor;
				return true;
			}
			cursor = cursor->next;
		}
	}
	else {
		return false;
	}
}


// Return true if key is equal to a key currently in the map, otherwise
// false.
bool Map::contains(const KeyType& key) const {
	Node* p = head;
	while (p != NULL) {
		if (p->key == key) {
			return true;
		}
		p = p->next;
	}
	return false;
}


// If key is equal to a key currently in the map, set value to the
// value in the map which that key maps to, and return true.  Otherwise,
// make no change to the value parameter of this function and return
// false.
bool Map::get(const KeyType& key, ValueType& value) const {
	Node* cursor = head;
	while (cursor != NULL) {
		if (cursor->key == key) {
			value = cursor->value;
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}


// If 0 <= i < size(), copy into the key and value parameters the
// key and value of the key/value pair in the map whose key is strictly
// greater than exactly i keys in the map and return true.  Otherwise,
// leave the key and value parameters unchanged and return false.
bool Map::get(int i, KeyType& key, ValueType& value) const {
	if (0 <= i && i < length) {
		Node* cursor = head;
		for (int j = 0; j < i; j++) {
			cursor = cursor->next;
		}
		key = cursor->key;
		value = cursor->value;
		return true;
	}
	return false;
}


// Exchange the contents of this map with the other one.
void Map::swap(Map& other) {
	Node* oh = other.head;
	Node* ot = other.tail;
	int ol = other.length;
	other.head = head;
	other.tail = tail;
	other.length = length;
	head = oh;
	tail = ot;
	length = ol;
}

// rsult 
// If key in exactly one of m1 and m2, then result must contain its pair.
// If key in both m1 and m2, with the same value, then result must contain exactly one pair.
// If key in both m1 and m2, but with different value, return false. 
// If there is no key like this, return true. 
// order is irrelevant
bool merge(const Map& m1, const Map& m2, Map& result) {
	bool resultbool = true;
	// empty result
	while (result.size() != 0) {
		KeyType k;
		ValueType v;
		result.get(0, k, v);
		result.erase(k);
	}
	// iterate through m1, check if each key is in m2
	for (int i = 0; i < m1.size(); i++) {
		KeyType k;
		ValueType v, v2;
		m1.get(i, k, v);
		// if key in both maps
		if (m2.contains(k)) {
			m2.get(k, v2);
			// if key maps to same value, add one pair to result
			if (v == v2) {
				result.insert(k, v);
			}
			// if key maps to different value, do nothing and return false
			else {
				resultbool = false;
			}
		}

		// if key only in m1, add pair to result
		else {
			result.insert(k, v);
		}
	}

	// iterate through m2, check if each key is in m2
	for (int i = 0; i < m2.size(); i++) {
		KeyType k;
		ValueType v, v2;
		m2.get(i, k, v);
		// if key only in m2, add pair to result
		if (m1.contains(k) == false) {
			result.insert(k, v);
		}
		// if key in both maps, dp nothing 
	}
	return resultbool;
}



// result must contain:
// for each pair p1 in m, a pair with p1's key mapping to a value copied from a different pair p2 in m,
// and no other pair in result has its value copied from p2. 
// However, if m has only one pair, then result must contain simply a copy of that pair.
// Upon return, result must contain the same number of pairs as m; 
void reassign(const Map& m, Map& result) {
	// empty result
	while (result.size() != 0) {
		KeyType k;
		ValueType v;
		result.get(0, k, v);
		result.erase(k);
	}
	result = m;
	// if m has only one pair, return 
	if (m.size() == 1)
		return;

	// for m that contains multiple pairs
	// since m and result are both sorted
	// shift values s.t. result.v1 = m.v2, result.v2 = m.v3, ..., result.tail = m.head
	for (int i = 0; i < m.size()-1; i++) {
		KeyType k, mk;
		ValueType v, mv;
		result.get(i, k, v);
		m.get(i + 1, mk, mv);
		result.update(k, mv);
	}
	KeyType k, mk;
	ValueType v, mv;
	result.get(result.size() - 1, k, v);
	m.get(0, mk, mv);
	result.update(k, mv);
}

