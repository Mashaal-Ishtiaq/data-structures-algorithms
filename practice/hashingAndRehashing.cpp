#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *next;

    Node(int k) : key(k), next(nullptr) {}
};

class HashTable
{
private:
    Node **table;
    int capacity;
    int size;

    int hash(int key)
    {
        return key % capacity; // index of key
    }

    void rehash()
    {
        int newCapacity = capacity * 2;

        Node **newTable = new Node *[newCapacity]();
        for (int i = 0; i < capacity; ++i)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                int newHash = hash(current->key) % newCapacity;
                Node *newNode = new Node(current->key);
                newNode->next = newTable[newHash];
                newTable[newHash] = newNode;

                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] table;
        table = newTable;
        capacity = newCapacity;
    }

public:
    HashTable(int initialCapacity) : capacity(initialCapacity), size(0)
    {
        table = new Node *[capacity]();
    }

    void insert(int key)
    {
        int h = hash(key);
        Node *newNode = new Node(key);
        newNode->next = table[h];
        table[h] = newNode;
        size++;

        if (size > capacity)
        {
            rehash();
        }
    }

    void display()
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << "Bucket " << i << ": ";
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; ++i)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable hashTable(5);

    // Insert some elements
    hashTable.insert(1);
    hashTable.insert(6);
    hashTable.insert(11);
    hashTable.insert(16);
    hashTable.insert(21);

    // Display the original hash table
    cout << "Original Hash Table:\n";
    hashTable.display();

    // Insert more elements (to trigger rehashing)
    hashTable.insert(26);
    hashTable.insert(31);
    hashTable.insert(36);

    // Display the updated hash table after rehashing
    cout << "\nHash Table After Rehashing:\n";
    hashTable.display();

    return 0;
}
