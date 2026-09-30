#include <iostream>
#include <fstream>
using namespace std;

const int TOTAL_SLOTS = 10;          // Total parking slots
bool slots[TOTAL_SLOTS] = {false};  // false = Empty, true = Occupied

// Function to display parking slots
void showSlots() {
    cout << endl << "--- Parking Slots Status ---" << endl;
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        cout << "Slot " << i + 1 << ": ";
        if (slots[i])
            cout << "Occupied" << endl;
        else
            cout << "Empty" << endl;
    }
}

// Function to park a car
void parkCar() {
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (!slots[i]) {
            slots[i] = true;
            cout << endl << "Car parked at Slot " << i + 1 << endl;

            ofstream file("parking_log.txt", ios::app);
            file << "Car Parked at Slot " << i + 1 << endl;
            file.close();
            return;
        }
    }
    cout << endl << "No empty slots available!" << endl;
}

// Function to remove a car
void removeCar() {
    int slot;
    cout << endl << "Enter slot number: ";
    cin >> slot;

    if (slot < 1 || slot > TOTAL_SLOTS) {
        cout << "Invalid slot number!" << endl;
        return;
    }

    if (!slots[slot - 1]) {
        cout << "Slot is already empty!" << endl;
        return;
    }

    slots[slot - 1] = false;
    cout << "Car removed from Slot " << slot << endl;

    int bill = 50;
    cout << "Parking Charges: Rs. " << bill << endl;

    ofstream file("parking_log.txt", ios::app);
    file << "Car Removed from Slot " << slot << " | Bill: Rs. " << bill << endl;
    file.close();
}

int main() {
    int choice;

    while (true) {
        cout << endl << "===== SMART PARKING SYSTEM =====" << endl;
        cout << "1. Show Parking Slots" << endl;
        cout << "2. Park a Car" << endl;
        cout << "3. Remove a Car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            showSlots();
        else if (choice == 2)
            parkCar();
        else if (choice == 3)
            removeCar();
        else if (choice == 4) {
            cout << "Thank you! Exiting..." << endl;
            break;
        }
        else
            cout << "Invalid choice! Try again." << endl;
    }
    return 0;
}