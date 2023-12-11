#include <iostream>
using namespace std;

//class
class Currency
{
    long pounds;
    int shellings; 
    int pence;

public:
           // constructor 
    Currency()
    {
    }
    Currency(long pounds, int shellings, int pence)
    {
        this->pounds = pounds;
        this->shellings = shellings;
        this->pence = pence;
    }

    // getter and setters

    long getpounds()
    {
        return pounds;
    }

    int getshellings()
    {
        return shellings; 
    }

    int getpence()
    {
        return pence;
    }

    float getSterling()
    {
        float conversionIntoDecimal = (0.833 * pence) + shellings / 2.0;
        return pounds + conversionIntoDecimal;
    }

    void Display()
    {
        cout << "The Value in the Old System Was: " << getpounds() << " " << getshellings() << " " << getpence() << endl;
        cout << "The Converted and the New Value in the New System is: " << getSterling() << endl;
    }
};

int main()
{ 
    // class object
    Currency Object(5, 2, 8);
    Object.Display();

    return 0;
}
