#include <iostream>
using namespace std;

class Rectangle
{
    int length, width;

public:
    Rectangle(int l = 0, int w = 0) {}
    void set(int length, int width)
    {
        this->length = length;
        this->width = width;
    }
    friend int area(Rectangle a);
    void display()
    {
        cout << "The Area of rectangle is : " << area(*this);
    }
};
int area(Rectangle a)
{
    return a.length * a.width;
}
int main()
{
    Rectangle a;
    Rectangle b;
    a.set(6, 8);
    b = a;
    b.display();
}
