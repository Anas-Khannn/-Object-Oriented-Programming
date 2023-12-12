#include<iostream>
using namespace std;
class Animal{
    public:
        string name;
        int age;
        Animal(string name,int age){
            this->name;
            this->age;
        }
        void speak(){}

};
class Bird:Animal{
    int wingLength;
    public:
    Bird(string name,int age):Animal(name,age){
        this->name=name;
        this->age=age;
    }
    void speak(){
        cout<<"My name is : "<<name<<" My age is : "<<age<<endl;
        cout<<"I am a bird and i can sing."<<endl;
    }

};
class Reptile:Animal{
    string habitat;
    public:
        Reptile(string name,int age):Animal(name,age){
            this->name=name;
            this->age=age;
        }
    void speak(){
        cout<<"My name is : "<<name<<" My age is : "<<age<<endl;
        cout<<"I am a reptile and i can creep!"<<endl;
    }

};
int main(){
    Bird b("Parrot",2);
    Reptile r("Crocodile",5);
    b.speak();
    r.speak();
}