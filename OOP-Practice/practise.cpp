#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Product
{
private:
    int pcode; // Product code
    float price;
    float discount; // Discount
    string pname;   // Name of the product

public:
    // Parameterized constructor
    Product(int code, float p, float d, const string &name)
        : pcode(code), price(p), discount(d), pname(name) {}

    // Accessor methods
    int getProductCode() const { return pcode; }
    float getPrice() const { return price; }
    float getDiscount() const { return discount; }
    string getProductName() const { return pname; }

    // Function to display product details
    void displayProductDetails() const
    {
        std::cout << "\t\t\t\t\t\t  " << pcode << "\t\t" << pname << "\t\t" << price << "\t" << discount << endl;
    }
};

class ShoppingCart
{
private:
    static const int MAX_PRODUCTS = 100;
    Product cart[MAX_PRODUCTS];
    int itemCount;

public:
    // Constructor
    ShoppingCart() : itemCount(0) {}

    // Function to add a product to the shopping cart
    void addToCart(const Product &product)
    {
        if (itemCount < MAX_PRODUCTS)
        {
            cart[itemCount++] = product;
        }
        else
        {
            cout << "Shopping cart is full." << endl;
        }
    }

    // Function to display the shopping cart
    void displayCart() const
    {
        std::cout << "\n\t\t\t\t\t\t  Shopping Cart\n";
        // Display the contents of the cart
        for (int i = 0; i < itemCount; ++i)
        {
            cart[i].displayProductDetails();
        }
    }
};

class User
{
protected:
    string email;
    string password;

public:
    // Parameterized constructor
    User(const string &e, const string &pass) : email(e), password(pass) {}

    // Pure virtual function for polymorphism
    virtual void displayMenu() const = 0;
};

class Administrator : public User
{
public:
    // Parameterized constructor
    Administrator(const string &e, const string &pass) : User(e, pass) {}

    // Implementation of the pure virtual function
    void displayMenu() const override
    {
        // Administrator menu code
    m:
        int choice;
        cout << endl;
        cout << "\t\t\t\t\t\t Administrator Menu \n";
        cout << "\n\t\t\t\t\t\t|__________1) Add new product_________________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________2) Modify the product______________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________3) Remove product__________________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________4) Back to Main menu_______________|";
        cout << endl;

        cout << "\n\t\t\t\t\t\t  Please Enter your choice  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            add(); // to add a new product
            break;
        }
        case 2:
        {
            edit(); // to modify or edit the existing product
            break;
        }
        case 3:
        {
            rem(); // to remove the product
            break;
        }
        case 4:
        {
            menu(); // to display the menu
            break;
        }
        default:
            cout << "\t\t\t\t\t\t  Invalid Choice !!";
        }

        goto m;
    }
};

class Buyer : public User
{
private:
    ShoppingCart cart;

public:
    // Parameterized constructor
    Buyer(const string &e, const string &pass) : User(e, pass) {}

    // Implementation of the pure virtual function
    void displayMenu() const override
    {
        // Buyer menu code

    m: // label for goto statement
        int choice;
        cout << "\t\t\t\t\t\t  Buyer Menu \n";
        cout << "\n\t\t\t\t\t\t|______1) Buy Product_______|";
        cout << "\n\t\t\t\t\t\t|                           |";
        cout << "\n\t\t\t\t\t\t|______2) Go back___________|";
        cout << endl;

        cout << "\t\t\t\t\t\t  Enter your Choice  : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
            break;
        }
        default:
            cout << "\t\t\t\t\t\t  Invalid Choice !!" << endl;
        }

        goto m;
    }

    // Accessor method for the shopping cart
    const ShoppingCart &getShoppingCart() const
    {
        return cart;
    }

    // Other buyer functions can be added as needed
};

class Shopping
{
private:
    // Function declarations
    void authenticate();
    void administratorMenu() const;
    void buyerMenu() const;
    void addProduct();
    void editProduct();
    void removeProduct();
    void listProducts() const;
    void generateReceipt(Buyer &buyer);

public:
    // Public functions
    void menu();
};

// Implement the member functions of the Shopping class and the main function as needed.
void Shopping::Add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t\t\t\t  Add new product  ";
    cout << "\n\n\t\t\t\t\t\t  Enter Product code ";
    cin >> pcode;
    cout << "\n\n\t\t\t\t\t\t  Name of the Product ";
    cin >> pname;
    cout << "\n\n\t\t\t\t\t\t  Price of the Product ";
    cin >> price;
    cout << "\n\n\t\t\t\t\t\t  Discount on Product  ";
    cin >> dis;

    data.open("database.txt", ios::in); // ios :: in -- is used to read from the file

    if (!data) // if the file doesnt exist
    {
        data.open("database.txt", ios::app | ios::out); // ios::app is used to append to the file and ios:: out is used to write in the file
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close(); // closing the file
    }
    else
    {
        data >> c >> n >> p >> d; // if the file exists then we will iterate over the file values

        while (!data.eof()) // this will help us to iterate till the last of the file
        {
            if (c == pcode) // if a product with the same code exists then we will not add it again and thats why we are using token variable to keep count if it already exists or not
            {
                token++;
            }

            data >> c >> n >> p >> d;
        }
        data.close(); // closing the file

        if (token == 1) // if the token value is incremented to 1 it means that the product is already present
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out); // ios::app is used to append to the file and ios:: out is used to write in the file
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close(); // closing the file
        }
    }

    cout << "\n\t\t\t\t\t\t  Record Inserted Successfully !!" << endl;
}
void shopping ::edit()
{
    fstream data, data1; // creating two objects of the fstream class
    int pkey;            // to get the product code from the administrator
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t\t\t\t  Modify the Product ";
    cout << "\n\t\t\t\t\t\t  Enter Product Code  :";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data) // if the file doesnt exist
    {
        cout << "\n\n\t\t\t\t\t\t  File doesn't Exist ! ";
    }
    else
    {
        // we will write the updated value in the database1 file and then we will update its name to database after we make the changes
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode) // if the product exists
            {
                cout << "\n\t\t\t\t\t\t  Product new Code  :";
                cin >> c;
                cout << "\n\t\t\t\t\t\t  Name of the Product  :";
                cin >> n;
                cout << "\n\t\t\t\t\t\t  Price  :";
                cin >> p;
                cout << "\n\t\t\t\t\t\t  Discount :";
                cin >> d;

                // enter the new record
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t\t\t\t\t  Record Edited  ";
                token++; // incrementing token bcs we find the product with the same product code
            }
            else // when the pkey entered by the user doesnt matches with the existing products code
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }

            data >> pcode >> pname >> price >> dis; // this will helps us in iterating again and again
        }
        // closing both the files
        data.close();
        data1.close();

        // we will firstly remove the old database file and then we will rename the database1.txt to database.txt
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) // it means that the product with the pcode is not present as the token value is not incremented
        {
            cout << "\n\n\t\t\t\t\t\t  Sorry! Record not found ";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1; // creating object of the fstream class
    int pkey;
    int token = 0;
    cout << "\n\n\t\t\t\t\t\t  Delete Product ";
    cout << "\n\n\t\t\t\t\t\t  Product code  :";
    cin >> pkey;

    data.open("database.txt", ios::in); // opening the file

    if (!data) // if file doesn't exist
    {
        cout << "\t\t\t\t\t\t  File doesn't Exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis; // getting the values of the different variables so that we can iterate over the file

        while (!data.eof()) // we will iterate till the end of the file
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t\t\t\t\t  Product deleted Successfully ";
                token++; // incrementing the token because we find the product
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; // writing into the file
            }

            data >> pcode >> pname >> price >> dis; // for iteratiion
        }

        // closing the opened files
        // and removing and renaming the files

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\t\t\t\t\t\t  Record Not found" << endl;
        }
    }
}

// this function will displays all the items present to the users
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
    cout << "\t\t\t\t\t\t  Product No. \t  Name \t\t Price \n";
    cout << "\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
    data >> pcode >> pname >> price >> dis;

    while (!data.eof())
    {
        cout << "\t\t\t\t\t\t   " << pcode << "\t\t" << pname << "\t\t " << price << "\n";
        data >> pcode >> pname >> price >> dis; // for iteration purpose
    }

    data.close();
}

void shopping ::receipt()
{
m:
    fstream data;

    int arrc[100]; // we are taking a array to hold the code of the various product
    int arrq[100]; // we are taking a array to hold the quantity of each product

    string choice;
    int c = 0; // counter
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t\t\t                          RECEIPT                      ";
    data.open("database.txt", ios::in); // opening the database file in read mode

    if (!data) // if the file doesn't exists
    {
        cout << "\n\n\t\t\t\t\t\t  Empty database" << endl;
        return;
    }
    else
    {
        data.close(); // we will closed the already opened file first

        list(); // if the file exists then we will show its content to the user

        cout << "\n\t\t\t\t\t\t__________________________________________________\n";
        cout << "\n\t\t\t\t\t\t|                                                 |\n";
        cout << "\n\t\t\t\t\t\t|            Please place your order              |\n";
        cout << "\n\t\t\t\t\t\t|                                                 |\n";
        cout << "\n\t\t\t\t\t\t__________________________________________________\n";

        // we are going to use do while loop here

        do
        {
            cout << "\n\n\t\t\t\t\t\t  Enter Product Code  :";
            cin >> arrc[c]; // getting the product code in our array
            cout << "\n\n\t\t\t\t\t\t  Enter the product Quantity  :";
            cin >> arrq[c];

            // checking if we ordering duplicate items or not
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n\t\t\t\t\t\t  Duplicate Product Code . Please try again :";
                    goto m;
                }
            }
            // if it is not a duplicate product code then we are going to increase the count of product
            c++;

            cout << "\n\n\t\t\t\t\t\t  Do you want to Buy another Product ? If yes then Press 'y' else 'n' ";
            cin >> choice;
        } while (choice == "y" || choice == "yes" || choice == "Yes" || choice == "Y"); // if the user wants to buy then we will repeat the loop

        cout << "\n\n\t\t\t\t\t\t_________________________________RECEIPT________________________\n";
        cout << "\n\t\t\t\t\t\t Product No.\t Product Name\t Product quantity\t Price\t Amount\t Amount with Discount\n";

        // iterating over the file to get the products and generate the prices and receipt
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof())
            {
                if (pcode == arrc[i]) // checking if the product key matches with any key in the whole file or not
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n\t\t\t\t\t\t  " << pcode << "\t\t  " << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
                i++;
            }
        }

        data.close();
    }

    cout << "\n\n\t\t\t\t\t\t___________________________________________________________";
      std::cout << "\n\t\t\t\t\t\t  Total Amount :  " << total << endl;
}

int main()
{
    Shopping s;
    s.menu();

    return 0;
}
