#include <iostream>

using namespace std;


class Complex {

    double real;
    double imag;

public:

    Complex() : real(0), imag(0) {

    }

    Complex(double real, double imag) : real(real), imag(imag) {

    }

    Complex(const Complex& obj) {
        real = obj.real;
        imag = obj.imag;
    }


    Complex operator + (Complex& obj) {
        Complex temp;

        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;

        return temp;
    }

    Complex operator - (Complex& obj) {
        Complex temp;

        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;

        return temp;
    }

    Complex operator*(Complex& obj) {
        Complex temp;

        temp.real = real * obj.real - imag * obj.imag;
        temp.imag = real * obj.imag + imag * obj.real;

        return temp;
    }

    Complex operator / (Complex& obj) {
        Complex temp;

        temp.real = real / obj.real - imag / obj.imag;
        temp.imag = real / obj.imag + imag / obj.real;

        return temp;
    }

    friend ostream& operator<<(ostream& out, const Complex& obj);

};

ostream& operator<<(std::ostream& out, const Complex& obj) {
    out << obj.real << " + " << obj.imag << "i";
    return out;
}



int main()
{


    Complex c1(2, 3);
    Complex c2(1, 4);

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / c2 << endl;

    return 0;

}

