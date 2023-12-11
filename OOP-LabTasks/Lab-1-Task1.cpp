#include<iostream>
using namespace std;
class Exam
{
    int phy;
    int math;
    int che;

    public:
    Exam()
    {
        int phy=0;
        int math=0;
        int che=0;
    }
void setMarks(int x,int y,int z)
{
    phy=x;
    math=y;
    che=z;
}
void print()
{
    cout<<"Marks of Physics = "<<phy<<endl;
    cout<<"Marks of Maths = "<<math<<endl;
    cout<<"Marks of Chemistry = "<<che<<endl;
}
};
int main()
{
    Exam s1,s2;
    s2.setMarks(3,2,100);
    s1.setMarks(10,20,25);
    s1.print();
    s2.print();

}