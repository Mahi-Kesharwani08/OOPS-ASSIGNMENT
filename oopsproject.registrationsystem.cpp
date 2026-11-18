#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// Structure to store participant details
struct Participant {
    int id;
    string name;
    string email;
    string eventName;
};

class EventRegistration {
private:
    vector<Participant> participants;
    unordered_set<string> registeredEmails;
    int nextID = 1001;

public:

    // Register a new participant
    void registerParticipant() { // CREATE A FUNCTION
        Participant p;    // OBJECT  

        cout << "\nEnter Participant Name: ";
        getline(cin, p.name);

        cout << "Enter Email: ";
        getline(cin, p.email);

        // Check duplicate email
        if (registeredEmails.find(p.email) != registeredEmails.end()) {
            cout << "\nEmail already registered!\n";
            return;
        }

        cout << "Enter Event Name: ";
        getline(cin, p.eventName);

        p.id = nextID++;

        participants.push_back(p);
        registeredEmails.insert(p.email);

        cout << "\nRegistration Successful!\n";
        cout << "Your Registration ID: " << p.id << endl;
    }

    // Display all participants
    void displayParticipants() {
        if (participants.empty()) {
            cout << "\nNo registrations found.\n";
            return;
        }

        cout << "\n------ REGISTERED PARTICIPANTS ------\n";

        for (const Participant& p : participants) {
            cout << "\nRegistration ID: " << p.id;
            cout << "\nName: " << p.name;
            cout << "\nEmail: " << p.email;
            cout << "\nEvent: " << p.eventName << endl;
        }
    }

    // Search participant using linear search
    void searchParticipant() {
        int searchID;
        cout << "\nEnter Registration ID: ";
        cin >> searchID;
        cin.ignore();

        bool found = false;

        for (const Participant& p : participants) {
            if (p.id == searchID) {
                cout << "\nParticipant Found!\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Email: " << p.email << endl;
                cout << "Event: " << p.eventName << endl;

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nParticipant Not Found!\n";
        }
    }
};

int main() {
    EventRegistration system;
    int choice;

    do {
        cout << "\n========== EVENT REGISTRATION SYSTEM ==========\n";
        cout << "1. Register Participant\n";
        cout << "2. Display All Participants\n";
        cout << "3. Search Participant\n";
        cout << "0. Exit\n";

        cout << "\nEnter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore();

        switch (choice) {
            case 1:
                system.registerParticipant();
                break;

            case 2:
                system.displayParticipants();
                break;

            case 3:
                system.searchParticipant();
                break;

            case 0:
                cout << "\nThank You for Using the System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}