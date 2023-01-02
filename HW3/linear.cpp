bool anyFalse(const double a[], int n) {
    // base case
    if (n <= 0) {
        return false;
    }

    else {
        bool x = somePredicate(a[n - 1]);
        if (x == false)
            return true;
    }
    return anyFalse(a, n - 1);
}


int countFalse(const double a[], int n)
{
    // base case
    if (n <= 0) {
        return 0;
    }
    else {
        bool x = somePredicate(a[n - 1]);
        if (x == false)
            return 1 + countFalse(a, n - 1);
        else
            return countFalse(a, n - 1);
    }

}



int firstTrue(const double a[], int n)
{
    if (n <= 0) {
        return -1;
    }

    if (n == 1) {
        if (somePredicate(a[n - 1])) {
            return n - 1;
        }
        return -1;
    }
    int index = firstTrue(a, n - 1);
    if (index == -1) {
        if (somePredicate(a[n - 1])) {
            return n - 1;
        }
        return -1;
    }
    return index;
}



int locateMax(const double a[], int n)
{
    if (n <= 0) {
        return -1;
    }

    //base case
    if (n == 1) {
        return 0;
    }
    // compare max(a[locateMax(a, n-1)], a[n-1])

    else {
        int index = locateMax(a, n - 1);
        if (a[n - 1] > a[index]) {
            return n - 1;
        }
        return index;
    }

}



bool contains(const double a1[], int n1, const double a2[], int n2)
{
    if (n2 > n1)
        return false;

    if (n2 == 0)
        return true;

    if (n2 - 1 == 0) {
        if (n1 - 1 == 0) {
            if (a2[n2 - 1] != a1[n1 - 1]) {
                return false;
            }
            return true;
        }
        if (a2[n2 - 1] != a1[n1 - 1]) {
            return contains(a1, n1 - 1, a2, n2);
        }
        return true;
    }
    if (a2[n2 - 1] != a1[n1 - 1]) {
        return contains(a1, n1 - 1, a2, n2);
    }
    return contains(a1, n1 - 1, a2, n2 - 1);
}