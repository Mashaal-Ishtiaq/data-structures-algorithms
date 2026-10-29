#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    StudentRecord(int id, string name, float gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }

    // Getter functions to access the private data members
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    float getGpa() {
        return gpa;
    }


    
    // Function to print 
    void printDetails() {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

struct Node {
    StudentRecord data;
    Node* next;

    // Constructor to initialize  local data members
    Node(int id, string name, float gpa) : data(id, name, gpa), next(nullptr) {}
};

class Link_List {
private:
    Node* head;
    float total_gpa;
    int length;

public:
    Link_List() {
        head = nullptr;
        total_gpa = 0;
        length = 0;
    }

    ~Link_List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to add a student
    void add_std(int id, string name, float gpa) {
        Node* newNode = new Node(id, name, gpa);
        newNode->next = head;
        head = newNode;
        total_gpa += gpa;
        length++;
        cout << "Student added successfully" << endl;
    }

    // Function to remove a student by ID
    void remove_id(int id) {
        Node* curr = head;
        Node* slow = nullptr;

        while (curr != nullptr && curr->data.getId()!= id) {
            slow = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "No student record available" << endl;
            return;
        }

        if (slow == nullptr) {
            head = curr->next;

        } else {
            slow->next = curr->next;
        }

        total_gpa -= curr->data.getGpa();
        delete curr;
        cout << "Student removed successfully" << endl;
    }

    // Function to display all  records
    void display_records() {
        if (head == nullptr) {
            cout << "No student records available" << endl;
            return;
        }

        cout << "Student Records:" << endl;
        Node* curr = head;
        while (curr != nullptr) {
            curr->data.printDetails();
            curr = curr->next;
        }
    }

    // Function to search for a student by ID and display their information
    void search_std_byID(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.getId() == id) {
                cout << "Student found:" << endl;
                temp->data.printDetails();
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << id << " not found" << endl;
    }

    // Function to calculate the average GPA of all students
    float calc_average_gpa() {
        if (length == 0)
            return 0;
        return total_gpa / length;
    }
};

int main() {
    Link_List std_List;

    cout << "______Welcome to the Student Registration System!________" << endl;

    while (1) {
        cout << "\n1. Add a student\n";
        cout << "2. Remove a student\n";
        cout << "3. Search for a student\n";
        cout << "4. Display all students\n";
        cout << "5. Calculate average GPA\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float gpa;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student GPA: ";
                cin >> gpa;
                std_List.add_std(id, name, gpa);
                break;
            }
            case 2: {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                std_List.remove_id(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                std_List.search_std_byID(id);
                break;
            }
            case 4: {
                std_List.display_records();
                break;
            }
            case 5: {
                cout << "Average GPA: " << std_List.calc_average_gpa() << endl;
                break;
            }
            case 6: {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    return 0;
}