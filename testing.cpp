#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Public getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }

};

// Overloading the << operator
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImag() << "i";
    return os;
}

int main() {
    Complex c1(3.5, 2.5);

    cout << "does this work?\n\n";

    cout << "Complex number c1: " << c1 << "\n\n\n";
    return 0;
}
