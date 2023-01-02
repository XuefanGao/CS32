#ifndef RADIXTREE_H
#define RADIXTREE_H

#include <string>
template<typename  ValueType>
class RadixTree {
public:
    //constructor & destructor
    RadixTree() { root = nullptr; }

    ~RadixTree() { removeAll(root); }

    // update the Radix Tree to associate the specified key string with a copy of the passed - in value
    // Inserting the same item twice should simply replace value
    //
    void insert(std::string key, const ValueType& value) {
        //char* c_arr = key.To
        //empty tree
        if (root == nullptr) {
            root = new Node();
            constructString(root, 0, key, value);
        }
        else {
            findBranch(root, 0, key, value);
        }
    }

    ValueType* search(std::string key) const {
        if (root == nullptr) {
            return nullptr;
        }
        return searchHelper(root, key, 0);
    }

    //test code  delete here
    //Node* GetRoot() const { return root; }

private:
    struct Node {
        Node() {
            endOfString = true;
            word = "";
            val = nullptr;
            for (int i = 0; i < 128; i++)
                edges[i] = nullptr;
        }
        bool endOfString;
        std::string word;
        ValueType* val;
        Node* edges[128];
    };
    void constructString(Node* curr, int index, const std::string str, const ValueType& value) {
        if (index >= str.length()) {
            curr->endOfString = true;
            curr->word = str;
            ValueType m_val = value;
            curr->val = const_cast<ValueType*>(&m_val);
            return;
        }
        else {
            curr->endOfString = false;
            Node* next = new Node();
            curr->edges[static_cast<int>(str[index])] = next;
            constructString(next, index + 1, str, value);
        }
    }
    void findBranch(Node* curr, int index, const std::string str, const ValueType& value) {
        if (curr->edges[static_cast<int>(str[index])] == nullptr) {
            constructString(curr, index, str, value);
            return;
        }
        findBranch(curr->edges[static_cast<int>(str[index])], index + 1, str, value);
    }
    ValueType* searchHelper(Node* cur, std::string key, int index) const {
        //std::cout << key[index] << std::endl;
        if (index >= key.length() && cur->endOfString == true) {
            return const_cast<ValueType*>(cur->val);
        }
        else if (cur->edges[static_cast<int>(key[index])] != nullptr) {
            return searchHelper(cur->edges[static_cast<int>(key[index])], key, index + 1);
        }
        else
            return nullptr;
    }
    void removeAll(Node* curr) {
        for (int i = 0; i < 128; i++) {
            if (curr->edges[i] != nullptr) {
                removeAll(curr->edges[i]);
            }
        }
        delete curr;
        return;
    }
    Node* root;
};

#endif