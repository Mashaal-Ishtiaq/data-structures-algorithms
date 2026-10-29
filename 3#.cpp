#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
    int quantity;

    // Constructor
    Product(int _id, string _name, double _price, int _quantity) 
        : id(_id), name(_name), price(_price), quantity(_quantity) {}
};

class Node {
public:
    Product data;
    Node* prev;
    Node* next;

    // Constructor
    Node(Product _data) : data(_data), prev(nullptr), next(nullptr) {}
};
class Inventory {
private:
    Node* head;
    int size;

public:
    Inventory() : head(nullptr), size(0) {}

    // Destructor to free memory
    ~Inventory() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to add a product to the inventory
    void addProduct(int id, string name, double price, int quantity) {
        Product newProduct(id, name, price, quantity);
        Node* newNode = new Node(newProduct);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        size++;
    }

    // Function to remove a product from the inventory by ID
    void removeProduct(int id) {
        if (head == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->data.id == id) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else {
                    current->prev->next = current->next;
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                }
                delete current;
                size--;
                cout << "Product with ID " << id << " removed from inventory." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Product with ID " << id << " not found in inventory." << endl;
    }

    // Function to display all products in the inventory
    void displayProducts() {
        if (head == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->data.id << ", Name: " << current->data.name << ", Price: " << current->data.price << ", Quantity: " << current->data.quantity << endl;
            current = current->next;
        }
    }

    // Function to update the price of a product by ID
    void updatePrice(int id, double newPrice) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.id == id) {
                current->data.price = newPrice;
                cout << "Price updated for product with ID " << id << "." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Product with ID " << id << " not found in inventory." << endl;
    }

    // Function to find a product by ID
    void findProduct(int id) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.id == id) {
                cout << "Product found:" << endl;
                cout << "ID: " << current->data.id << ", Name: " << current->data.name << ", Price: " << current->data.price << ", Quantity: " << current->data.quantity << endl;
                return;
            }
            current = current->next;
        }

        cout << "Product with ID " << id << " not found in inventory." << endl;
    }
};
int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n1. Add Product\n2. Remove Product\n3. Display Products\n4. Update Price\n5. Find Product\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                double price;
                string name;
                cout << "Enter ID, Name, Price, Quantity: ";
                cin >> id >> name >> price >> quantity;
                inventory.addProduct(id, name, price, quantity);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of product to remove: ";
                cin >> id;
                inventory.removeProduct(id);
                break;
            }
            case 3: {
                cout << "Products in Inventory:" << endl;
                inventory.displayProducts();
                break;
            }
            case 4: {
                int id;
                double newPrice;
                cout << "Enter ID of product and new price: ";
                cin >> id >> newPrice;
                inventory.updatePrice(id, newPrice);
                break;
            }
            case 5: {
                int id;
                cout << "Enter ID of product to find: ";
                cin >> id;
                inventory.findProduct(id);
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
