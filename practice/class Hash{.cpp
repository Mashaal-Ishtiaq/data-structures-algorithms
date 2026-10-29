class Hash
{
private:
    int n;
    int *arr;

public:
    Hash(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    int hashFunction(int k)
    {
        return k % n; // returns index
    }
    void insert(int k)
    {
        arr[hashFunction(k)] = k;
    }
    bool search(int k)
    {
        if (arr[hashFunction(k)] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// auto=just like variables dont have a return type in python, similarly we use auto to give a return type of our own choice. conside the following example:
int fun1()
{
    return 1;
}
float fun2()
{
    return 1.1;
}
int main()
{
    auto a = fun1();
    auto b = fun2();
}
// list declaration
std::list<datatype> newList; // list stores members of same datatype
int main()
{
    list<int> myList;
    myList.push_back(0); // for insertion at the enclass Hash{
private:
    int n;
    int *arr;

public:
    Hash(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    int hashFunction(int k)
    {
        return k % n; // returns index
    }
    void insert(int k)
    {
        arr[hashFunction(k)] = k;
    }
    bool search(int k)
    {
        if (arr[hashFunction(k)] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// auto=just like variables dont have a return type in python, similarly we use auto to give a return type of our own choice. conside the following example:
int fun1()
{
    return 1;
}
float fun2()
{
    return 1.1;
}
int main()
{
    auto a = fun1();
    auto b = fun2();
}
// list declaration
std::list<datatype> newList; // list stores members of same datatype
int main()
{
    list<int> myList;
    myList.push_back(0); // for insertion at the end
    myList.pushback(1);
    myList.pushback(2);

    myList.front(); // to show the first element which was inserted

    myList.pop_back(); // pops the end value but it also deletes them
    // we want to show the elements in the same order as we inserted them and also they shouldnt be deleted
    for (auto i = myList.begin(); i != myList.end(); i++)
    { // begin() takes you to the start, end() takes you to the end
        cout << *i;
    }
    for (int i : myList)
    {
        cout << i;
    }
    // separate chaining
    for (auto i = myList[index].begin(); i != myList[index].end(); i++)
    {
        if (*i == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    d
        myList.pushback(1);
    myList.pushback(2);

    myList.front(); // to show the first element which was inserted

    myList.pop_back(); // pops the end value but it also deletes them
    // we want to show the elements in the same order as we inserted them and also they shouldnt be deleted
    for (auto i = myList.begin(); i != myList.end(); i++)
    { // begin() takes you to the start, end() takes you to the end
        cout << *i;
    }
    for (int i : myList)
    {
        cout << i;
    }
    // separate chaining
    for (auto i = myList[index].begin(); i != myList[index].end(); i++)
    {
        if (*i == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }