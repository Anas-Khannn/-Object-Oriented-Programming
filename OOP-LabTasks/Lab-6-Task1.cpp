#include<iostream>
using namespace std;
class Invoice
{
private:
    string number;
    string description;
    int quantity;
    int price;

public:
    Invoice(string number=" ",string description="not enter",int quantity=0,int price=0)
    {
    this->number=number;
    this->description=description;
    this->quantity=quantity;
    this->price=price;
    }
    void setnumber(string number){
        this->number=number;
    }
    void setdescription(string number){
        this->description=description;
    }
    void setquantity(int number){
        this->quantity=quantity;
    }

    void setprice(int number){
        this->price=price;
    }
    string getnumber() { return number; }
    string getdescription() { return description; }
    int getquantity() { return quantity; }
    int getprice() { return price; }
    int getInvoiceAmount(){
        if (quantity==0)
        {
            this->quantity=0;
            return quantity;
        }
        
        else if (price==0)
        {
            this->price=0;
            return price;
        }
        else
        return quantity * price;
    }   

};
int main()
{
    Invoice obj("1234","ALi",43,23);
    cout << "Part Number: " << obj.getnumber() <<endl;
    cout << "Part Description: " << obj.getdescription() << endl;
    cout << "Quantity: " << obj.getquantity() << std::endl;
    cout << "Price Per Item: " << obj.getprice()<< endl;
    cout << "Invoice Amount: " << obj.getInvoiceAmount() << endl;

    return 0;
}




