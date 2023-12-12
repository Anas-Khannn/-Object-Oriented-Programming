#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "Enter your grade: ";
    cin >> grade;
    switch (grade) {
        case 'A':
            cout << "Excellent";
            break;
        case 'B':
            cout << "Very Good" ;
            break;
        case 'C':
            cout << "Good";
            break;
        case 'D':
            cout << "Poor" ;
            break;
        case 'F':
            cout << "Fail";
            break;
        default:
            cout << "Invalid grade. Please enter A, B, C, D, or F";
            break;
    }

    return 0;
}
