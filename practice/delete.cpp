
#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    int id;
    string name;
    double price;
    int quantity;

    // Constructor with member initializer list

    Product(int id, string name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}
};

class Node
{
public:
    Product data;
    Node *prev;
    Node *next;

    // Constructor with member initializer list
    Node(int id, string name, double price, int quantity)
        : data(id, name, price, quantity), prev(nullptr), next(nullptr) {}
};

class Link_List
{
private:
    Node *head;

public:
    Link_List() : head(nullptr) {}

    ~Link_List()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Add_Product(int id, string name, double price, int quantity)
    {
        Node *newProduct = new Node(id, name, price, quantity);

        if (head == nullptr)
        {
            head = newProduct;
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr && curr->data.id < id)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr)
        {
            newProduct->next = head;
            head->prev = newProduct;
            head = newProduct;
        }
        else
        {
            prev->next = newProduct;
            newProduct->prev = prev;
            newProduct->next = curr;

            if (curr != nullptr)
            {
                curr->prev = newProduct;
            }
        }
    }

    void Remove_Product(int id)
    {
        if (head == nullptr)
        {
            cout << "Inventory is empty." << endl;
            return;
        }

        Node *curr = head;
        Node *slow = nullptr;

        while (curr != nullptr && curr->data.id != id)
        {
            slow = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Product with ID " << id << " not found in inventory." << endl;
            return;
        }

        if (slow == nullptr)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
        }
        else
        {
            slow->next = curr->next;
            if (curr->next != nullptr)
            {
                curr->next->prev = slow;
            }
        }

        delete curr;
        cout << "Product removed successfully." << endl;
    }

    void Display_Products()
    {
        if (head == nullptr)
        {
            cout << "Inventory is empty." << endl;
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            cout << "ID: " << curr->data.id << ", Name: " << curr->data.name << ", Price: " << curr->data.price << ", Quantity: " << curr->data.quantity << endl;
            curr = curr->next;
        }
    }

    void Update_Price(int id, double newPrice)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.id == id)
            {
                curr->data.price = newPrice;
                cout << "Price updated for product with ID " << id << "." << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Product with ID " << id << " not found in inventory." << endl;
    }

    void Find_Product(int id)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.id == id)
            {
                cout << "Product found:" << endl;
                cout << "ID: " << curr->data.id << ", Name: " << curr->data.name << ", Price: " << curr->data.price << ", Quantity: " << curr->data.quantity << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Product with ID " << id << " not found in inventory." << endl;
    }
};

int main()
{
    Link_List inventory;
    int choice;
    do
    {
        cout << "\n1. Add Product\n2. Remove Product\n3. Display Products\n4. Update Price\n5. Find Product\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, quantity;
            double price;
            string name;
            cout << "Enter ID, Name, Price, Quantity: ";
            cin >> id >> name >> price >> quantity;
            inventory.Add_Product(id, name, price, quantity);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID of product to remove: ";
            cin >> id;
            inventory.Remove_Product(id);
            break;
        }
        case 3:
        {
            inventory.Display_Products();
            break;
        }
        case 4:
        {
            int id;
            double newPrice;
            cout << "Enter ID of product and new price: ";
            cin >> id >> newPrice;
            inventory.Update_Price(id, newPrice);
            break;
        }
        case 5:
        {
            int id;
            cout << "Enter ID of product to find: ";
            cin >> id;
            inventory.Find_Product(id);
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
