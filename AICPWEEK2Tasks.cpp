#include <iostream>
#include <iomanip>
#include <vector>

const int NUM_JOURNEYS = 4;
const int MAX_PASSENGERS = 80;
const double TICKET_PRICE = 25.0;

struct TrainJourney {
    int availableSeats;
    int passengers;
    double revenue;
};

void initializeDay(std::vector<TrainJourney>& upTrains, std::vector<TrainJourney>& downTrains) {
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        upTrains.push_back({MAX_PASSENGERS, 0, 0.0});
        downTrains.push_back({MAX_PASSENGERS, 0, 0.0});
    }
}

void displayAvailableSeats(const std::vector<TrainJourney>& trains, const std::string& direction) {
    std::cout << "Available seats for " << direction << " journeys:\n";
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        std::cout << "Train " << i + 1 << ": ";
        if (trains[i].availableSeats > 0) {
            std::cout << trains[i].availableSeats << " seats available\n";
        } else {
            std::cout << "Closed\n";
        }
    }
    std::cout << std::endl;
}

void purchaseTickets(std::vector<TrainJourney>& upTrains, std::vector<TrainJourney>& downTrains) {
    int upTrain, downTrain, numPassengers;
    std::cout << "Enter the train number for the upward journey (1-4): ";
    std::cin >> upTrain;

    if (upTrain < 1 || upTrain > NUM_JOURNEYS) {
        std::cerr << "Invalid train number for the upward journey.\n";
        return;
    }

    std::cout << "Enter the train number for the downward journey (1-4): ";
    std::cin >> downTrain;

    if (downTrain < 1 || downTrain > NUM_JOURNEYS) {
        std::cerr << "Invalid train number for the downward journey.\n";
        return;
    }

    std::cout << "Enter the number of passengers: ";
    std::cin >> numPassengers;

    if (numPassengers < 1 || numPassengers > MAX_PASSENGERS) {
        std::cerr << "Invalid number of passengers.\n";
        return;
    }

    TrainJourney& upJourney = upTrains[upTrain - 1];
    TrainJourney& downJourney = downTrains[downTrain - 1];

    if (upJourney.availableSeats < numPassengers || downJourney.availableSeats < numPassengers) {
        std::cerr << "Not enough available seats for the selected journeys.\n";
        return;
    }

    double totalCost = numPassengers * TICKET_PRICE;

    // Check for group discount
    if (numPassengers >= 10) {
        int freeTickets = numPassengers / 10;
        totalCost -= freeTickets * TICKET_PRICE;
    }

    // Update data
    upJourney.availableSeats -= numPassengers;
    downJourney.availableSeats -= numPassengers;
    upJourney.passengers += numPassengers;
    downJourney.passengers += numPassengers;
    upJourney.revenue += totalCost;
    downJourney.revenue += totalCost;

    std::cout << "Tickets purchased successfully. Total cost: $" << std::fixed << std::setprecision(2) << totalCost << "\n\n";
}

void displayEndOfDayStats(const std::vector<TrainJourney>& upTrains, const std::vector<TrainJourney>& downTrains) {
    int totalPassengers = 0;
    double totalRevenue = 0.0;
    int maxPassengers = 0;
    int maxPassengersIndex = -1;

    std::cout << "End of the day statistics:\n";
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        totalPassengers += upTrains[i].passengers + downTrains[i].passengers;
        totalRevenue += upTrains[i].revenue + downTrains[i].revenue;

        std::cout << "Upward Train " << i + 1 << ": " << upTrains[i].passengers << " passengers, revenue: $"
                  << std::fixed << std::setprecision(2) << upTrains[i].revenue << "\n";
        std::cout << "Downward Train " << i + 1 << ": " << downTrains[i].passengers << " passengers, revenue: $"
                  << std::fixed << std::setprecision(2) << downTrains[i].revenue << "\n";

        if (upTrains[i].passengers > maxPassengers) {
            maxPassengers = upTrains[i].passengers;
            maxPassengersIndex = i;
        }
        if (downTrains[i].passengers > maxPassengers) {
            maxPassengers = downTrains[i].passengers;
            maxPassengersIndex = i;
        }
    }

    std::cout << "\nTotal passengers for the day: " << totalPassengers << "\n";
    std::cout << "Total revenue for the day: $" << std::fixed << std::setprecision(2) << totalRevenue << "\n";
    std::cout << "Train journey with the most passengers: ";
    if (maxPassengersIndex != -1) {
        std::cout << "Upward Train " << maxPassengersIndex + 1 << " with " << maxPassengers << " passengers.\n";
    } else {
        std::cout << "No data available.\n";
    }
}

int main() {
    std::vector<TrainJourney> upTrains;
    std::vector<TrainJourney> downTrains;

    initializeDay(upTrains, downTrains);

    // Display available seats at the start of the day
    displayAvailableSeats(upTrains, "upward");
    displayAvailableSeats(downTrains, "downward");

    // Simulate ticket purchases (you can replace this with actual user interactions)
    purchaseTickets(upTrains, downTrains);
    purchaseTickets(upTrains, downTrains);

    // Display end-of-day statistics
    displayEndOfDayStats(upTrains, downTrains);

    return 0;
}
