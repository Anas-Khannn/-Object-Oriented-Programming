#include <iostream>

using namespace std; // Using the std namespace

int main() {
    int number;
    cout << "Enter a three-digit number: ";
    cin >> number;
    if (number >= 100 && number <= 999) {
        int digit1 = number % 10;        
        int digit2 = (number / 10) % 10; 
        int digit3 = number / 100;       
        cout << "Reverse order: " << digit1 << digit2 << digit3 << endl;
    } else {
        cout << "Please enter a valid three-digit number." << endl;
    }
    return 0;
}