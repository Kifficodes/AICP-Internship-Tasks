#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Constants
const int NUM_CHARITIES = 3;
const vector<string> CHARITY_NAMES = {"Charity A", "Charity B", "Charity C"};

// Variables to store donation totals
vector<double> charity_totals(NUM_CHARITIES, 0.0);
double grand_total = 0.0;

void displayCharities() {
    cout << "Choose a charity:" << endl;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << i + 1 << ". " << CHARITY_NAMES[i] << endl;
    }
}

double calculateDonation(double billAmount, int charityChoice) {
    const double donationPercentage = 0.01;
    double donation = billAmount * donationPercentage;
    charity_totals[charityChoice - 1] += donation;
    return donation;
}

void displayTotals() {
    vector<pair<int, double>> sortedTotals;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        sortedTotals.emplace_back(i + 1, charity_totals[i]);
    }

    sort(sortedTotals.begin(), sortedTotals.end(),
         [](const pair<int, double>& a, const pair<int, double>& b) {
             return a.second > b.second;
         });

    cout << "\nCharity Totals:" << endl;
    for (const auto& total : sortedTotals) {
        cout << CHARITY_NAMES[total.first - 1] << ": $" << total.second << endl;
    }

    cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << grand_total << endl;
}

int main() {
    // TASK 1 - Set up the donation system
    vector<string> charityNames;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        string charityName;
        cout << "Enter the name of Charity " << i + 1 << ": ";
        getline(cin, charityName);
        charityNames.push_back(charityName);
    }

    displayCharities();

    int charityChoice = 0;
    while (charityChoice < 1 || charityChoice > NUM_CHARITIES) {
        cout << "Enter the number of the chosen charity (1, 2, or 3): ";
        cin >> charityChoice;
        if (charityChoice < 1 || charityChoice > NUM_CHARITIES) {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    double billAmount;
    cout << "Enter the customer's shopping bill amount: ";
    cin >> billAmount;

    // Calculate donation and update totals
    double donationAmount = calculateDonation(billAmount, charityChoice);
    cout << "\nDonation of $" << donationAmount << " recorded for " << CHARITY_NAMES[charityChoice - 1] << "." << endl;

    // TASK 2 - Record and total each donation
    while (true) {
        displayCharities();

        cout << "Enter the number of the chosen charity (1, 2, or 3), or -1 to show totals: ";
        cin >> charityChoice;

        if (charityChoice == -1) {
            displayTotals();
            break;
        } else if (charityChoice < 1 || charityChoice > NUM_CHARITIES) {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        } else {
            double billAmount;
            cout << "Enter the customer's shopping bill amount: ";
            cin >> billAmount;

            // Calculate donation and update totals
            donationAmount = calculateDonation(billAmount, charityChoice);
            cout << "\nDonation of $" << donationAmount << " recorded for " << CHARITY_NAMES[charityChoice - 1] << "." << endl;
        }
    }

    return 0;
}
