#include <iostream>

#include <cmath>

const double PI = 3.14159;

class Circle {
  private: double radius;

  public:
    // Constructor
    Circle(double rad): radius(rad) {}

  // Member function to calculate the area
  double calculateArea() {
    return PI * pow(radius, 2);
  }

  // Member function to calculate the circumference
  double calculateCircumference() {
    return 2 * PI * radius;
  }
};

int main() {
  // Create a circle object
  double radius;
  std::cout << "Input the radius of the circle: ";
  std::cin >> radius;
  Circle circle(radius);

  // Calculate and display the area
  double area = circle.calculateArea();
  std::cout << "Area: " << area << std::endl;

  // Calculate and display the circumference
  double circumference = circle.calculateCircumference();
  std::cout << "Circumference: " << circumference << std::endl;

  return 0;
}
