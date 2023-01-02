#ifndef Map_h
#define Map_h

#include <string>

using KeyType = std::string;
using ValueType = double;

//using KeyType = int;
//using ValueType = std::string;;
class Map
{
public:
    // ---------------------------------------------------------------
    // constructor, destructor, copy constructor, assignmentoperators
    Map();
    ~Map();
    Map(const Map& old);
    Map& operator=(const Map& src);

    // ---------------------------------------------------------------
    // member functions
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
    struct Node {
    public:
        KeyType key;
        ValueType value;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length;   
};


// non member functions
bool merge(const Map& m1, const Map& m2, Map& result);
void reassign(const Map& m, Map& result);

#endif
