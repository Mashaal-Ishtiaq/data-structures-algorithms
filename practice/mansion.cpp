#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<string> stack;

public:
    void push(const string &element)
    {
        stack.push_back(element);
    }

    void pop()
    {
        if (!isEmpty())
        {
            stack.pop_back();
        }
    }

    string top()
    {
        if (!isEmpty())
        {
            return stack.back();
        }
        return "";
    }

    bool isEmpty()
    {
        return stack.empty();
    }
};

class Queue
{
private:
    vector<string> queue;

public:
    void enqueue(const string &element)
    {
        queue.push_back(element);
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            queue.erase(queue.begin());
        }
    }

    string front()
    {
        if (!isEmpty())
        {
            return queue.front();
        }
        return "";
    }

    bool isEmpty()
    {
        return queue.empty();
    }
};

class HauntedMansion
{
private:
    Queue places;
    Stack ghostEncountersStack;

public:
    HauntedMansion()
    {
        bool permission;

        places.enqueue("Start exploring the mansion");
        places.enqueue("The Gateway to Darkness");
        places.enqueue("The Creeping Corridor");
        places.enqueue("The abandoned lounge");
        places.enqueue("The haunted gallery");
        places.enqueue("The shadowed library");
        places.enqueue("The broken window (the exit)");
    }

    void addGhostEncounter(const string &place)
    {
        ghostEncountersStack.push(place);
    }

    void explorePlaces()
    {
        while (!places.isEmpty())
        {
            string currentPlace = places.front();
            places.dequeue();
            cout << "Exploring: " << currentPlace << endl;

            if (currentPlace != "The Gateway to Darkness")
            {
                addGhostEncounter(currentPlace);
            }
        }
    }

    void printGhostEncounters()
    {
        cout << "Ghost Encounters:" << endl;
        while (!ghostEncountersStack.isEmpty())
        {
            string ghostEncounter = ghostEncountersStack.top();
            ghostEncountersStack.pop();
            cout << ghostEncounter << endl;
        }
    }
};

int main()
{
    HauntedMansion mansion;
    int choice;

    cout << "Start exploring the mansion places one by one..." << endl;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Explore next place" << endl;
        cout << "2. Print ghost encounters" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            mansion.explorePlaces();
            break;
        case 2:
            mansion.printGhostEncounters();
            break;
        case 3:
            cout << "You left safe and sound!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}