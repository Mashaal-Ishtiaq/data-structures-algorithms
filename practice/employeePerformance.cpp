// YA NICHA USE KIA HOA THA SO IS LIA BTA DIA SMJNA MA ASINI HO AGA HI BOHT JAGAR LAGYA HOA HAN
//  LCI==LEFT CHILD INDEX
//  RCI==RIGHT CHILD INDEX
// PI PARENT INDEX

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee
{
public:
    int employeeID;
    string name;
    double sales;
    double customerSatisfaction;
    double projectCompletion;
    double performanceScore;

    Employee(int id, string name, double sales, double customerSatisfaction, double projectCompletion)
    {
        this->employeeID = id;
        this->name = name;
        this->sales = sales;
        this->customerSatisfaction = customerSatisfaction;
        this->projectCompletion = projectCompletion;
        this->performanceScore = calculatePerformanceScore();
    }

    double calculatePerformanceScore()
    {
        double res = sales + customerSatisfaction + projectCompletion;
        return res;
    }
};

class MaxHeap
{
public:
    // ya cheez during prepration apna college sa sikhi thi
    auto begin()
    {
        return heap.begin();
    }

    auto end()
    {
        return heap.end();
    }
    vector<Employee> heap;

    int getPI(int index)
    {
        return (index - 1) / 2;
    }

    int getLCI(int index)
    {
        return 2 * index + 1;
    }

    int getRCI(int index)
    {
        return 2 * index + 2;
    }

    void heapifyUp(int index)
    {
        if (index == 0)
        {
            return;
        }

        int pIndex = getPI(index);
        if (heap[pIndex].performanceScore < heap[index].performanceScore)
        {
            swap(heap[pIndex], heap[index]);
            heapifyUp(pIndex);
        }
    }

    void heapifyDown(int index)
    {
        int LCI = getLCI(index);
        int RCI = getRCI(index);

        int largestIndex = index;
        if (LCI < heap.size() && heap[LCI].performanceScore > heap[largestIndex].performanceScore)
        {
            largestIndex = LCI;
        }
        if (RCI < heap.size() && heap[RCI].performanceScore > heap[largestIndex].performanceScore)
        {
            largestIndex = RCI;
        }

        if (largestIndex != index)
        {
            swap(heap[largestIndex], heap[index]);
            heapifyDown(largestIndex);
        }
    }

    void insert(const Employee &employee)
    {
        heap.push_back(employee);
        heapifyUp(heap.size() - 1);
    }

    void removeTop()
    {
        if (heap.empty())
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Top-ranking employee: " << heap[0].name << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
};

int main()
{
    MaxHeap maxHeap;

    while (1)
    {
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Menu>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "1. Enter a new employee details" << endl;
        cout << "2. Search an employee (enter the id)" << endl;
        cout << "3. Get the top-ranking employee" << endl;
        cout << "4. Update an employee score" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            double sales, customerSatisfaction, projectCompletion;

            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter sales percentage: ";
            cin >> sales;
            Employee newEmployee(id, name, sales, customerSatisfaction, projectCompletion);
            maxHeap.insert(newEmployee);

            cout << "Employee details added successfully." << endl;
        }
        else if (choice == 2)
        {
            int ID;
            cout << "Enter performance score to search: ";
            cin >> ID;

            bool found = false;
            for (const auto &employee : maxHeap)
            {
                if (employee.employeeID == ID)
                {
                    cout << "Employee found: " << employee.name << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "No employee found with the given performance score." << endl;
            }
        }
        else if (choice == 3)
        {
            maxHeap.removeTop();
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter employee ID to update score: ";
            cin >> id;

            bool found = false;
            // YA auto type-alias ha jo ka Employee class sa object bna rai ha heap ma
            for (auto &employee : maxHeap)
            {
                if (employee.employeeID == id)
                {
                    double sales, customerSatisfaction, projectCompletion;

                    cout << "Enter new sales percentage: ";
                    cin >> sales;
                    cout << "Enter new customer satisfaction percentage: ";
                    cin >> customerSatisfaction;
                    cout << "Enter new project completion percentage: ";
                    cin >> projectCompletion;

                    employee.sales = sales;
                    employee.customerSatisfaction = customerSatisfaction;
                    employee.projectCompletion = projectCompletion;
                    employee.performanceScore = employee.calculatePerformanceScore();

                    found = true;
                    cout << "socre updated." << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "ID didn't  match." << endl;
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
