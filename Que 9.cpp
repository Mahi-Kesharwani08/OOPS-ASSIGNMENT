#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
    T arr[10];
    int top;
public:
    Stack() { top = -1; }

    void push(T value) {
        if (top == 9)
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = value;
    }

    void display() {
        if (top == -1) {
            cout << "(empty)" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    // Integer stack
    cout << "Integer Stack: ";
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();

    // Float stack
    cout << "Float Stack: ";
    Stack<float> s2;
    s2.push(1.5f);
    s2.push(2.5f);
    s2.push(3.5f);
    s2.display();

    // String stack
    cout << "String Stack: ";
    Stack<string> s3;
    s3.push("Apple");
    s3.push("Banana");
    s3.push("Cherry");
    s3.display();

    return 0;
}