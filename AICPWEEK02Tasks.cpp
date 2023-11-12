#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_PASSENGERS = 80;
const int MIN_GROUP_SIZE = 10;
const double TICKET_PRICE = 25.0;

struct TrainJourney {
    int availableSeats;
    double revenue;
    int passengers;
};

vector<TrainJourney> upTrains(4);  // Four journeys up
vector<TrainJourney> downTrains(4);  // Four journeys down

void startOfDay() {
    for (int i = 0; i < 4; ++i) {
        upTrains[i].availableSeats = MAX_PASSENGERS;
        upTrains[i].revenue = 0.0;
        upTrains[i].passengers = 0;

        downTrains[i].availableSeats = MAX_PASSENGERS;
        downTrains[i].revenue = 0.0;
        downTrains[i].passengers = 0;
    }
}

double calculateTotalPrice(int numPassengers, int journeyIndex) {
    int numFreeTickets = numPassengers / MIN_GROUP_SIZE;
    double totalPrice = (numPassengers - numFreeTickets) * TICKET_PRICE;
    return totalPrice;
}

bool purchaseTickets(int numPassengers, int journeyIndex) {
    if (numPassengers <= 0 || numPassengers > MAX_PASSENGERS) {
        cout << "Invalid number of passengers. Please enter a number between 1 and 80." << endl;
        return false;
    }

    if (numPassengers > upTrains[journeyIndex].availableSeats || numPassengers > downTrains[journeyIndex].availableSeats) {
        cout << "Not enough available seats for the selected journey. Please choose a different number of passengers or train." << endl;
        return false;
    }

    double totalPrice = calculateTotalPrice(numPassengers, journeyIndex);

    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;

    // Update data
    upTrains[journeyIndex].availableSeats -= numPassengers;
    upTrains[journeyIndex].revenue += totalPrice;
    upTrains[journeyIndex].passengers += numPassengers;

    downTrains[journeyIndex].availableSeats -= numPassengers;
    downTrains[journeyIndex].revenue += totalPrice;
    downTrains[journeyIndex].passengers += numPassengers;

    return true;
}

void endOfDay() {
    int totalPassengers = 0;
    double totalRevenue = 0.0;
    int maxPassengersIndex = 0;

    for (int i = 0; i < 4; ++i) {
        totalPassengers += upTrains[i].passengers + downTrains[i].passengers;
        totalRevenue += upTrains[i].revenue + downTrains[i].revenue;

        if (upTrains[i].passengers + downTrains[i].passengers > upTrains[maxPassengersIndex].passengers + downTrains[maxPassengersIndex].passengers) {
            maxPassengersIndex = i;
        }
    }

    cout << "Total Passengers: " << totalPassengers << endl;
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
    cout << "Journey with the most passengers: Up " << maxPassengersIndex + 1 << " and Down " << maxPassengersIndex + 1 << endl;
}

int main() {
    startOfDay();

    // Example ticket purchase
    int numPassengers;
    int journeyIndex;

    cout << "Enter the number of passengers: ";
    cin >> numPassengers;

    cout << "Enter the journey index (1-4): ";
    cin >> journeyIndex;

    if (purchaseTickets(numPassengers, journeyIndex - 1)) {
        cout << "Tickets purchased successfully!" << endl;
    }

    // Call end of day function
    endOfDay();

    return 0;
}
