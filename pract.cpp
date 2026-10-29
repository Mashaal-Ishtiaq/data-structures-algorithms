#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void generateRandomInventory(int* inventory, int size);
double calculateAverageStock(int* inventory, int size);
int countCriticalProducts(int* inventory, int size, double average);
void findTopSellingProduct(int* inventory, int size);
int findSecondBestSeller(int* inventory, int size);
void sortByPopularity(int* inventory, int size);

int main() {
    // Seed for random number generation
    srand(time(0));

    // User input for inventory size
    int size;
    cout << "Enter the size of the inventory array: ";
    cin >> size;

    // Dynamically allocate memory for the inventory array
    int* inventory = new int[size];

    // Generate random quantities of product items
    generateRandomInventory(inventory, size);

    // Calculate average stock level
    double average = calculateAverageStock(inventory, size);
    cout << "Average Stock Level: " << average << endl;

    // Identify and count critically low stock products
    int criticalCount = countCriticalProducts(inventory, size, average);
    cout << "Number of Critical Products: " << criticalCount << endl;

    // Discover the top-selling product
    findTopSellingProduct(inventory, size);

    // Find the second best-selling product
    int secondBestSeller = findSecondBestSeller(inventory, size);
    cout << "Second Best-Selling Product: " << inventory[secondBestSeller] << " units" << endl;

    // Sort products by popularity
    sortByPopularity(inventory, size);

    // Clean up: Deallocate memory
    delete[] inventory;

    return 0;
}

// Function to generate random quantities of product items
void generateRandomInventory(int* inventory, int size) {
    for (int i = 0; i < size; ++i) {
        inventory[i] = rand() % 100 + 1; // Random quantity between 1 and 100
    }
}

// Function to calculate the average stock level
double calculateAverageStock(int* inventory, int size) {
    int totalStock = 0;
    for (int i = 0; i < size; ++i) {
        totalStock += inventory[i];
    }
    return static_cast<double>(totalStock) / size;
}

// Function to identify and count critically low stock products
int countCriticalProducts(int* inventory, int size, double average) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (inventory[i] < average) {
            ++count;
        }
    }
    return count;
}

// Function to find and print the top-selling product
void findTopSellingProduct(int* inventory, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (inventory[i] > inventory[maxIndex]) {
            maxIndex = i;
        }
    }
    cout << "Top-Selling Product: " << inventory[maxIndex] << " units" << endl;
}

// Function to find the index of the second best-selling product
int findSecondBestSeller(int* inventory, int size) {
    int maxIndex = 0;
    int secondMaxIndex = -1;
    for (int i = 1; i < size; ++i) {
        if (inventory[i] > inventory[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        } else if (secondMaxIndex == -1 || inventory[i] > inventory[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;
}

// Function to sort products in descending order based on sales volume
void sortByPopularity(int* inventory, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (inventory[j] < inventory[j + 1]) {
                // Swap if the current element is less than the next element
                swap(inventory[j], inventory[j + 1]);
            }
        }
    }

    // Display sorted inventory
    cout << "Sorted Inventory by Popularity: ";
    for (int i = 0; i < size; ++i) {
        cout << inventory[i] << " ";
    }
    cout << endl;
}
