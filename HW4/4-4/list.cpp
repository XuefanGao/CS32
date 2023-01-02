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
        cout << path + "=>" + a->name() << endl;
        if (a->subclasses().size() > 0)
            listAll(path + "=>" + a->name(), a);
    }
}

