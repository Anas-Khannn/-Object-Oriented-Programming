#include<iostream>
using namespace std;
int main()
{
    float First_num,second_num;
    float result;
    char operation;
 cout<<"Enter First Number:\t";
 cin>>First_num;
 cout<<"Enter second Number:\t";
 cin>>second_num;   
 cout<<"Enter the operator (+,-,/,*):";
 cin>>operation;
 if (operation=='+')
 {
   result= First_num+second_num;
   cout<<First_num<< "+" <<second_num<< "=" <<result;
 }
 else if (operation=='-')
 {
      result= First_num-second_num;
   cout<<First_num<< "-" <<second_num<< "=" <<result;
 }
 else if (operation=='/')
 {
    if(second_num!=0){
     result= First_num / second_num;
    cout<<First_num<< "/" <<second_num<< "=" <<result;}
   else cout<<"divison with 0 is not possible";
 }
 else if (operation=='*')
 {
    result= First_num * second_num;
   cout<<First_num<< "*" <<second_num<< "=" <<result;
 }
 else
 cout<<"Invalid Operator";
 return 0;
 
}