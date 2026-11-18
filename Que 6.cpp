#include <iostream>
using namespace std;

class Person {
protected:
    char name[50];
    int age;
public:
    void setPerson() {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollNo;
    char course[30];
public:
    void setStudent() {
        setPerson();
        cout << "Enter roll no: ";
        cin >> rollNo;
        cout << "Enter course : ";
        cin >> course;
    }
    void displayStudent() {
        displayPerson();
        cout << "Roll No: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

class GraduateStudent : public Student {
    char thesis[50];
    char supervisor[30];
public:
    void setGraduate() {
        setStudent();
        cout << "Enter thesis topic: ";
        cin >> thesis;
        cout << "Enter supervisor name : ";
        cin >> supervisor;
    }
    void displayGraduate() {
        displayStudent();
        cout << "Thesis Topic: " << thesis << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
};

int main() {
    int choice;

    do {
        cout << "\n===== University Management =====" << endl;
        cout << "1. Single Inheritance (Person -> Student)" << endl;
        cout << "2. Multilevel Inheritance (Person -> Student -> GraduateStudent)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.setStudent();
            cout << "\n--- Student Details ---" << endl;
            s.displayStudent();
        }
        else if (choice == 2) {
            GraduateStudent g;
            g.setGraduate();
            cout << "\n--- Graduate Student Details ---" << endl;
            g.displayGraduate();
        }
        else if (choice == 3) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}