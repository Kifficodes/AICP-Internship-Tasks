#include <iostream>

using namespace std;

// Constants
const int COST_CEMENT = 3;
const int COST_GRAVEL = 2;
const int COST_SAND = 2;
const int DISCOUNT_PACK_CEMENT = 1;
const int DISCOUNT_PACK_SAND = 2;
const int DISCOUNT_PACK_GRAVEL = 2;
const int DISCOUNT_PRICE = 10;

// Function to check a single sack
pair<char, double> check_single_sack() {
    cout << "Task 1 - Check contents and weight of a single sack:" << endl;
    char contents;
    double weight;

    cout << "Contents (C for Cement, G for Gravel, S for Sand): ";
    cin >> contents;
    contents = toupper(contents);

    cout << "Weight (in kilograms): ";
    cin >> weight;

    // Check contents
    if (contents != 'C' && contents != 'G' && contents != 'S') {
        cout << "Sack rejected: Invalid contents." << endl;
        return make_pair('0', 0);
    }

    // Check weight
    if ((contents == 'C' && (weight < 24.9 || weight > 25.1)) ||
        ((contents == 'G' || contents == 'S') && (weight < 49.9 || weight > 50.1))) {
        cout << "Sack rejected: Invalid weight." << endl;
        return make_pair('0', 0);
    }

    cout << "Sack accepted - Contents: " << contents << ", Weight: " << weight << " kg." << endl;
    return make_pair(contents, weight);
}

// Task 2 - Check a customer's order for delivery
void check_customer_order() {
    double total_weight = 0;
    int sacks_rejected = 0;

    int num_sacks_cement, num_sacks_gravel, num_sacks_sand;

    cout << "\nTask 2 - Check a customer's order for delivery:" << endl;
    cout << "Enter the number of sacks of Cement: ";
    cin >> num_sacks_cement;
    cout << "Enter the number of sacks of Gravel: ";
    cin >> num_sacks_gravel;
    cout << "Enter the number of sacks of Sand: ";
    cin >> num_sacks_sand;

    for (int i = 0; i < num_sacks_cement; ++i) {
        auto check_result = check_single_sack();
        if (check_result.second > 0) {
            total_weight += check_result.second;
        } else {
            sacks_rejected++;
        }
    }

    for (int i = 0; i < num_sacks_gravel; ++i) {
        auto check_result = check_single_sack();
        if (check_result.second > 0) {
            total_weight += check_result.second;
        } else {
            sacks_rejected++;
        }
    }

    for (int i = 0; i < num_sacks_sand; ++i) {
        auto check_result = check_single_sack();
        if (check_result.second > 0) {
            total_weight += check_result.second;
        } else {
            sacks_rejected++;
        }
    }

    cout << "\nTotal weight of the order: " << total_weight << " kg" << endl;
    cout << "Number of sacks rejected from the order: " << sacks_rejected << endl;
}

// Task 3 - Calculate the price for a customer's order
void calculate_order_price() {
    int regular_price = 0;

    int num_discount_packs = 0;
    int num_sacks_cement, num_sacks_gravel, num_sacks_sand;

    cout << "\nTask 3 - Calculate the price for a customer's order:" << endl;
    cout << "Enter the number of sacks of Cement: ";
    cin >> num_sacks_cement;
    cout << "Enter the number of sacks of Gravel: ";
    cin >> num_sacks_gravel;
    cout << "Enter the number of sacks of Sand: ";
    cin >> num_sacks_sand;

    // Calculate regular price
    regular_price += num_sacks_cement * COST_CEMENT;
    regular_price += num_sacks_gravel * COST_GRAVEL;
    regular_price += num_sacks_sand * COST_SAND;

    // Check for discount packs
    while (num_sacks_cement >= DISCOUNT_PACK_CEMENT &&
           num_sacks_gravel >= DISCOUNT_PACK_GRAVEL &&
           num_sacks_sand >= DISCOUNT_PACK_SAND) {
        num_discount_packs++;
        num_sacks_cement -= DISCOUNT_PACK_CEMENT;
        num_sacks_gravel -= DISCOUNT_PACK_GRAVEL;
        num_sacks_sand -= DISCOUNT_PACK_SAND;
    }

    // Calculate total price
    int total_price = regular_price + num_discount_packs * DISCOUNT_PRICE;

    cout << "\nRegular price for the order: $" << regular_price << endl;
    cout << "Number of discount packs in the order: " << num_discount_packs << endl;
    cout << "New price for the order: $" << total_price << endl;
    cout << "Amount saved: $" << (regular_price - total_price) << endl;
}

int main() {
    // Task 1 - Check contents and weight of a single sack
    check_single_sack();

    // Task 2 - Check a customer's order for delivery
    check_customer_order();

    // Task 3 - Calculate the price for a customer's order
    calculate_order_price();

    return 0;
}
