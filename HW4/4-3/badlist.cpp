void removeBad(list<Movie*>& li)
{
    list<Movie*>::iterator iter = li.begin();
    while (iter != li.end()) {
        if ((*iter)->rating() < 50) {
            (*iter)->~Movie();
            iter = li.erase(iter);
        }
        else
            iter++;
    }
}