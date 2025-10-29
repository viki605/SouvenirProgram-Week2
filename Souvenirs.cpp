#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>  // for file output
using namespace std;

int main() {
    // Introduction banner
    cout << "==================================================\n";
    cout << "     Welcome to Viktorija's Souvenir Tracker  \n";
    cout << "==================================================\n\n";

    // Variables
    string souvenirName;
    int quantity;
    double pricePerItem;

    // User input with validation
    cout << "Enter the name of the souvenir: ";
    getline(cin, souvenirName);

    cout << "Enter the quantity you bought: ";
    cin >> quantity;

    if (cin.fail() || quantity <= 0) {
        cout << "Invalid quantity entered. Setting quantity to 1.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        quantity = 1;
    }

    cout << "Enter the price per item (in USD): ";
    cin >> pricePerItem;

    if (cin.fail() || pricePerItem <= 0) {
        cout << "Invalid price entered. Setting price to $1.00.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        pricePerItem = 1.00;
    }

    // Derived value
    double totalCost = quantity * pricePerItem;

    // Display formatted summary
    cout << "\n===================== Souvenir Summary =====================\n";
    cout << left << setw(20) << "Souvenir Name" << right << setw(15) << "Quantity"
        << right << setw(20) << "Price Each ($)"
        << right << setw(20) << "Total ($)" << endl;
    cout << "------------------------------------------------------------\n";
    cout << left << setw(20) << souvenirName
        << right << setw(15) << quantity
        << right << setw(20) << fixed << setprecision(2) << pricePerItem
        << right << setw(20) << fixed << setprecision(2) << totalCost << endl;

    // Save to file
    ofstream report("report.txt");
    if (report.is_open()) {
        report << "================= Souvenir Summary ========================================\n";
        report << left << setw(20) << "Souvenir Name" << right << setw(15) << "Quantity"
            << right << setw(20) << "Price Each ($)"
            << right << setw(20) << "Total ($)" << endl;
        report << "----------------------------------------------------------------------------\n";
        report << left << setw(20) << souvenirName
            << right << setw(15) << quantity
            << right << setw(20) << fixed << setprecision(2) << pricePerItem
            << right << setw(20) << fixed << setprecision(2) << totalCost << endl;
        report.close();
        cout << "\nReport successfully saved to 'report.txt'.\n";
    }
    else {
        cout << "Error: Could not create report file.\n";
    }

    cout << "\nThank you for using Viktorija's Souvenir Tracker!\n";
    return 0;
}