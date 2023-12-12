#include<iostream>
using namespace std;

// creating a class
class complex{
  private:
    int real, img;
  public:
     complex(){
        real = 0;
        img = 0;
     }
    complex(int real, int img){
        this->real = real;
        this->img = img;
     }
    friend complex addComplex(complex Number1, complex Number2);

    void display(){
        cout<<" "<<real<<" + "<<img<<"i"<<endl;
    }
};
  complex addComplex(complex Number1, complex Number2){
       complex Number3;
       Number3.real = Number1.real + Number2.real;
       Number3.img = Number1.img + Number2.img;
       return Number3;
 }
int main(){
  complex c1(3,4);
  complex c2(1,2);
  
  complex c3 = addComplex(c1, c2);
  c3.display();
}