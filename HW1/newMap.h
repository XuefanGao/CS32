#ifndef Map_h
#define Map_h
#include <string>
#include <iostream>
const int DEFAULT_MAX_ITEMS = 260;
using KeyType = std::string;
using ValueType = double;

typedef struct Node {
    KeyType key;
    ValueType value;
} Node;

class Map
{
public:
    Map();

    Map(int capacity);

    bool empty() const;

    int size() const;

    bool insert(const KeyType& key, const ValueType& value);

    bool update(const KeyType& key, const ValueType& value);

    bool insertOrUpdate(const KeyType& key, const ValueType& value);

    bool erase(const KeyType& key);

    bool contains(const KeyType& key) const;

    bool get(const KeyType& key, ValueType& value) const;

    bool get(int i, KeyType& key, ValueType& value) const;

    void swap(Map& other);

    ~Map();

    void print(); /////////////////////////////////////////////delete
private:
    int capacity;
    int length;   //actual number of nodes 
//change
    Node** arr;
    // helper functions
    int find(KeyType key) const;
    KeyType getKey(int pos) const; //return the key whihc is greater than pos keys
    void printArr(KeyType* arr);
    void swapKey(KeyType* x, KeyType* y);
};

#endif
