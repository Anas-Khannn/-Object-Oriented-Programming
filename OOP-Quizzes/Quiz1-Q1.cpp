#include <iostream>
#include <math.h>
using namespace std;
struct Distance
{
    float x;
    float y;
};
double cal_Distance(Distance point1, Distance point2)
{
    return sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}
void displayDistance(float distance)
{
    cout << "The distance is : " << distance << endl;
}
int main()
{
    Distance point1, point2;
    float distance;
    cout << "Enter the x1: ";
    cin >> point1.x;
    cout << "Enter the y1: ";
    cin >> point1.y;
    cout << "Enter the x2: ";
    cin >> point2.x;
    cout << "Enter the y2: ";
    cin >> point2.y;
    distance = cal_Distance(point1, point2);
    displayDistance(distance);

    return 0;
}
