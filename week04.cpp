#include<iostream>
#include<cmath>

class Hexagon {
private:
    double side;

public:
    // Constructor to initialize the side length
    Hexagon(double s) : side(s) {}

    // Member functions to calculate and display area, perimeter, and sum of angles
    double calcArea() {
        return 1.5 * 1.732 * side;
    }

    double calcPeri() {
        return 6 * side;
    }

    double calcAngleSum() {
        return 6 * 120;
    }

    void display() {
        std::cout << "Hexagon - Area: " << calcArea() << ", Perimeter: " << calcPeri() << ", Sum of Angles: " << calcAngleSum() << std::endl;
    }
};

class Square {
private:
    double side;

public:
    // Constructor to initialize the side length
    Square(double s) : side(s) {}

    // Member functions to calculate and display area and perimeter
    double calcAreaSquare() {
        return side * side;
    }

    double calcPeriSquare() {
        return 4 * side;
    }

    void display() {
        std::cout << "Square - Area: " << calcAreaSquare() << ", Perimeter: " << calcPeriSquare() << std::endl;
    }
};

int main() {
    // Extract the last digit of your CNIC (replace '2' with your actual last digit)
    int lastDigit = 2;

    // Create objects of Hexagon and Square
    Hexagon hexagon(lastDigit);
    Square square(lastDigit + 1);

    // Display menu and perform operations based on user input
    int choice;
    do {
        std::cout << "Menu:\n1. Hexagon\n2. Square\nAny other input to exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            hexagon.display();
            break;
        case 2:
            square.display();
            break;
        default:
            std::cout << "Exiting program." << std::endl;
            break;
        }
    } while (choice == 1 || choice == 2);

    return 0;
}
