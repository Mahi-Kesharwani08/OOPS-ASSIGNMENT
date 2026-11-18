#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

// Helper functions used by the algorithms
bool byMarksDesc(Student a, Student b) { return a.marks > b.marks; }
bool above80(Student s) { return s.marks > 80; }
Student addBonus(Student s) { s.marks = s.marks + 5; return s; }

void show(vector<Student> &v) {
    for (Student s : v)
        cout << s.name << " : " << s.marks << endl;
}

int main() {
    // vector holds the data set
    vector<Student> students;
    students.push_back({"Rahul", 78});
    students.push_back({"Priya", 92});
    students.push_back({"Amit", 45});
    students.push_back({"Sneha", 67});
    students.push_back({"Karan", 88});

    // 1. Student dataset
    cout << "--- Student Dataset ---" << endl;
    show(students);

    // 2. Students sorted by marks (on a copy, so the original stays unchanged)
    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), byMarksDesc);
    cout << "\n--- Students Sorted by Marks ---" << endl;
    show(sorted);

    // 3. Students with marks above 80 (copy_if)
    vector<Student> topStudents;
    copy_if(students.begin(), students.end(), back_inserter(topStudents), above80);
    cout << "\n--- Students with Marks Above 80 ---" << endl;
    show(topStudents);

    // 4. Records using map (keys kept sorted by name)
    map<string, int> m;
    for (Student s : students)
        m[s.name] = s.marks;
    cout << "\n--- Records Using Map ---" << endl;
    for (auto p : m)
        cout << p.first << " : " << p.second << endl;

    // 5. Records using unordered_map (order not guaranteed)
    unordered_map<string, int> um;
    for (Student s : students)
        um[s.name] = s.marks;
    cout << "\n--- Records Using Unordered Map ---" << endl;
    for (auto p : um)
        cout << p.first << " : " << p.second << endl;

    // 6. Marks after adding 5 bonus marks (transform)
    transform(students.begin(), students.end(), students.begin(), addBonus);
    cout << "\n--- Marks After Adding 5 Bonus Marks ---" << endl;
    show(students);

    return 0;
}