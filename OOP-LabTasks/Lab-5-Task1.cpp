#include <iostream>
using namespace std;
class Account
{
private:
    string name;
    int balance;

public:
    int deposit_amount(int amount)
    {
        cout << "Updated Balance" << balance + amount;
        this->balance=balance+amount;
    }
    void withdraw_amount(int amount)
    {
        cout << "Enter withdraw amount";
        cin >> amount;
        if (amount <= balance)
        {
           this-> balance -= amount;
            cout << "balance" << this-> balance;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void setname(string name)
    {
        this->name = name;
    }
    void setbalance(int balance)
    {
        this->balance = balance;
       // cout << "balance :" << this-> balance;
    }
    int getbalance(int balance)
    {
        return balance;
    }
    void print()
    {
        cout<<"Balance = "<<balance<<endl;
        cout<<"Name = "<<name<<endl;
    }
};

Account create_account()
{
    Account obj;
    obj.setbalance(500);
    obj.setname("Saif");
    return obj;
}

int main()
{
    int choice, amount;
    Account r=create_account();
    
    while(choice!=4)
    {
        cout << "\n1:Display Balance" << endl;
        cout << "2:Deposit amount" << endl;
        cout << "3:withdraw amount" << endl;
        cout << "4:exit" << endl;
        cout << "Press : ";
        cin >> choice;

    
    if (choice == 1)
    {
      r.print();
    }
    else if (choice == 2)
    {
        cout << "How much amount you want to deposit :";
        cin >> amount;
        r.deposit_amount(amount);
    }

    else if (choice == 3)
    {
          cout << "Enter withdraw amount";
          cin >> amount;
        r.withdraw_amount(amount);
    }
    }
}
