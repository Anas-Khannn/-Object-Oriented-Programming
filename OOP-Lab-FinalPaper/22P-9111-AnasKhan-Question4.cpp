#include <iostream>
using namespace std;

class PersonalInfo
{
private:
    string name;
    string Birthday;
    int Date;
    int Month;
    int year;
    int PersondId;

public:
    PersonalInfo(string name, string Birthday, int PersondId, int Date, int Month, int Year)
    {
        this->name = name;
        this->Birthday = Birthday;
        this->PersondId = PersondId;
        this->Date = Date;
        this->Month = Month;
        this->year = Year;
    }

    void Display()
    {
        cout << "PERSONAL INFO" << endl;
        cout << "Name : " << name << endl;
        cout << "Birthday : " << Birthday << endl;
        cout << "Personal ID : " << PersondId << endl;
        cout << "Date : " << Date << endl;
        cout << "Month : " << Month << endl;
        cout << "Year : " << year << endl;
    }
};

class PersonType : public PersonalInfo
{
private:
    string Firstname;
    string Lastname;

public:
    PersonType(string Firstname, string Lastname)
    {
        this->Firstname = Firstname;
        this->Lastname = Lastname;
    }
    // getter
    string getFirstname()
    {
        return Firstname;
    }
    string getLastname()
    {
        return Lastname;
    }
    // setter
    void setFirstname(string Firstname)
    {
        this->Firstname = Firstname;
    }
    void setLastname(string Lastname)
    {
        this->Lastname = Lastname;
    }
    void Display()
    {
        PersonalInfo::Display();
        cout << "FULL NAME : " << Firstname << " " << Lastname
             << endl;
    }
};

class DateType{
    int Month;
    int day;
    int year;

    // setter & getter
    // getter
    int getMonth()
    {
        return Month;
    }
    int  getDay()
    {
        return day ;
    }

    int getyear()
    {
        return year;

    }
    // setter
    void setmonth(int Month)
    {
        this->Month = Month;
    }
    void setday(int  setday)
    {
        this->setday= setday;
    }
    void setyear(int year)
    {
              this->year=year
    }

    
};

int main()
{

    
    return 0;
}
