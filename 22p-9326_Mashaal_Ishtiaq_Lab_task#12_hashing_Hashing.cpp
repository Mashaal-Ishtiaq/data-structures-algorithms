#include <iostream>
#include <string>
using namespace std;

// Define the student structure
class Student
{

public:
    string rollNumber;
    string name;
    string fatherName;
    string department;
    string degree;
    Student *next;

    Student(string rn, string n, string fn, string dep, string deg)
        : rollNumber(rn), name(n), fatherName(fn), department(dep), degree(deg), next(nullptr) {}
};

//__ hash table class for student management
class StudentHashTable
{
private:
    Student **table; // handling collisions using chaining
    int capacity;    // Size of the hash table

    int hash(string rollNumber)
    {
        return stoi(rollNumber.substr(0, 2)); // Extract the two-digit year and convert from stringt->integer
    }

public:
    StudentHashTable(int cap) : capacity(cap)
    {
        table = new Student *[capacity]();
    }

    //____Insert

    void insert(Student *student)
    {
        int index = hash(student->rollNumber);
        student->next = table[index];
        table[index] = student;
    }

    //___Search

    Student *search(string rollNumber)
    {
        int index = hash(rollNumber);
        Student *current = table[index];
        while (current != nullptr)
        {
            if (current->rollNumber == rollNumber)
                return current;
            current = current->next;
        }
        return nullptr; // Return nullptr if no student found with the given roll number
    }

    //___display

    void display()
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << "Year " << i << ": ";
            Student *current = table[i];
            while (current != nullptr)
            {
                cout << current->name << " (" << current->rollNumber << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }

    //___deleting the dynamically allocated memory
    ~StudentHashTable()
    {
        for (int i = 0; i < capacity; ++i)
        {
            Student *current = table[i];
            while (current != nullptr)
            {
                Student *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main()
{
    StudentHashTable ht(100); // Create a hash table with 100 slots for years 00 -> 99

    //__ inserting some student records
    ht.insert(new Student("22P-9326", "Mashaal", " Ishtiaq", "Software Engeering ", "BSE"));
    ht.insert(new Student("23-5678", "Aqsa", "yousaf", "Aritifical intelligence", "BAI"));
    ht.insert(new Student("22-9101", "Minahil", "Fatima", "Mechanical Engineering", "BSME"));

    //___ Display all students
    cout << "Hash Table of Students:\n";
    ht.display();

    //____ Searching a student

    string roll = "22P-9326";
    Student *foundStudent = ht.search(roll);
    if (foundStudent)
    {
        cout << "Found student: " << foundStudent->name << " enrolled in " << foundStudent->department << endl;
    }
    else
    {
        cout << "Student with roll number " << roll << " not found." << endl;
    }

    return 0;
}