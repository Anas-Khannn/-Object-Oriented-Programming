#include <iostream>

using namespace std;

class Employee {
private:
  int id;
  string name;
  string jobTitle;
  int hoursWorkedPerWeek;
  float hourlyRate;
  float salary;

public:
Employee(){}
  Employee(int id, string name, string jobTitle, int hoursWorkedPerWeek, float hourlyRate) {
    this->id = id;
    this->name = name;
    this->jobTitle = jobTitle;
    this->hoursWorkedPerWeek = hoursWorkedPerWeek;
    this->hourlyRate = hourlyRate;
    this->salary = 0;
  }

  int getId() {
    return id;
  }

  void setId(int id) {
    this->id = id;
  }

  string getName() {
    return name;
  }

  void setName(string name) {
    this->name = name;
  }

  string getJobTitle() {
    return jobTitle;
  }

  void setJobTitle(string jobTitle) {
    this->jobTitle = jobTitle;
  }

  int getHoursWorkedPerWeek() {
    return hoursWorkedPerWeek;
  }

  void setHoursWorkedPerWeek(int hoursWorkedPerWeek) {
    this->hoursWorkedPerWeek = hoursWorkedPerWeek;
  }

  float getHourlyRate() {
    return hourlyRate;
  }

  void setHourlyRate(float hourlyRate) {
    this->hourlyRate = hourlyRate;
  }

  float getSalary() {
    return salary;
  }

  void setSalary(float salary) {
    this->salary = salary;
  }

  void calculateSalary() {
    if (hoursWorkedPerWeek <= 40) {
      salary = hoursWorkedPerWeek * hourlyRate;
    } else {
      int overtimeHours = hoursWorkedPerWeek - 40;
      float overtimePay = overtimeHours * hourlyRate * 2;
      salary = 40 * hourlyRate + overtimePay;
    }
  }
};

int main() {
     int id;
    string name;
    string jobTitle;
    int hoursWorkedPerWeek;
    float hourlyRate;
  int numberOfEmployees;
   cout<<"Hourly rate for company is 25"<<endl;
  cout << "Enter the number of employees: ";
  cin >> numberOfEmployees;
  Employee employees[numberOfEmployees];
  for (int i = 0; i < numberOfEmployees; i++) {
    cout << "Enter the details of employee " << i + 1 << ":" << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Job title: ";
    cin >> jobTitle;
    cout << "Hours worked per week: ";
    cin >> hoursWorkedPerWeek;
    //cout << "Hourly rate: ";
    //cin >> hourlyRate;
    employees[i] = Employee(id, name, jobTitle, hoursWorkedPerWeek, 25);
  }
  for (int i = 0; i < numberOfEmployees; i++) {
    employees[i].calculateSalary();
  }
  cout << endl << "Employee salary report:" << endl;
  for (int i = 0; i < numberOfEmployees; i++) {
    cout << "Name: " << employees[i].getName() << endl;
    cout << "Salary: " << employees[i].getSalary() << endl;
  }

  return 0;
}
