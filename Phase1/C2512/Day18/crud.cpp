#include <iostream>
#include <iomanip>
using namespace std;

// *****Const.h*****
// Constants
const int MAX_SURGERIES = 100;

// *****Surgery.h*****
class Surgery {
    friend class SurgeryManager;
    private:
        string SurgeryID;
        int Duration; // Duration in minutes
    public:
        bool GreaterThan(const Surgery& other);
        bool LessThan(const Surgery& other);
        // Getters and setters
        string GetSurgeryID();
        int GetDuration();
};

// *****SurgeryManager.h*****
class SurgeryManager {
    friend class SurgeryAggregator;
    friend int main();
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

// *****SurgeryAggregator.h*****
class SurgeryAggregator {
    public:
        int findMin(SurgeryManager& manager);
        int findMax(SurgeryManager& manager);
        int findSecondMin(SurgeryManager& manager);
        int findSecondMax(SurgeryManager& manager);
};

// *****Menu.h*****
void printMenu();

// *****Main.cpp*****
int main() {
    SurgeryManager manager;
    SurgeryAggregator aggregator;
    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
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
                     << " with Duration "
                     << manager.surgeries[aggregator.findMin(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 6:
                cout << "Surgery with Max Duration: "
                     << manager.surgeries[aggregator.findMax(manager)].GetSurgeryID()
                     << " with Duration "
                     << manager.surgeries[aggregator.findMax(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 7:
                cout << "Surgery with 2nd Min Duration: "
                     << manager.surgeries[aggregator.findSecondMin(manager)].GetSurgeryID()
                     << " with Duration "
                     << manager.surgeries[aggregator.findSecondMin(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 8:
                cout << "Surgery with 2nd Max Duration: "
                     << manager.surgeries[aggregator.findSecondMax(manager)].GetSurgeryID()
                     << " with Duration "
                     << manager.surgeries[aggregator.findSecondMax(manager)].GetDuration()
                     << " minutes\n";
                break;
            case 9:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
    } while (choice != 9);

    return 0;
}

// *****SurgeryManager.cpp*****
SurgeryManager::SurgeryManager() {
    numSurgeries = 0;
}

int SurgeryManager::findIndexById(string SurgeryID) {
    for (int i = 0; i < numSurgeries; i++) {
        if (surgeries[i].SurgeryID == SurgeryID) {
            return i;
        }
    }
    return -1;
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
// *****Menu.cpp*****
void printMenu() {
    cout << "\n=== Surgery Management System ===\n";
    cout << "1. Create Surgery\n";
    cout << "2. Display All Surgeries\n";
    cout << "3. Edit Surgery\n";
    cout << "4. Delete Surgery\n";
    cout << "5. Find Min Duration Surgery\n";
    cout << "6. Find Max Duration Surgery\n";
    cout << "7. Find Second Min Duration Surgery\n";
    cout << "8. Find Second Max Duration Surgery\n";
    cout << "9. Exit\n";
}

// *****Surgery.cpp*****
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

// *****SurgeryAggregator.cpp*****
int SurgeryAggregator::findMin(SurgeryManager& manager) {
    int minIndex = 0;
    for (int i = 1; i < manager.numSurgeries; i++) {
        if (manager.surgeries[i].LessThan(manager.surgeries[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

int SurgeryAggregator::findMax(SurgeryManager& manager) {
    int maxIndex = 0;
    for (int i = 1; i < manager.numSurgeries; i++) {
        if (manager.surgeries[i].GreaterThan(manager.surgeries[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int SurgeryAggregator::findSecondMin(SurgeryManager& manager) {
    int minIndex = findMin(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < manager.numSurgeries; i++) {
        if (i != minIndex && manager.surgeries[i].LessThan(manager.surgeries[secondMinIndex])) {
            secondMinIndex = i;
        }
    }
    return secondMinIndex;
}

int SurgeryAggregator::findSecondMax(SurgeryManager& manager) {
    int maxIndex = findMax(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < manager.numSurgeries; i++) {
        if (i != maxIndex && manager.surgeries[i].GreaterThan(manager.surgeries[secondMaxIndex])) {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;
}


