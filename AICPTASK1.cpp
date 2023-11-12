#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int NUM_ITEMS = 10;
const int BASIC_SET_COST = 200;
const double DISCOUNT_ONE_ITEM = 0.05;
const double DISCOUNT_MULTIPLE_ITEMS = 0.10;

// Structs
struct Item {
    string code;
    string description;
    double price;
};

// Function prototypes
void printTable(Item[]);
void orderMainItems(Item&, Item&, Item&);
void orderAdditionalItems(Item[]);
double calculatePrice(Item&, Item&, Item&, Item[]);
double applyDiscount(double, int);

// Main function
int main() {
    Item items[NUM_ITEMS] = {
        {"A1", "Compact", 75.00},
        {"A2", "Tower", 150.00},
        {"B1", "8 GB", 79.99},
        {"B2", "16 GB", 149.99},
        {"B3", "32 GB", 299.99},
        {"C1", "1 TB HDD", 49.99},
        {"C2", "2 TB HDD", 89.99},
        {"C3", "4 TB HDD", 129.99},
        {"G1", "Standard Version", 100.00},
        {"G2", "Professional Version", 175.00}
    };

    printTable(items);

    // Task 1: Setting up the system and ordering main items
    Item caseItem, ramItem, hddItem;
    orderMainItems(caseItem, ramItem, hddItem);

    // Task 2: Ordering additional items
    Item additionalItems[NUM_ITEMS];
    orderAdditionalItems(additionalItems);

    // Task 3: Offering discounts
    double price = calculatePrice(caseItem, ramItem, hddItem, additionalItems);
    int numAdditionalItems = 0;

    for (int i = 0; i < NUM_ITEMS; i++) {
        if (additionalItems[i].code != "") {
            numAdditionalItems++;
        }
    }

    double discount = applyDiscount(price, numAdditionalItems);
    double finalPrice = price - discount;

    // Output the final price of the computer
    cout << "Total Price: $" << fixed << setprecision(2) << finalPrice << endl;

    return 0;
}

// Prints the table of items
void printTable(Item items[]) {
    cout << setw(10) << "Category" << setw(15) << "Item code" << setw(20) << "Description" << setw(10) << "Price ($)" << endl;
    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << setw(10) << items[i].code << setw(15) << items[i].description << setw(20) << fixed << setprecision(2) << items[i].price << endl;
    }
}

// Task 1: Order main items
void orderMainItems(Item& caseItem, Item& ramItem, Item& hddItem) {
    // Implement logic to order main items
    // You can take input from the user or set default values for caseItem, ramItem, and hddItem
}

// Task 2: Order additional items
void orderAdditionalItems(Item additionalItems[]) {
    // Implement logic to order additional items
    // You can take input from the user or set default values for additionalItems
}

// Task 3: Calculate the total price and apply discounts
double calculatePrice(Item& caseItem, Item& ramItem, Item& hddItem, Item additionalItems[]) {
    // Implement logic to calculate the total price
    // You can use the provided items and additionalItems to calculate the total cost
}

// Apply discount based on the number of additional items
double applyDiscount(double price, int numAdditionalItems) {
    if (numAdditionalItems == 1) {
        return price * DISCOUNT_ONE_ITEM;
    } else if (numAdditionalItems >= 2) {
        return price * DISCOUNT_MULTIPLE_ITEMS;
    } else {
        return 0.0;
    }
}
