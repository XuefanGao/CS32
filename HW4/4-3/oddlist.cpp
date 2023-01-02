void removeOdd(list<int>& li)
{
    for (list<int>::iterator iter = li.begin(); iter != li.end();) {
        if (*iter % 2 != 0) {
            iter = li.erase(iter);
        }
        else{
            iter++;
        }
    }
}