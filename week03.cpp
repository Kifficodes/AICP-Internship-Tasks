#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 5;

// Source data matrix
int sourceMatrix[ROWS][COLS] = {
    {50, 150, 250, 50, 0},
    {120, 30, 80, 120, 0},
    {300, 200, 100, 0, 0}
};

// Function to calculate and display cost for slab 1
void costSlab1() {
    int unitCost = 10;
    int totalCost = 0;

    for (int i = 0; i < COLS; i++) {
        totalCost += sourceMatrix[0][i] * unitCost;
    }

    cout << "Cost for slab 1: Rs. " << totalCost << endl;
}

// Function to calculate and display cost for slab 2
void costSlab2() {
    int unitCost = 15;
    int totalCost = 0;

    for (int i = 0; i < COLS; i++) {
        totalCost += sourceMatrix[1][i] * unitCost;
    }

    cout << "Cost for slab 2: Rs. " << totalCost << endl;
}

// Function to calculate and display cost for slab 3
void costSlab3() {
    int unitCost = 20;
    int totalCost = 0;

    for (int i = 0; i < COLS; i++) {
        totalCost += sourceMatrix[2][i] * unitCost;
    }

    cout << "Cost for slab 3: Rs. " << totalCost << endl;
}

int main() {
    int choice;

    do {
        cout << "1. Display the bill of slab 1 and slab 2" << endl;
        cout << "2. Display the bill of slab 3" << endl;
        cout << "Any other key to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                costSlab1();
                costSlab2();
                break;
            case 2:
                costSlab3();
                break;
            default:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
        }

    } while (choice == 1 || choice == 2);

    return 0;
}

