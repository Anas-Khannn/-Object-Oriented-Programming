#include <iostream>
using namespace std;

    int main()
    {
        const double pi=3.14;
    	int radius;
    	float Vol_of_Sphere;	
        cout<<"Enter the radius of a sphere : ";
    	cin>>radius;
    	Vol_of_Sphere=(4*pi*radius*radius*radius)/3;
        cout<<" The volume of a sphere is : "<< Vol_of_Sphere << endl;
        return 0;
    }