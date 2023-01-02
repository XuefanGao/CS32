#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Class
{
public:
    Class(string nm) : m_name(nm) {}
    string name() const { return m_name; }
    const vector<Class*>& subclasses() const { return m_subclasses; }
    void add(Class* d) { m_subclasses.push_back(d); }
    ~Class();
private:
    string m_name;
    vector<Class*> m_subclasses;
};

Class::~Class()
{
    for (size_t k = 0; k < m_subclasses.size(); k++)
        delete m_subclasses[k];
}

void listAll(string path, const Class* c)  // two-parameter overload
{
    //You will write this code.
    if (path == "")
        path += c->name();
    for (int i = 0; i < c->subclasses().size(); i++) {
        // print all subclasses from front to back
        //vector<Class>::iterator it = c.subclasses().begin();
        // if there is a class that has subclass
        Class* a = c->subclasses()[i];
        cout << path + " => " + a->name() << endl;
        if (a->subclasses().size() > 0)
            listAll(path + " => " + a->name(), a);
    }
}

void listAll(string path, const Class* c)  // two-parameter overload
{
    //You will write this code.
    if (path == "")
        path += c->name();
    for (int i = 0; i < c->subclasses().size(); i++) {
        // print all subclasses from front to back
        //vector<Class>::iterator it = c.subclasses().begin();
        // if there is a class that has subclass
        Class* a = c->subclasses()[i];
        cout << path + " => " + a->name() << endl;
        if (a->subclasses().size() > 0)
            cout << path + " => " + a->name();
            listAll(, a);
    }
}

void listAll(const Class* c)  // one-parameter overload
{
    if (c != nullptr)
        listAll("", c);
}

int main()
{
    Class* d1 = new Class("Koopa");
    listAll(d1);
    cout << "====" << endl;

    d1->add(new Class("SoopaKoopa"));
    Class* d2 = new Class("Enemy");
    d2->add(new Class("Piranha"));
    d2->add(d1);
    Class* d3 = new Class("Goodie");
    d3->add(new Class("Flower"));
    d3->add(new Class("Mushroom"));
    d3->add(new Class("Star"));
    listAll(d3);
    cout << "====" << endl;

    Class* d4 = new Class("Actor");
    d4->add(d2);
    d4->add(new Class("Peach"));
    d4->add(d3);
    listAll(d4);
    delete d4;
}

/*
Koopa
====
Goodie
Goodie = > Flower
Goodie = > Mushroom
Goodie = > Star
====
Actor
Actor = > Enemy
Actor = > Enemy = > Piranha
Actor = > Enemy = > Koopa
Actor = > Enemy = > Koopa = > SoopaKoopa
Actor = > Peach
Actor = > Goodie
Actor = > Goodie = > Flower
Actor = > Goodie = > Mushroom
Actor = > Goodie = > Star
*/