#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Boat class to store information about each boat
class Boat {
public:
    int boatNumber;
    double totalMoney;
    double totalHours;
    double returnTime;

    Boat(int number) : boatNumber(number), totalMoney(0.0), totalHours(0.0), returnTime(10.0) {}
};

// Function to calculate money taken for one boat (Task 1)
void calculateMoneyForOneBoat(Boat& boat) {
    cout << "Enter the hiring duration for Boat " << boat.boatNumber << " in hours: ";
    double duration;
    cin >> duration;

    // Validate hiring time
    if (duration <= 0 || duration > 7 || boat.returnTime + duration > 17) {
        cout << "Invalid hiring duration or return time. Please enter a valid duration.\n";
        return;
    }

    double cost;
    if (duration == 0.5) {
        cost = 12.0;
    } else {
        cost = 20.0 * duration;
    }

    boat.totalMoney += cost;
    boat.totalHours += duration;
    boat.returnTime += duration;

    cout << fixed << setprecision(2);
    cout << "Boat " << boat.boatNumber << " hired for " << duration << " hours. Cost: $" << cost << endl;
}

// Function to find the next available boat or show the earliest available time (Task 2)
void findNextAvailableBoat(const vector<Boat>& boats) {
    double currentTime;
    cout << "Enter the current time in 24-hour format (e.g., 14.30): ";
    cin >> currentTime;

    int availableBoats = 0;
    double earliestAvailableTime = 17.0;

    for (const Boat& boat : boats) {
        if (boat.returnTime <= currentTime) {
            availableBoats++;
        } else {
            earliestAvailableTime = min(earliestAvailableTime, boat.returnTime);
        }
    }

    if (availableBoats > 0) {
        cout << "Available boats: " << availableBoats << endl;
    } else {
        cout << "No boats available. Next available time: " << earliestAvailableTime << " hours\n";
    }
}

// Function to calculate money taken for all boats at the end of the day (Task 3)
void calculateMoneyForAllBoats(const vector<Boat>& boats) {
    double totalMoney = 0.0;
    double totalHours = 0.0;
    int unusedBoats = 0;
    int mostUsedBoat = 0;
    double maxHours = 0.0;

    for (const Boat& boat : boats) {
        totalMoney += boat.totalMoney;
        totalHours += boat.totalHours;

        if (boat.totalHours == 0.0) {
            unusedBoats++;
        }

        if (boat.totalHours > maxHours) {
            maxHours = boat.totalHours;
            mostUsedBoat = boat.boatNumber;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total money taken for all boats: $" << totalMoney << endl;
    cout << "Total hours boats were hired: " << totalHours << " hours\n";
    cout << "Number of boats not used: " << unusedBoats << endl;
    cout << "Boat #" << mostUsedBoat << " was used the most with " << maxHours << " hours\n";
}

int main() {
    // Create 10 boats
    vector<Boat> boats;
    for (int i = 1; i <= 10; ++i) {
        boats.push_back(Boat(i));
    }

    // Task 1: Calculate money for one boat
    for (Boat& boat : boats) {
        calculateMoneyForOneBoat(boat);
    }

    // Task 2: Find next available boat
    findNextAvailableBoat(boats);

    // Task 3: Calculate money for all boats at the end of the day
    calculateMoneyForAllBoats(boats);

    return 0;
}
