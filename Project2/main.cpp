/*

destructor, copy const,assignment op
Destructor
When a Map is destroyed, the nodes in the linked list must be deallocated.
Copy constructor
When a new Map is created as a copy of an existing Map, enough new nodes must be allocated
to hold a duplicate of the original list.
Assignment operator
When an existing Map (the left-hand side) is assigned the value of another Map (the right-hand
side), the result must be that the left-hand side object is a duplicate of the right-hand side
object, with no memory leak of list nodes (i.e. no list node from the old value of the left-hand
side should be still allocated yet inaccessible).



inline

clean includes


*/


#include "Map.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	Map m;

	// check for insert(), update(), insertorupdate() and both get()
	assert(m.empty());
	assert(m.size() == 0);
	assert(m.insert("b", 2));       // insert as the first node
	assert(!m.empty());
	assert(m.insert("c", 3));       // insert to tail
	assert(m.insert("a", 1));       // insert to front
	assert(!m.insert("c", 0));        // cannot insert duplicate values
	// now m is a-1, b-2, c-3.

	KeyType k;
	ValueType v = -1;
	// check get(i, k, v)
	assert(m.get(0, k, v));
	assert(v == 1);
	assert(m.get(1, k, v));
	assert(v == 2);
	assert(m.get(2, k, v));
	assert(v == 3);

	// check update()
	assert(m.insert("", 0));          // m is a-1, b-2, c-3, -0.
	assert(m.size() == 4);
	assert(m.update("", 0));
	assert(m.get(0, k, v));
	assert(v == 0);
	assert(m.update("", 5));
	assert(m.get(0, k, v));
	assert(v == 5);

	assert(m.insertOrUpdate("", 0));
	assert(m.get(0, k, v));
	assert(v == 0);

	// check get(k, v)
	assert(m.get("", v));
	assert(v == 0);
	assert(m.get("a", v));
	assert(v == 1);
	assert(m.get("b", v));
	assert(v == 2);
	assert(m.get("c", v));
	assert(v == 3);


	// check contains()
	assert(m.contains(""));
	assert(m.contains("a"));
	assert(m.contains("b"));
	assert(m.contains("c"));
	assert(!m.contains(" "));

	// check erase()
	assert(m.erase("c"));            //erase from tail
	assert(!m.contains("c"));

	assert(m.erase("b"));            //erase from middle
	assert(!m.contains("b"));

	assert(m.erase(""));             //erase from head
	assert(!m.contains(""));

	assert(m.erase("a"));
	assert(!m.contains("a"));
	assert(!m.erase("a"));

	assert(m.empty());
	assert(m.size() == 0);

	// if get() returns false, v is not changed, v = 3 at this time
	assert((!m.get(" ", v)) && v == 3);
	assert(!m.get(10, k, v) && v == 3);


	// check swap()
	// swap 2 empty maps
	Map m1;
	Map m2;
	m1.swap(m2);
	/*m1.print();
	m2.print();*/
	assert(m1.empty());
	assert(m2.empty());

	// swap an empty map with another
	Map m3;
	assert(m3.insert("a", 1));
	m1.swap(m3);
	/*m1.print();
	m3.print();*/
	assert(m1.size() == 1);
	assert(m3.size() == 0);

	assert(m1.insert("b", 2));
	assert(m1.insert("c", 3));
	m1.swap(m3);
	/*m1.print();
	m3.print();*/
	assert(m1.size() == 0);
	assert(m3.size() == 3);

	// swap maps of different length
	Map m4;
	assert(m4.insert("a", 2));
	assert(m4.insert("b", 3));
	m4.swap(m3);
	/*m4.print();
	m3.print();*/
	assert(m4.size() == 3);
	assert(m3.size() == 2);


	// check merge()
	// merge different sizes
	assert(!merge(m3, m4, m1));
	// m1.print();

	// merge two empty maps
	Map mm1;
	Map mm2;
	assert(merge(mm1, mm2, m1));
	//m1.print();

	// merge two identical maps
	assert(merge(m4, m4, m1));
	//m1.print();

	// merge empty map with another
	assert(merge(m4, mm2, m1));
	//m1.print();

	// merge maps with all values different
	m2.insert("a", 5);
	m2.insert("b", 5);
	m2.insert("c", 5);
	assert(!merge(m4, m2, m1));
	//m1.print();

	// merge example given in spec
	Map s1, s2, s3;
	s1.insert("Fred", 123);
	s1.insert("Ethel",456);
	s1.insert("Lucy",789);
	s2.insert("Lucy",789);
	s2.insert("Ricky",321);
	assert(merge(s1, s2, m1));
	//m1.print();
	s3.insert("Lucy",  654);
	s3.insert("Ricky",  321);
	assert(!merge(s1, s3, m1));
	//m1.print();


	// check reassign()
	// example given in spec (no repeated value)
	s1.insert("Ricky", 321);
	reassign(s1, m1);
	//m1.print();
	//s1.print();             // make sure it doesn't change the original map

	// rearrange empty map
	Map r1;
	reassign(r1, m1);
	//m1.print();

	// example given in spec (repeated value)
	r1.insert("Fred", 123);
	r1.insert("Ethel", 456);
	r1.insert("Lucy", 456);
	reassign(r1, m1);
	//m1.print();

	cout << "pass";
    return 0;
}