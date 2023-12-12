#include <iostream>
using namespace std;
class person
{
private:
    string name;
    int age;

public:
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    void display_info()
    {
    }
};
class student : public person
{
    float gpa;

public:
    student(string name, int age, float gpa) : person(name, age)
    {
        this->gpa = gpa;
    }
    void display_info()
    {
        cout << "student name : " << getName() << endl
             << "student age : " << getAge() << endl
             << "student Gpa : " << gpa << endl;
    }
};
class Employy : public person
{
    int salary;

public:
    Employy(string name, int age, int salary) : person(name, age)
    {
        this->salary = salary;
    }
    void display_info()
    {
        cout << "Employy name : " << getName() << endl
             << "employy age : " << getAge() << endl
             << "employy salary : " << salary << endl;
    }
};
int main()
{
    student s1("saif", 32, 3.3);
    Employy e1("soahaib", 45, 10000);
    s1.display_info();
    e1.display_info();
}