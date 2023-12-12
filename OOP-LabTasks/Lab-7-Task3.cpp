#include <iostream>
#include <math.h>

using namespace std;

struct Point {
  double x;
  double y;
};

double calculateDistance(Point p1, Point p2) {
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void displayDistance(double distance) {
  cout << "The distance between the two points is: " << distance << endl;
}

int main() {
  Point p1, p2;

  cout << "Enter the coordinates of the first point: ";
  cin >> p1.x >> p1.y;

  cout << "Enter the coordinates of the second point: ";
  cin >> p2.x >> p2.y;

  double distance = calculateDistance(p1, p2);

  displayDistance(distance);

  return 0;
}
