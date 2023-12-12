#include <iostream>
#include <string>
using namespace std;
class Shape
{
public:
void draw()
{
cout<<"Drawing shape"<<endl;
}
};
class Rectangle
{
int length, width;
public:
void draw()
{
cout<<"Drawing rectangle"<<endl;
}

};
class Circle: public Shape
{
int radius;
public:
void draw()
{
cout<<"Drawing Circle"<<endl;
}

};
int main()
{
Shape *s=new Circle();
s->draw();
}