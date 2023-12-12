#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    int addition = num1 + num2;
    int subtraction = num1 - num2;
    float division = num1 / num2;
    int multiplication = num1 * num2;
    int remainder = num1 % num2;
    cout << "Addition: " << addition << endl;
    cout << "Subtraction: " << subtraction << endl;
    cout << "Division: " << division << endl;
    cout << "Multiplication: " << multiplication << endl;
    cout << "Remainder: " << remainder << endl;

    return 0;
}
