#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex() { real = 0; imag = 0; }
    Complex(double r, double i) { real = r; imag = i; }

    // ---------- Function overloading ----------
    // same function name "add", different parameters
    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex add(double n) {
        return Complex(real + n, imag);
    }
    Complex add(double r, double i) {
        return Complex(real + r, imag + i);
    }

    // ---------- Operator overloading ----------
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(Complex c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2), c2(1, 4), result;

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();

    cout << "\n--- Function Overloading ---" << endl;
    result = c1.add(c2);        // add(Complex)
    cout << "add(Complex): "; result.display();

    result = c1.add(5);         // add(double)
    cout << "add(double): "; result.display();

    result = c1.add(2, 3);      // add(double, double)
    cout << "add(double, double): "; result.display();

    cout << "\n--- Operator Overloading ---" << endl;
    result = c1 + c2;
    cout << "c1 + c2 = "; result.display();

    result = c1 - c2;
    cout << "c1 - c2 = "; result.display();

    result = c1 * c2;
    cout << "c1 * c2 = "; result.display();

    return 0;
}