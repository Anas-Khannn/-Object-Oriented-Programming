#include <iostream>

using namespace std;

int main() {
  int num1, num2;
  cout << "Enter the first number: ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;
  num1 = num1 ^ num2;
  num2 = num1 ^ num2;
  num1 = num1 ^ num2;
  cout << "The first number after swapping: " << num1 << endl;
  cout << "The second number after swapping: " << num2 << endl;

  return 0;
}
