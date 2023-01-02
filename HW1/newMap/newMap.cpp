#include "newMap.h"
using namespace std;

// Create an empty map (i.e., one with no key/value pairs)
Map::Map() {
	capacity = DEFAULT_MAX_ITEMS;
	arr = new Node * [capacity];
	length = 0;
}


Map::Map(int cap = DEFAULT_MAX_ITEMS) {
	capacity = cap;
	arr = new Node * [cap];
	length = 0;
}

Map::~Map() {
	delete [] arr;
}

// Return true if the map is empty, otherwise false.
bool Map::empty() const {
	if (length == 0) {
		return true;
	}
	return false;
}

// Return the number of key/value pairs in the map.
int Map::size() const {
	return length;
}



// If key is not equal to any key currently in the map, and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that either the key is already in the map, or the map has a fixed
// capacity and is full).
bool Map::insert(const KeyType& key, const ValueType& value) {
	int index = find(key);

	// if key NOT in Map, add key
	if (index == -1 && length < capacity) {
		Node* p = new Node;
		p->key = key;
		p->value = value;

		arr[length] = p;
		length = length + 1;

		return true;
	}
	return false;
}



// If key is equal to a key currently in the map, then make that key no
// longer map to the value that it currently maps to, but instead map to
// the value of the second parameter; return true in this case.
// Otherwise, make no change to the map and return false.
bool Map::update(const KeyType& key, const ValueType& value) {
	int index = find(key);

	// if key in Map, update key
	if (index != -1) {
		Node* p = new Node;
		p->key = key;
		p->value = value;

		arr[index] = p;

		return true;
	}
	return false;
}




// If key is equal to a key currently in the map, then make that key no
// longer map to the value that it currently maps to, but instead map to
// the value of the second parameter; return true in this case.
// If key is not equal to any key currently in the map and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that the key is not already in the map and the map has a fixed
// capacity and is full).
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
	int index = find(key);
	//if key in Map
	if (index != -1) {
		update(key, value);
		return true;
	}
	//if ket NOT in Map
	if (index == -1 && length < capacity) {
		insert(key, value);
		return true;
	}

	return false;
}




// If key is equal to a key currently in the map, remove the key/value
// pair with that key from the map and return true.  Otherwise, make
// no change to the map and return false.
bool Map::erase(const KeyType& key) {
	int index = find(key);
	// if key in Map, remove node
	if (index != -1) {
		for (int i = index; i < length - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[length - 1] = NULL;
		length = length - 1;
		return true;
	}
	return false;
}



// Return true if key is equal to a key currently in the map, otherwise
// false.
bool Map::contains(const KeyType& key) const {
	if (find(key) != -1) {
		return true;
	}
	return false;
}


// If key is equal to a key currently in the map, set value to the
// value in the map which that key maps to, and return true.  Otherwise,
// make no change to the value parameter of this function and return
// false.
bool Map::get(const KeyType& key, ValueType& value) const {
	int index = find(key);
	if (index != -1) {
		value = arr[index]->value;
		return true;
	}
	return false;
}



// If 0 <= i < size(), copy into the key and value parameters the
// key and value of the key/value pair in the map whose key is strictly
// greater than exactly i keys in the map and return true.  Otherwise,
// leave the key and value parameters unchanged and return false.
bool Map::get(int i, KeyType& key, ValueType& value) const {
	if (0 <= i && i < length) {
		key = getKey(i);
		int index = find(key);
		if (index != -1) {
			value = arr[index]->value;
		}
		return true;
	}
	return false;
}



// Exchange the contents of this map with the other one.
void Map::swap(Map& other) {
	//shallow copy
	int temp_capacity = capacity;
	int temp_length = length;
	length = other.length;
	capacity = other.capacity;
	other.length = temp_length;
	other.capacity = temp_capacity;

	//arr = tempArr
	Node** tempArr = new Node * [capacity];
	for (int i = 0; i < capacity; i++) {
		tempArr[i] = arr[i];
	}
	//arr = other.arr;
	//Node** newArr = new Node * [other.capacity];
	for (int i = 0; i < other.capacity; i++) {
		arr[i] = other.arr[i];
	}

	//other.arr = tempArr;
	//Node** otherArr = new Node * [capacity];
	for (int i = 0; i < capacity; i++) {
		other.arr[i] = tempArr[i];
	}
	delete[] tempArr;
}


//if key existsin Map, return the index of the node, else, return -1
int Map::find(KeyType key) const {
	for (int i = 0; i < length; i++) {
		if (arr[i]->key == key)
			return i;
	}
	return -1;
}


//void Map::print() {
//	for (int i = 0; i < length; i++) {
//		cout << arr[i]->key << "     " << arr[i]->value << endl;
//	}
//}


KeyType Map::getKey(int pos) const {
	KeyType* KeyArr = new KeyType[length];
	for (int k = 0; k < length; k++) {
		KeyArr[k] = arr[k]->key;
	}
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (KeyArr[j] > KeyArr[j + 1]) {
				KeyType temp = KeyArr[j];
				KeyArr[j] = KeyArr[j + 1];
				KeyArr[j + 1] = temp;
			}
		}
	}
	return KeyArr[pos];
}

Map::Map(const Map& old) {
	capacity = old.capacity;
	length = old.length;
	arr = new Node * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = old.arr[i];
	}

}


Map& Map::operator=(const Map& src) {
	if (&src == this)
		return *this;
	delete[] arr;
	capacity = src.capacity;
	length = src.length;
	arr = new Node* [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = src.arr[i];
	}
	return *this;
}