#include <iostream>
#include <string>
using namespace std;

struct Person
{
    int id;
    string firstName;
    string lastName;
    string password;

    Person(int id = 0, string firstName = "", string lastName = "", string password = "")
        : id(id), firstName(firstName), lastName(lastName), password(password) {}
};

struct SalesPerson
{
    Person user;
    double salesByQtr[4];
    double totalSale;

    SalesPerson(Person user = Person()) : user(user)
    {
        for (int i = 0; i < 4; i++)
        {
            salesByQtr[i] = 0.0;
        }
        totalSale = 0.0;
    }
};

struct Admin
{
    Person user;
    bool isFirstLogin;

    Admin(Person user = Person(), bool isFirstLogin = true) : user(user), isFirstLogin(isFirstLogin) {}
};

void displayMainMenu()
{
    cout << "Welcome to Sales Management System!" << endl;
    cout << "Please select from the following menu:" << endl;
    cout << "1. Admin mode" << endl;
    cout << "2. Salesperson mode" << endl;
    cout << "0. Exit" << endl;
}

void displayAdminMenu(SalesPerson salesPersons[], int &totalSalesPersons)
{
    cout << "Admin menu:" << endl;
    cout << "1. Display complete record" << endl;
    cout << "2. Display single salesperson record" << endl;
    cout << "3. Add/enroll a salesperson" << endl;
    cout << "4. Logout" << endl;

    int adminChoice;
    cin >> adminChoice;

    if (adminChoice == 1)
    {
        
        cout << "ID\tFirst Name\tLast Name\tQtr1\tQtr2\tQtr3\tQtr4\tTotal" << endl;
        for (int i = 0; i < totalSalesPersons; i++)
        {
            cout << salesPersons[i].user.id << "\t" << salesPersons[i].user.firstName << "\t"
                 << salesPersons[i].user.lastName << "\t";
            for (int j = 0; j < 4; j++)
            {
                cout << salesPersons[i].salesByQtr[j] << "\t";
            }
            cout << salesPersons[i].totalSale << endl;
        }
    }
    else if (adminChoice == 2)
    {
       
        cout << "Enter Salesperson ID: ";
        int idToDisplay;
        cin >> idToDisplay;
        bool found = false;
        for (int i = 0; i < totalSalesPersons; i++)
        {
            if (salesPersons[i].user.id == idToDisplay)
            {
                cout << "ID\tFirst Name\tLast Name\tQtr1\tQtr2\tQtr3\tQtr4\tTotal" << endl;
                cout << salesPersons[i].user.id << "\t" << salesPersons[i].user.firstName << "\t"
                     << salesPersons[i].user.lastName << "\t";
                for (int j = 0; j < 4; j++)
                {
                    cout << salesPersons[i].salesByQtr[j] << "\t";
                }
                cout << salesPersons[i].totalSale << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Salesperson with ID " << idToDisplay << " not found." << endl;
        }
    }
    else if (adminChoice == 3)
    {
        
        if (totalSalesPersons < 5)
        {
            cout << "Enter Salesperson ID: ";
            int newID;
            cin >> newID;
            bool idExists = false;
            for (int i = 0; i < totalSalesPersons; i++)
            {
                if (salesPersons[i].user.id == newID)
                {
                    idExists = true;
                    break;
                }
            }
            if (!idExists)
            {
                cout << "Enter Salesperson First Name: ";
                string firstName;
                cin >> firstName;
                cout << "Enter Salesperson Last Name: ";
                string lastName;
                cin >> lastName;
                cout << "Enter Salesperson Password: ";
                string password;
                cin >> password;
                salesPersons[totalSalesPersons].user.id = newID;
                salesPersons[totalSalesPersons].user.firstName = firstName;
                salesPersons[totalSalesPersons].user.lastName = lastName;
                salesPersons[totalSalesPersons].user.password = password;
                totalSalesPersons++;
                cout << "Salesperson added successfully!" << endl;
            }
            else
            {
                cout << "Salesperson with ID " << newID << " already exists." << endl;
            }
        }
        else
        {
            cout << "Maximum number of salespersons reached (5)." << endl;
        }
    }
}

void displaySalesPersonMenu(SalesPerson &salesPerson)
{
    cout << "Salesperson menu:" << endl;
    cout << "1. Update salesByQtr" << endl;
    cout << "2. View salesperson record" << endl;
    cout << "3. Logout" << endl;

    int salesPersonChoice;
    cin >> salesPersonChoice;

    if (salesPersonChoice == 1)
    {
        
        cout << "Enter sales for each quarter:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "Quarter " << (i + 1) << ": ";
            cin >> salesPerson.salesByQtr[i];
        }
        salesPerson.totalSale = 0;
        for (int i = 0; i < 4; i++)
        {
            salesPerson.totalSale += salesPerson.salesByQtr[i];
        }
        cout << "Sales updated successfully!" << endl;
    }
    else if (salesPersonChoice == 2)
    {
        cout << "ID\tFirst Name\tLast Name\tQtr1\tQtr2\tQtr3\tQtr4\tTotal" << endl;
        cout << salesPerson.user.id << "\t" << salesPerson.user.firstName << "\t"
             << salesPerson.user.lastName << "\t";
        for (int j = 0; j < 4; j++)
        {
            cout << salesPerson.salesByQtr[j] << "\t";
        }
        cout << salesPerson.totalSale << endl;
    }
}

int main()
{
    Person adminUser(1, "Admin", "Admin", "admin");
    Admin admin(adminUser);

    SalesPerson salesPersons[5];
    int totalSalesPersons = 0;

    bool isFirstAdminLogin = true;

    while (true)
    {
        displayMainMenu();

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            if (isFirstAdminLogin)
            {
                cout << "It's the first admin login. Please change the password: ";
                string newPassword;
                cin >> newPassword;
                admin.user.password = newPassword;
                isFirstAdminLogin = false;
                cout << "Password changed successfully!" << endl;
            }

            string enteredPassword;
            cout << "Enter the admin password: ";
            cin >> enteredPassword;

            if (enteredPassword == admin.user.password)
            {
                while (true)
                {
                    displayAdminMenu(salesPersons, totalSalesPersons);
                    int adminChoice;
                    cin >> adminChoice;

                    if (adminChoice == 4)
                    {
                        break;
                    }
                    else if (adminChoice != 1 && adminChoice != 2 && adminChoice != 3)
                    {
                        cout << "Invalid choice!" << endl;
                    }
                }
            }
            else
            {
                cout << "Access is denied due to incorrect password." << endl;
                continue;
            }
        }
        else if (choice == 2)
        {
            if (totalSalesPersons == 0)
            {
                cout << "No salespersons enrolled yet. Please contact the admin." << endl;
                continue;
            }
            else
            {
                cout << "Enter your ID: ";
                int salespersonID;
                cin >> salespersonID;

                SalesPerson *currentSalesperson = nullptr;

                for (int i = 0; i < totalSalesPersons; i++)
                {
                    if (salesPersons[i].user.id == salespersonID)
                    {
                        currentSalesperson = &salesPersons[i];
                        break;
                    }
                }

                if (currentSalesperson != nullptr)
                {
                    cout << "Enter your password: ";
                    string enteredPassword;
                    cin >> enteredPassword;

                    if (enteredPassword == currentSalesperson->user.password)
                    {
                        while (true)
                        {
                            displaySalesPersonMenu(*currentSalesperson);
                            int salespersonChoice;
                            cin >> salespersonChoice;

                            if (salespersonChoice == 3)
                            {
                                break;
                            }
                            else if (salespersonChoice != 1 && salespersonChoice != 2)
                            {
                                cout << "Invalid choice!" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Incorrect password. Access denied." << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "Salesperson not found. Please contact the admin to enroll." << endl;
                    continue;
                }
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            continue;
        }
    }

    return 0;
}
