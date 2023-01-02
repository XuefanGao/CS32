
//The eraseThrees member function removes the 3rd, 6th, 9th, 12th, 15th, etc., nodes from the listand deletes them.For example, if the values in the StringList x were 't'  'r'  'e'  'a'  'c'  'h'  'e'  'r'  'y', then after the call x.eraseThrees(), x would contain 't'  'r'  'a'  'c'  'e'  'r'.Of course, if x has fewer than three nodes, the call would do nothing.

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class StringList
{
public:
    StringList(string text);
    // You may declare other member functions for your test code to call
    void eraseThrees();
private:
    struct Node
    {
        char  value;
        Node* next;
        Node(char v, Node* n) : value(v), next(n) {}
    };
    Node* head;  // points to first Node in the list
};

StringList::StringList(string text)
{
    //  For example, StringList s("heap"); creates s containing
    //  a list with values  'h'  'e'  'a'  'p'
    head = nullptr;
    for (int k = text.size(); k > 0; k--)
        head = new Node(text[k - 1], head);
}



// You may implement other member functions here for test purposes,
// but you will not turn them in as part of your submission.

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AFTER THE END OF THE eraseThrees IMPLEMENTATION

//Your implementation of eraseThrees goes hereand is the only code
//you will submit
void StringList::eraseThrees() {
    int counter = 0;
    Node* p = head;
    while (p != nullptr && p->next != nullptr) {
        counter = counter + 1;
        if (counter % 3  == 2) {
            //remove p->next
            Node* toDelete = p->next;
            p->next = toDelete->next;
            delete toDelete;
        }
        else
            p = p->next;
    }
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT BEFORE THE START OF THE eraseThrees IMPLEMENTATION

int main()
{
    StringList x("1131141151161175");
    x.eraseThrees();
    // You might put some code here for test purposes, e.g., to verify
    // that x now contains  't'  'r'  'a'  'c'  'e'  'r'
    // You might run some other tests.
    cout << "Program finished" << endl;
}





#include <iostream>
#include <cassert>
using namespace std;

class Weight
{
public:
    Weight(int w) : m_w(w) {}
    int getw() const { return m_w; }
private:
    int m_w;
};

class Pod
{
public:
    Pod(int p);
    ~Pod();
    Pod(const Pod& other);
private:
    Weight* m_wt;
    int m_ppp;
    int* m_peas;
};

Pod::Pod(int p)
{
    m_wt = new Weight(p);   // dynamically allocated
    m_ppp = 3 * p;          // not
    m_peas = &m_ppp;        // not
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AFTER THE END OF THE DESTRUCTOR AND COPY CONSTRUCTOR
// IMPLEMENTATIONS

Pod::~Pod() {
    delete m_wt;
}

Pod::Pod(const Pod& other) {
    m_wt = new Weight(other.m_wt->getw());   
    m_ppp = other.m_ppp;          
    m_peas = &m_ppp;        
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT BEFORE THE START OF THE DESTRUCTOR AND COPY CONSTRUCTOR
// IMPLEMENTATIONS

void test()
{
    Pod p1(2);
    Pod p2(p1);
}

int main()
{
    test();
    cout << "All tests succeeded" << endl;
}