#include <iostream>
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

    T pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return T();
        }
        return arr[top--];
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

// Helper that does all three steps for any type
template <class T>
void test(Stack<T> &s) {
    cout << "Stack elements    : ";
    s.display();

    cout << "Popped element    : " << s.pop() << endl;

    cout << "Remaining elements: ";
    s.display();
}

int main() {
    cout << "===== Int Stack =====" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    test(s1);

    cout << "\n===== Float Stack =====" << endl;
    Stack<float> s2;
    s2.push(1.5f);
    s2.push(2.5f);
    s2.push(3.5f);
    test(s2);

    cout << "\n===== String Stack =====" << endl;
    Stack<const char*> s3;
    s3.push("Apple");
    s3.push("Banana");
    s3.push("Cherry");
    test(s3);

    return 0;
}