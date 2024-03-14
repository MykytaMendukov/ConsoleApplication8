#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Fraction {

    float num;
    float denom;

public:

    float fraction = num / denom;

    Fraction(float num_, float denom_) : num{ num_ }, denom{ denom_ } {

    }

    Fraction() : fraction(1) {

    }

    Fraction(const Fraction& fr) {
        num = fr.num;
        denom = fr.denom;
        fraction = fr.fraction;
    }

    Fraction operator + (Fraction& fr) {
        Fraction temp;

        temp.fraction = fraction - fr.fraction;
        cout << num << "/" << denom << " + " << fr.num << "/" << fr.denom << " = " << temp.fraction << endl;

        return temp;
    }

    Fraction operator - (Fraction& fr) {
        Fraction temp;

        temp.fraction = fraction - fr.fraction;
        cout << num << "/" << denom << " - " << fr.num << "/" << fr.denom << " = " << temp.fraction << endl;

        return temp;
    }

    Fraction operator * (Fraction& fr) {
        Fraction temp;

        temp.fraction = fraction * fr.fraction;
        cout << num << "/" << denom << " * " << fr.num << "/" << fr.denom << " = " << temp.fraction << endl;

        return temp;
    }

    Fraction operator / (Fraction& fr) {
        Fraction temp;

        temp.fraction = fraction / fr.fraction;
        cout << num << "/" << denom << " / " << fr.num << "/" << fr.denom << " = " << temp.fraction << endl;

        return temp;
    }

};

#include <iostream>

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

    Fraction fraction1(3, 4);
    Fraction fraction2(4, 3);

    fraction1 + fraction2;
    fraction1 - fraction2;
    fraction1* fraction2;
    fraction1 / fraction2;


    Complex c1(2, 3);
    Complex c2(1, 4);

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / c2 << endl;

    return 0;

}

