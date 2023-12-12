#include <iostream>
using namespace std;

int main() {
    int salary, amount ,deduction;
    cout << "Enter your salary: ";
    cin >> salary;
    if (salary < 10000) {
        deduction = 0;
    } else if (salary >= 10000 && salary < 20000) {
        deduction = 1000;
    } else {
        deduction = 0.07 * salary;
    }
    amount = salary - deduction;
    cout << "Deduction: Rs." << deduction << endl;
    cout << "Net Payable Amount: Rs." << amount;

    return 0;
}
