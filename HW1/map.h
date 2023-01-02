#ifndef Map_h
#define Map_h
#include <string>


using KeyType = std::string;
using ValueType = double;
//using KeyType = int;
//using ValueType = std::string;
const int DEFAULT_MAX_ITEMS = 260;



class Map
{
public:
    Map();         

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

private:
    typedef struct Node {
        KeyType key;
        ValueType value;
    } Node;

    int capacity;
    int length;   //actual number of nodes 
    Node arr[DEFAULT_MAX_ITEMS];

    // helper functions
    int find(KeyType key) const;
    KeyType getKey(int pos) const; //return the key whihc is greater than pos keys
    
};

#endif