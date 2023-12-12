#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal constructor Called" << endl;
    }

    int age;
    void walk()
    {
        cout << "Animal started Walking at the age of 10 ohoo" << endl;
    }
};

class Tiger :virtual public Animal
{
public:
    Tiger()
    {
        cout << "Tiger constructor Called" << endl;
    }
};

class Lion:virtual public Animal
{
public:
    Lion()
    {
        cout << "Lion constructor Called" << endl;
    }
};

class liger :public Tiger, public Lion
{
public:
    liger()
    {
        cout << "Liger constructor Called" << endl;
    }
};

int main()
{
    liger object;
    object.walk();

    return 0;
}
