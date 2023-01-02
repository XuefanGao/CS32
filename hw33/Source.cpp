
#include <iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

int countContains(const double a1[], int n1, const double a2[], int n2){
    if (n1 > 0 && n2 <= 0)
        return 1;

    else if (n1 <= 0 || n2 > n1)
        return 0;
    
    if (a1[0] == a2[0])
        return countContains(a1 + 1, n1 - 1, a2 + 1, n2 - 1) + countContains(a1 + 1, n1 - 1, a2, n2);

    return countContains(a1 + 1, n1 - 1, a2, n2);
}


void exchange(double& x, double& y){
    double temp = x;
    x = y;
    y = temp;
}


void separate(double a[], int n, double separator,
    int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;

    while (firstUnknown < firstLess){
        if (a[firstUnknown] < separator){
            firstLess = firstLess - 1;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else{
            if (a[firstUnknown] > separator){
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater = firstNotGreater + 1;
            }
            firstUnknown = firstUnknown + 1;
        }
    }
}


void order(double a[], int n){
    int firstNGreater = n;
    int firstLess = n;
    if (n > 1 ) {
        separate(a, n, a[n - 1], firstNGreater, firstLess);
        order(a, firstNGreater);
        order(a + firstLess, n - firstLess);
    }
    return;
}

int main() {
    srand(1);
    double a[10], b[10];
    int firstNGreater = 0;
    int firstless = 0;
    //srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        double integer = rand() % 100 + 1;
        a[i] = integer;
        b[i] = integer;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        std::cout << b[i] << " ";
    }
    cout << endl;

    separate(b, 10, b[0], firstNGreater, firstless);
    order(a, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        std::cout << b[i] << " ";
    }

}
