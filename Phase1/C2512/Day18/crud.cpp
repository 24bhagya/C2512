#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SURGERIES = 100;

class Surgery {
    friend class SurgeryManager;
private:
    string SurgeryID;
    int Duration; // Duration in minutes

public:
    bool GreaterThan(const Surgery& other);
    bool LessThan(const Surgery& other);

    // Getters and Setters
    string GetSurgeryID();
    int GetDuration();
};

class SurgeryManager {
private:
    Surgery surgeries[MAX_SURGERIES];
    int numSurgeries;

public:
    int findIndexById(string SurgeryID);

    void create();
    void displayAll();
    void editById();
    void deleteById();

    SurgeryManager();
};

class SurgeryAggregator {
public:
    int findMin(SurgeryManager& manager);
    int findMax(SurgeryManager& manager);
};

void printSurgeryMenu();

int main() {
    SurgeryManager manager;
    SurgeryAggregator aggregator;

    int choice;

    do {
        printSurgeryMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.create(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.editById(); break;
            case 4: manager.deleteById(); break;
            case 5:
                cout << "Surgery with Min Duration: "
                     << manager.surgeries[aggregator.findMin(manager)].GetSurgeryID()
                     << " with Duration: "
                     << manager.surgeries[aggregator.findMin(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 6:
                cout << "Surgery with Max Duration: "
                     << manager.surgeries[aggregator.findMax(manager)].GetSurgeryID()
                     << " with Duration: "
                     << manager.surgeries[aggregator.findMax(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 7:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}

void SurgeryManager::create() {
    if (numSurgeries >= MAX_SURGERIES) {
        cout << "Error: Maximum surgery limit reached.\n";
        return;
    }

    string SurgeryID;
    int Duration;

    cout << "Enter Surgery ID: ";
    cin >> SurgeryID;

    if (findIndexById(SurgeryID) != -1) {
        cout << "Error: Surgery ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Duration (in minutes): ";
    cin >> Duration;

    surgeries[numSurgeries].SurgeryID = SurgeryID;
    surgeries[numSurgeries].Duration = Duration;
    numSurgeries++;

    cout << "Surgery added successfully.\n";
}

void SurgeryManager::displayAll() {
    if (numSurgeries == 0) {
        cout << "No surgeries available to display.\n";
        return;
    }

    cout << "-----------------------------------------\n";
    cout << "|   Surgery ID   | Duration (minutes)   |\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < numSurgeries; i++) {
        cout << "| " << setw(14) << surgeries[i].SurgeryID << " | "
             << setw(20) << surgeries[i].Duration << " |\n";
    }
    cout << "-----------------------------------------\n";
}

int SurgeryManager::findIndexById(string SurgeryID) {
    for (int i = 0; i < numSurgeries; i++) {
        if (surgeries[i].SurgeryID == SurgeryID) {
            return i;
        }
    }
    return -1;
}

void SurgeryManager::editById() {
    string SurgeryID;
    cout << "Enter Surgery ID to edit: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) {
        cout << "Error: Surgery ID not found.\n";
        return;
    }

    cout << "Current Duration: " << surgeries[index].Duration << " minutes\n";

    cout << "Enter New Duration (in minutes): ";
    cin >> surgeries[index].Duration;

    cout << "Surgery updated successfully.\n";
}

void SurgeryManager::deleteById() {
    string SurgeryID;
    cout << "Enter Surgery ID to delete: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) {
        cout << "Error: Surgery ID not found.\n";
        return;
    }

    for (int i = index; i < numSurgeries - 1; i++) {
        surgeries[i] = surgeries[i + 1];
    }
    numSurgeries--;

    cout << "Surgery deleted successfully.\n";
}

SurgeryManager::SurgeryManager() {
    numSurgeries = 0;
}

bool Surgery::GreaterThan(const Surgery& other) {
    return (Duration > other.Duration);
}

bool Surgery::LessThan(const Surgery& other) {
    return (Duration < other.Duration);
}

string Surgery::GetSurgeryID() {
    return SurgeryID;
}

int Surgery::GetDuration() {
    return Duration;
}

int SurgeryAggregator::findMin(SurgeryManager& manager) {
    Surgery* arr = manager.surgeries;
    int& n = manager.numSurgeries;
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

int SurgeryAggregator::findMax(SurgeryManager& manager) {
    Surgery* arr = manager.surgeries;
    int& n = manager.numSurgeries;
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void printSurgeryMenu() {
    cout << "\n=== Surgery Management System ===\n";
    cout << "1. Add Surgery\n";
    cout << "2. Display All Surgeries\n";
    cout << "3. Edit Surgery by ID\n";
    cout << "4. Delete Surgery by ID\n";
    cout << "5. Find Surgery with Minimum Duration\n";
    cout << "6. Find Surgery with Maximum Duration\n";
    cout << "7. Exit\n";
}
