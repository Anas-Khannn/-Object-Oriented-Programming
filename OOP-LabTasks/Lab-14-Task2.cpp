#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}
    void display()
    {
        cout << real << "+" << imag << "i" << endl;
    }
    int getReal()
    {
        return real;
    }
    int getImag()
    {
        return imag;
    }
};

class Operations
{
public:
    static Complex addComplex(Complex Number1, Complex Number2)
    {
        int realSum = Number1.getReal() + Number2.getReal();
        int imaginarySum = Number1.getImag() + Number2.getImag();
        return Complex(realSum, imaginarySum);
    }
    static Complex subtractComplex(Complex c1, Complex c2)
    {
        int realDiff = c1.getReal() - c2.getReal();
        int imagDiff = c1.getImag() - c2.getImag();
        return Complex(realDiff, imagDiff);
    }
};

int main()
{
    Complex num1(3, 4);
    Complex num2(1, -2);
    Complex sum = Operations::addComplex(num1, num2);
    Complex difference = Operations::subtractComplex(num1, num2);
    cout << "Sum: ";
    sum.display();
    cout << "Difference: ";
    difference.display();
    return 0;
}
