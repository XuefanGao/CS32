#include "Map.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	Map m;
	//m.print();
	// check for insert(), update(), insertorupdate() and both get()
	assert(m.empty());
	assert(m.size() == 0);
	assert(m.insert("c", 3));
	assert(!m.empty());
	assert(m.insert("b", 2));
	assert(m.insert("a", 1));
	// now m is a-1, b-2, c-3.

	KeyType k;
	ValueType v = -1;
	assert(m.get(0, k, v));
	assert(v == 1);
	assert(m.get(1, k, v));
	assert(v == 2);
	assert(m.get(2, k, v));
	assert(v == 3);

	assert(!m.insert("c", 0));        // cannot insert duplicate values
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

	//if get returns false, v is not changed, v = 3 at this time
	assert((!m.get(" ", v)) && v == 3);
	assert(!m.get(10, k, v) && v == 3);


	//swap
	Map m1;
	Map m2;
	m1.insertOrUpdate("1", 1);
	m1.insertOrUpdate("2", 2);
	m2.insertOrUpdate("m2", 2);
	m1.swap(m2);
	//m1.print();
	//m2.print();
	m2.swap(m1);
	//m1.print();
	//m2.print();


	return 0;
}


//=====================================================


//#include "map.h"
//#include <assert.h>
//using namespace std;
//
//
//int main() {
//
//    Map mm;
//    mm.insert("Little Ricky", 3.206);
//    mm.insert("Ethel", 3.538);
//    mm.insert("Ricky", 3.350);
//    mm.insert("Lucy", 2.956);
//    mm.insert("Ethel", 3.538);
//    mm.insert("Fred", 2.956);
//    mm.insert("Lucy", 2.956);
//    assert(mm.size() == 5);  // duplicate "Ethel" and "Lucy" were not added
//    string x;
//    double y;
//
//    //mm.print();
//    mm.get(0, x, y);
//    assert(x == "Ethel");  // "Ethel" is greater than exactly 0 items in mm
//    mm.get(4, x, y);
//    assert(x == "Ricky");  // "Ricky" is greater than exactly 4 items in mm
//    mm.get(2, x, y);
//    assert(x == "Little Ricky");  // "Little Ricky" is greater than exactly 2 items in mm
//    assert(y == 3.206);  // the value corresponding to the key "Little Ricky"
//
//
//    Map m1;
//    m1.insert("Fred", 2.956);
//    Map m2;
//    m2.insert("Ethel", 3.538);
//    m2.insert("Lucy", 2.956);
//    m1.swap(m2);
//    assert(m1.size() == 2 && m1.contains("Ethel") && m1.contains("Lucy") &&
//        m2.size() == 1 && m2.contains("Fred"));
//
//    Map gpas;
//    gpas.insert("Fred", 2.956);
//    assert(!gpas.contains(""));
//    gpas.insert("Ethel", 3.538);
//    gpas.insert("", 4.000);
//    gpas.insert("Lucy", 2.956);
//    assert(gpas.contains(""));
//    gpas.erase("Fred");
//    assert(gpas.size() == 3 && gpas.contains("Lucy") && gpas.contains("Ethel") &&
//        gpas.contains(""));
//    string k;
//    double v;
//    assert(gpas.get(1, k, v) && k == "Ethel");
//    assert(gpas.get(0, k, v) && k == "");
//	return 0;
//}

//=============================================================================

//#include "Map.h"
//#include <string>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Map m;
//    assert(m.insert("Fred", 2.956));
//    assert(m.insert("Ethel", 3.538));
//    assert(m.size() == 2);
//    ValueType v = 42;
//    assert(!m.get("Lucy", v) && v == 42);
//    assert(m.get("Fred", v) && v == 2.956);
//    v = 42;
//    KeyType x = "Lucy";
//    assert(m.get(0, x, v) &&
//        ((x == "Fred" && v == 2.956) || (x == "Ethel" && v == 3.538)));
//    KeyType x2 = "Ricky";
//    assert(m.get(1, x2, v) &&
//        ((x2 == "Fred" && v == 2.956) || (x2 == "Ethel" && v == 3.538)) &&
//        x != x2);
//}
//
//int main()
//{
//    test();
//}



//=============================================================================



//#include "Map.h"
//#include <string>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Map m;
//    assert(m.insert(10, "diez"));
//    assert(m.insert(20, "veinte"));
//    assert(m.size() == 2);
//    ValueType v = "cuarenta y dos";
//    assert(!m.get(30, v) && v == "cuarenta y dos");
//    assert(m.get(10, v) && v == "diez");
//    v = "cuarenta y dos";
//    KeyType x = 30;
//    assert(m.get(0, x, v) &&
//        ((x == 10 && v == "diez") || (x == 20 && v == "veinte")));
//    KeyType x2 = 40;
//    assert(m.get(1, x2, v) &&
//        ((x2 == 10 && v == "diez") || (x2 == 20 && v == "veinte")) &&
//        x != x2);
//}
//
//int main()
//{
//    test();
//}


//=============================================================================


//#include "Map.h"
//#include <cassert>
//using namespace std;
//
//int main()
//{
//    Map m;  // maps strings to doubles
//    assert(m.empty());
//    ValueType v = -1234.5;
//    assert(!m.get("abc", v) && v == -1234.5); // v unchanged by get failure
//    m.insert("xyz", 9876.5);
//    assert(m.size() == 1);
//    KeyType k = "hello";
//    assert(m.get(0, k, v) && k == "xyz" && v == 9876.5);
//}

//=============================================================================
//#include "Map.h"
//#include <cassert>
//using namespace std;
//
//int main()
//{
//    Map m;  // maps ints to strings
//    assert(m.empty());
//    ValueType v = "Ouch";
//    assert(!m.get(42, v) && v == "Ouch"); // v unchanged by get failure
//    m.insert(123456789, "Wow!");
//    assert(m.size() == 1);
//    KeyType k = 9876543;
//    assert(m.get(0, k, v) && k == 123456789 && v == "Wow!");
//}
//



