#include<iostream>
using namespace std;
 template<typename T>
bool  isEqualTo(T a,T b){
    bool ans=(a==b);
    if(ans==true){
        return true;
    }
    else    
        false;
}
int main(){
    cout<<isEqualTo(5,6)<<endl;
    cout<<isEqualTo(9.9,9.9)<<endl;
}
