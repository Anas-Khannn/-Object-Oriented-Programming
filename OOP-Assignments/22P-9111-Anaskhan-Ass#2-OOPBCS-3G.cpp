#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int AccountNumber;
    string AccountHolder;
    double Balance;

public:
    static int count;

    // Constructor
    BankAccount(int accNumber = 0, string accHolder = "N/A", double bal = 0)

    {
        AccountNumber = accNumber;
        AccountHolder = accHolder;
        Balance = bal;
        count++;
    }

    // Getter and setter functions
    int getAccountNumber() const
    {
        return AccountNumber;
    }

    string getAccountHolder() const
    {
        return AccountHolder;
    }

    double getBalance() const
    {
        return Balance;
    }

    void setAccountNumber(int accNumber)
    {
        AccountNumber = accNumber;
    }

    void setAccountHolder(string accHolder)
    {
        AccountHolder = accHolder;
    }

    void setBalance(double balance)
    {
        Balance = balance;
    }

    void depositAmount(double Amount)
    {
        Balance += Amount;
        cout << "Balance after deposit: " << Balance << endl;
    }

    void withdrawAmount(double Amount)
    {
        if (Amount <= Balance)
        {
            Balance -= Amount;
            cout << "Remaining balance after withdrawal: " << Balance << endl;
        }
        else
        {
            cout << "Insufficient funds: Your balance is low. Cannot withdraw." << endl;
        }
    }
};

int BankAccount::count = 0;

class BankManager
{
private:
    BankAccount *ptr;
    int Size;
    int capacity;

public:
    BankManager(int s)
    {
        ptr = new BankAccount[s];
        Size = 0;
        capacity = s;
    }

    ~BankManager()
    {
        delete[] ptr;
    }

    void deleteAccount(int Number)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (ptr[i].getAccountNumber() == Number)
            {
                for (int j = i; j < Size - 1; ++j)
                {
                    ptr[j] = ptr[j + 1];
                }
                Size--;
                cout << "Account " << Number << " deleted." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    BankAccount *findAccount(int Num)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (ptr[i].getAccountNumber() == Num)
            {
                return &ptr[i];
            }
        }
        return nullptr;
    }

    void displayAccounts()
    {
        if (Size == 0)
        {
            cout << "No accounts to print" << endl;
            return;
        }
        for (int i = 0; i < Size; i++)
        {
            cout << "Account Holder: " << ptr[i].getAccountHolder() << endl;
            cout << "Account Number: " << ptr[i].getAccountNumber() << endl;
            cout << "Balance: " << ptr[i].getBalance() << endl;
            cout << "------------------------" << endl;
        }
    }

    void AddAccount(const BankAccount &acc)
    {
        if (Size >= capacity)
        {
            cout << "No more space for accounts ..." << endl;
            return;
        }
        ptr[Size] = acc;
        Size++;
        cout << "Account created successfully." << endl;
    }
};

void createAccount(BankManager &manager)
{
    int accNumber;
    string accHolder;
    double balance;

    cout << "Enter account number: ";
    cin >> accNumber;

    cin.ignore();

    cout << "Enter account holder name: ";
    getline(cin, accHolder);

    cout << "Enter initial balance: ";
    cin >> balance;

    BankAccount newAccount(accNumber, accHolder, balance);

    manager.AddAccount(newAccount);
}

int main()
{
    int numAccounts;
    cout << "Enter the number of accounts: ";
    cin >> numAccounts;

    BankManager manager(numAccounts);

    while (true)
    {
        cout << "---------------------------------------------" << endl;
        cout << "Display menu" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Delete Account" << endl;
        cout << "3. Display Accounts" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount(manager);
            break;
        case 2:
        {
            int accNumber;
            cout << "Enter account number to delete: ";
            cin >> accNumber;
            manager.deleteAccount(accNumber);
            break;
        }
        case 3:
            manager.displayAccounts();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid input. Try again." << endl;
            break;
        }
    }

    return 0;
}