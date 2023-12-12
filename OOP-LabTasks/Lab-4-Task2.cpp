#include <iostream>
using namespace std;

int main() {
    float First_num, second_num;
    float result;
    char operation;
    cout << "Enter First Number:\t";
    cin >> First_num;
    cout << "Enter second Number:\t";
    cin >> second_num;
    cout << "Enter the operator (+, -, /, *):";
    cin >> operation;
    switch (operation) {
        case '+':
            result = First_num + second_num;
            cout << First_num << "+" << second_num << "=" << result;
            break;
        case '-':
            result = First_num - second_num;
            cout << First_num << "-" << second_num << "=" << result;
            break;
        case '/':
                result = First_num / second_num;
                cout << First_num << "/" << second_num << "=" << result;
               break;
        case '*':
            result = First_num * second_num;
            cout << First_num << "*" << second_num << "=" << result;
            break;
        default:
            cout << "You entered an invalid operator";
    }
    return 0;
}
