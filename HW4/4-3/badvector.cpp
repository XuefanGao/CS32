void removeBad(vector<Movie*>& v)
{
    vector<Movie*>::iterator iter = v.begin();
    while (iter != v.end()) {
        if ((*iter)->rating() < 50) {
            (*iter)->~Movie();
            iter = v.erase(iter);
        }
        else
            iter++;
    }
}