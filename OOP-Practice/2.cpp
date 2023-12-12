#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// User base class
class User
{
protected:
    string username;
    string password;

public:
    User(string username, string password) : username(username), password(password) {}

    virtual bool login(string username, string password)
    {
        return this->username == username && this->password == password;
    }

    virtual void displayMenu() {}

    string getUsername() const { return username; }
};

// Administrator user class
class Administrator : public User
{
public:
    Administrator(string username, string password) : User(username, password) {}

    void displayMenu()
    {
        cout << "\n\t\tAdministrator Menu\n";
        cout << "\n\t1. Add new product";
        cout << "\n\t2. Modify product";
        cout << "\n\t3. Remove product";
        cout << "\n\t4. Back to main menu";
        cout << "\n\tEnter your choice: ";
    }
};

// Buyer user class
class Buyer : public User
{
public:
    Buyer(string username, string password) : User(username, password) {}

    void displayMenu()
    {
        cout << "\n\t\tBuyer Menu\n";
        cout << "\n\t1. Buy product";
        cout << "\n\t2. Go back";
        cout << "\n\tEnter your choice: ";
    }
};

// Product class
class Product
{
private:
    int productCode;
    string name;
    float price;
    float discount;

public:
    Product(int productCode, string name, float price, float discount)
        : productCode(productCode), name(name), price(price), discount(discount) {}

    int getProductCode() const { return productCode; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    float getDiscount() const { return discount; }

    float getDiscountedPrice() const { return price * (1 - discount / 100); }
};

// Shopping cart class
class ShoppingCart
{
private:
    User *currentUser;
    Product *products[100]; // Array of product pointers (max 100 products)
    int numProducts;

public:
    ShoppingCart() : currentUser(nullptr), numProducts(0) {}

    void setUser(User *user) { currentUser = user; }

    void addProduct(Product *product)
    {
        if (numProducts < 100)
        {
            products[numProducts++] = product;
            cout << "\n\tProduct added successfully!";
        }
        else
        {
            cout << "\n\tCart is full!";
        }
    }

    void removeProduct(int productCode)
    {
        for (int i = 0; i < numProducts; i++)
        {
            if (products[i]->getProductCode() == productCode)
            {
                products[i] = products[numProducts - 1];
                numProducts--;
                cout << "\n\tProduct removed successfully!";
                return;
            }
        }
        cout << "\n\tProduct not found!";
    }

    void displayProducts()
    {
        cout << "\n\tProducts in cart:\n";
        cout << "\t------------------------------\n";
        cout << "\tCode\tName\t\tPrice\tDiscount\tDiscounted Price\n";
        for (int i = 0; i < numProducts; i++)
        {
            Product *product = products[i];
            cout << "\t" << product->getProductCode() << "\t" << product->getName() << "\t\t"
                 << product->getPrice() << "\t" << product->getDiscount() << "%\t"
                 << product->getDiscountedPrice() << endl;
        }
    }

    void checkout()
    {
        float total = 0.0f;
        for (int i = 0; i < numProducts; i++)
        {
            total += products[i]->getDiscountedPrice();
        }

        cout << "\n\tTotal amount: " << total << endl;

        // Payment processing options
        enum PaymentOption
        {
            Cash,
            Card,
            OnlineWallet
        };

        void choosePaymentOption(PaymentOption & chosenOption)
        {
            cout << "\n\tPlease choose your payment method:\n";
            cout << "\t1. Cash";
            cout << "\n\t2. Card";
            cout << "\n\t3. Online Wallet";
            cout << "\n\tEnter your choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                chosenOption = Cash;
                break;
            case 2:
                chosenOption = Card;
                // Implement card payment processing logic here (e.g., ask for card details)
                break;
            case 3:
                chosenOption = OnlineWallet;
                // Implement online wallet payment processing logic here (e.g., ask for wallet details)
                break;
            default:
                cout << "\n\tInvalid option!";
                break;
            }
        }

        void processPayment(float totalAmount, PaymentOption chosenOption)
        {
            // Simulate successful payment based on chosen option
            cout << "\n\tProcessing payment...";
            switch (chosenOption)
            {
            case Cash:
                cout << "\n\tCash received. Thank you for your purchase!";
                break;
            case Card:
                cout << "\n\tPayment successful! Your card has been charged.";
                break;
            case OnlineWallet:
                cout << "\n\tPayment successful! Money deducted from your online wallet.";
                break;
            }

            // Empty the cart after successful payment
            emptyCart();
        }

        void emptyCart()
        {
            numProducts = 0;
            cout << "\n\tYour cart has been emptied. Thank you for shopping!";
        }

        // File I/O for product data
        void saveProductsToFile(const string &filename)
        {
            ofstream file(filename);
            if (!file.is_open())
            {
                cout << "\n\tError saving products to file!";
                return;
            }

            for (int i = 0; i < numProducts; i++)
            {
                file << products[i]->getProductCode() << " " << products[i]->getName() << " "
                     << products[i]->getPrice() << " " << products[i]->getDiscount() << endl;
            }

            file.close();
            cout << "\n\tProducts saved successfully!";
        }

        void loadProductsFromFile(const string &filename)
        {
            ifstream file(filename);
            if (!file.is_open())
            {
                cout << "\n\tNo product data found!";
                return;
            }

            numProducts = 0;
            int productCode;
            string name;
            float price, discount;

            while (file >> productCode >> name >> price >> discount)
            {
                products[numProducts++] = new Product(productCode, name, price, discount);
            }

            file.close();
            cout << "\n\tProducts loaded successfully!";
        }

        // Main menu
        void displayMainMenu()
        {
            cout << "\n\t\tSupermarket Main Menu\n";
            cout << "\n\t1. Login";
            cout << "\n\t2. Exit";
            cout << "\n\tEnter your choice: ";
        }

        int main()
        {
            ShoppingCart cart;
            string filename = "products.txt";

            // Load products from file
            loadProductsFromFile(filename);

            bool running = true;
            while (running)
            {
                displayMainMenu();

                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    // Login process
                    string username, password;
                    cout << "\n\tEnter username: ";
                    cin >> username;
                    cout << "\n\tEnter password: ";
                    cin >> password;

                    if (username == "admin" && password == "admin")
                    {
                        cart.setUser(new Administrator(username, password));
                    }
                    else
                    {
                        cart.setUser(new Buyer(username, password));
                    }

                    if (cart.currentUser->login(username, password))
                    {
                        cout << "\n\tLogin successful! Welcome, " << cart.currentUser->getUsername() << "!";
                        cart.currentUser->displayMenu();

                        // Handle user-specific actions based on chosen menu options
                        // (e.g., add

                        // Handle user-specific actions based on chosen menu options
                        while (true)
                        {
                            int choice;
                            cin >> choice;

                            switch (choice)
                            {
                            case 1: // Add product (buyer)
                                int productCode;
                                float quantity;
                                cout << "\n\tEnter product code: ";
                                cin >> productCode;
                                cout << "\n\tEnter quantity: ";
                                cin >> quantity;

                                // Find product based on code
                                Product *product = nullptr;
                                for (int i = 0; i < numProducts; i++)
                                {
                                    if (products[i]->getProductCode() == productCode)
                                    {
                                        product = products[i];
                                        break;
                                    }
                                }

                                if (product)
                                {
                                    cart.addProduct(new Product(*product)); // Add copy to avoid modifying original data
                                    cout << "\n\t" << quantity << "x " << product->getName() << " added to cart.";
                                }
                                else
                                {
                                    cout << "\n\tProduct not found!";
                                }
                                break;

                            case 2: // Buy product (buyer)
                                cart.displayProducts();
                                if (numProducts == 0)
                                {
                                    cout << "\n\tYour cart is empty!";
                                }
                                else
                                {
                                    PaymentOption chosenOption;
                                    choosePaymentOption(chosenOption);
                                    processPayment(cart.getTotalAmount(), chosenOption);
                                }
                                break;

                            case 3: // Add new product (admin)
                                productCode;
                                name;
                                price;
                                discount;
                                cout << "\n\tEnter product code: ";
                                cin >> productCode;
                                cout << "\n\tEnter product name: ";
                                getline(cin, name);
                                cout << "\n\tEnter product price: ";
                                cin >> price;
                                cout << "\n\tEnter product discount (%): ";
                                cin >> discount;

                                cart.addProduct(new Product(productCode, name, price, discount));
                                cout << "\n\tProduct added successfully!";
                                break;

                            case 4: // Modify product (admin)
                                cout << "\n\tEnter product code: ";
                                cin >> productCode;

                                product = nullptr;
                                for (int i = 0; i < numProducts; i++)
                                {
                                    if (products[i]->getProductCode() == productCode)
                                    {
                                        product = products[i];
                                        break;
                                    }
                                }

                                if (product)
                                {
                                    int modifyChoice;
                                    cout << "\n\t1. Change name";
                                    cout << "\n\t2. Change price";
                                    cout << "\n\t3. Change discount";
                                    cout << "\n\tEnter your choice: ";
                                    cin >> modifyChoice;

                                    string newName;
                                    float newPrice;
                                    float newDiscount;

                                    switch (modifyChoice)
                                    {
                                    case 1:
                                        cout << "\n\tEnter new name: ";
                                        getline(cin, newName);
                                        product->setName(newName);
                                        break;
                                    case 2:
                                        cout << "\n\tEnter new price: ";
                                        cin >> newPrice;
                                        product->setPrice(newPrice);
                                        break;
                                    case 3:
                                        cout << "\n\tEnter new discount (%): ";
                                        cin >> newDiscount;
                                        product->setDiscount(newDiscount);
                                        break;
                                    default:
                                        cout << "\n\tInvalid choice!";
                                        break;
                                    }

                                    cout << "\n\tProduct updated successfully!";
                                }
                                else
                                {
                                    cout << "\n\tProduct not found!";
                                }
                                break;

                            case 5: // Remove product (admin)
                                cout << "\n\tEnter product code: ";
                                cin >> productCode;
                                cart.removeProduct(productCode);
                                break;

                            case 6: // Back to main menu (buyer)
                                cout << "\n\tReturning to main menu...";
                                break;

                            default:
                                cout << "\n\tInvalid choice! Please try again.";
                                break;
                            }

                            // Check if user wants to exit after each action
                            if (choice == 2 || choice == 6)
                            {
                                break;
                            }
                        }

                        // Save products to file before exiting
                        saveProductsToFile(filename);

                        cout << "\n\tThank you for using Super Market!";
                        // Implement product search based on name
                        Product *searchProductByName(const string &name)
                        {
                            for (int i = 0; i < numProducts; i++)
                            {
                                if (products[i]->getName().find(name) != string::npos)
                                {
                                    return products[i];
                                }
                            }
                            return nullptr;
                        }

                        // Implement updating product quantity (buyer)
                        void updateProductQuantity(Product * product, int quantity)
                        {
                            for (int i = 0; i < numProducts; i++)
                            {
                                if (products[i] == product)
                                {
                                    products[i]->setPrice(products[i]->getPrice() * quantity);
                                    break;
                                }
                            }
                        }

                        // Handle invalid user input and errors gracefully
                        void handleInvalidInput()
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\tInvalid input! Please try again.";
                        }

                        // Implement additional funcionalidades
                        void showProductDetails(int productCode)
                        {
                            Product *product = searchProductByName(to_string(productCode));
                            if (product)
                            {
                                cout << "\n\tProduct Details:\n";
                                cout << "\t--------------------\n";
                                cout << "\tCode: " << product->getProductCode() << endl;
                                cout << "\tName: " << product->getName() << endl;
                                cout << "\tPrice: " << product->getPrice() << endl;
                                cout << "\tDiscount: " << product->getDiscount() << "%\n";
                                cout << "\tDiscounted Price: " << product->getDiscountedPrice() << endl;
                            }
                            else
                            {
                                cout << "\n\tProduct not found!";
                            }
                        }

                        void showAllDiscounts()
                        {
                            cout << "\n\tProducts with Discounts:\n";
                            cout << "\t-------------------------\n";
                            for (int i = 0; i < numProducts; i++)
                            {
                                if (products[i]->getDiscount() > 0)
                                {
                                    cout << "\t" << products[i]->getName() << " (" << products[i]->getDiscount() << "% off)\n";
                                }
                            }

                            if (!showAllDiscounts)
                            {
                                cout << "\n\tNo discounted products found!";
                            }
                        }

                        int main()
                        {

                            while (running)
                            {
                                // ... your existing code with user input handling ...

                                try
                                {
                                    choice;
                                    cin >> choice;

                                    switch (choice)
                                    {
                                        // ... your existing cases ...

                                    case 7: // Search product (buyer)
                                        cout << "\n\tEnter product name or code: ";
                                        string searchTerm;
                                        cin >> searchTerm;

                                        product = searchProductByName(searchTerm);
                                        if (product)
                                        {
                                            showProductDetails(product->getProductCode());
                                        }
                                        else
                                        {
                                            cout << "\n\tProduct not found!";
                                        }
                                        break;

                                    case 8: // Update product quantity (buyer)
                                        cout << "\n\tEnter product code: ";
                                        cin >> productCode;
                                        cout << "\n\tEnter new quantity: ";
                                        cin >> quantity;

                                        product = searchProductByName(to_string(productCode));
                                        if (product)
                                        {
                                            updateProductQuantity(product, quantity);
                                            cout << "\n\tProduct quantity updated successfully!";
                                        }
                                        else
                                        {
                                            cout << "\n\tProduct not found!";
                                        }
                                        break;

                                    case 9: // Show all discounts (buyer)
                                        showAllDiscounts();
                                        break;

                                    default:
                                        handleInvalidInput();
                                        break;
                                    }
                                }
                                catch (invalid_argument &e)
                                {
                                    handleInvalidInput();
                                    cerr << "\n\tError: " << e.what() << endl;
                                }

                                // ... your existing code for checking exit ...
                            }

                            // ... your existing code for saving and exiting ...

                            return 0;
                        }
                    }
