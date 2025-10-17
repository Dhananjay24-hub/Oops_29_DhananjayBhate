#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Operator Overloading
    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    Complex operator - (const Complex& obj) {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }

    Complex operator * (const Complex& obj) {
        Complex temp;
        temp.real = (real * obj.real) - (imag * obj.imag);
        temp.imag = (real * obj.imag) + (imag * obj.real);
        return temp;
    }

    Complex operator / (const Complex& obj) {
        Complex temp;
        float denom = (obj.real * obj.real) + (obj.imag * obj.imag);
        temp.real = ((real * obj.real) + (imag * obj.imag)) / denom;
        temp.imag = ((imag * obj.real) - (real * obj.imag)) / denom;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i";
    }
};

int main() {
    Complex c1(4, 3), c2(2, 1), result;

    cout << "First Complex Number: ";
    c1.display();
    cout << "\nSecond Complex Number: ";
    c2.display();

    result = c1 + c2;
    cout << "\n\nAddition: ";
    result.display();

    result = c1 - c2;
    cout << "\nSubtraction: ";
    result.display();

    result = c1 * c2;
    cout << "\nMultiplication: ";
    result.display();

    result = c1 / c2;
    cout << "\nDivision: ";
    result.display();

    cout << endl;
    return 0;
}