#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Student struct to store student information
struct Student
{
    string rollNumber;
    string name;
    string fatherName;
    string department;
    string degree;
    Student *next;

    Student(string roll, string n, string f, string d, string deg)
        : rollNumber(roll), name(n), fatherName(f), department(d), degree(deg), next(nullptr) {}
};

class StudentManagementSystem
{
private:
    vector<Student *> hashTable;
    int capacity;

    // Hash function to map roll number to hash table index
    int hash(string rollNumber)
    {
        int year = stoi(rollNumber.substr(0, 2));
        return year % capacity;
    }

public:
    StudentManagementSystem(int initialCapacity) : capacity(initialCapacity)
    {
        hashTable.resize(capacity, nullptr);
    }

    // Insert a student record into the hash table
    void insertStudent(string rollNumber, string name, string fatherName, string department, string degree)
    {
        int index = hash(rollNumber);
        Student *newStudent = new Student(rollNumber, name, fatherName, department, degree);

        // Handle collision using chaining
        if (hashTable[index] == nullptr)
        {
            hashTable[index] = newStudent;
        }
        else
        {
            Student *current = hashTable[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    // Retrieve a student record from the hash table using roll number
    Student *getStudent(string rollNumber)
    {
        int index = hash(rollNumber);
        Student *current = hashTable[index];

        while (current != nullptr)
        {
            if (current->rollNumber == rollNumber)
            {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    // Display all students in the hash table
    void displayStudents()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "Admission Year " << i + 2000 << ":\n";
            Student *current = hashTable[i];
            while (current != nullptr)
            {
                cout << "Roll Number: " << current->rollNumber << endl;
                cout << "Name: " << current->name << endl;
                cout << "Father's Name: " << current->fatherName << endl;
                cout << "Department: " << current->department << endl;
                cout << "Degree: " << current->degree << endl;
                cout << "-------------------\n";
                current = current->next;
            }
        }
    }
};

int main()
{
    StudentManagementSystem sms(100); // Initialize the hash table with a capacity of 100

    // Insert student records
    sms.insertStudent("23P-1234", "John Doe", "Mr. John", "Computer Science", "Bachelor");
    sms.insertStudent("23P-1235", "Jane Smith", "Mrs. Smith", "Electrical Engineering", "Master");
    sms.insertStudent("22P-1001", "Michael Johnson", "Mr. Johnson", "Mechanical Engineering", "Bachelor");
    sms.insertStudent("21P-2345", "Emily Davis", "Mrs. Davis", "Civil Engineering", "Master");

    // Retrieve a student record
    Student *student = sms.getStudent("23P-1234");
     if (student != nullptr)
    {
        cout << "Student found:\n";
        cout << "Roll Number: " << student->rollNumber << endl;
        cout << "Name: " << student->name << endl;
        cout << "Father's Name: " << student->fatherName << endl;
        cout << "Department: " << student->department << endl;
        cout << "Degree: " << student->degree << endl;
    }
    else
    {
        cout << "Student not found.\n";
    }

    // Display all students
    cout << "All Students:\n";
    sms.displayStudents();

    return 0;
}