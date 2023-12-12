#include<iostream>
using namespace std;
class Distance{
    int meter;
    friend int addFive(Distance);

    public:
    Distance() : meter(0){};

};

int addFive(Distance d){
    d.meter+=5;
    return d.meter;

}

int main()
{
    Distance d;
    cout<<"The value of Meter with friend function is :"<<addFive(d)<<endl;
}
