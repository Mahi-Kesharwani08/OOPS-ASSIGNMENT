#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int roll;
    string name;

    void getData() {
        cout << "Enter Roll no and name: ";
        cin >> roll >> name;
    }

    void display() {
        cout << "Rollno: " << roll << " Name: " << name << endl;
    }
};

int main() {
    // Array to store details for 2 students
    Student stu[2];

    // Input details
    for (int i = 0; i < 2; i++) {
        cout << "\nFor Student " << (i + 1) << ":" << endl;
        stu[i].getData();
    }

    // Display details
    cout << "\n--- Student Details ---" << endl;
    for (int i = 0; i < 2; i++) {
        stu[i].display();
    }

    return 0;
}