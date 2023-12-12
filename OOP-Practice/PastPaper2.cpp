#include <iostream>
#include <string>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int age;
};

// Function to input student data
void inputStudentData(Student* student) {
    cout << "Enter student name: ";
    cin >> student->name;
    cout << "Enter student age: ";
    cin >> student->age;
}

// Function to display student data
void displayStudentData(const Student* student) {
    cout << "Name: " << student->name << ", Age: " << student->age << endl;
}

// Function to calculate the average age of students
static double calculateAverageAge(const Student* students, int numStudents) {
    if (numStudents == 0) {
        return 0.0;
    }

    int totalAge = 0;
    for (int i = 0; i < numStudents; ++i) {
        totalAge += students[i].age;
    }

    return static_cast<double>(totalAge) / numStudents;
}

int main() {
    const int MAX_STUDENTS = 3;
    Student students[MAX_STUDENTS];

    // Input student data
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        cout << "Enter data for student " << (i + 1) << ":\n";
        inputStudentData(&students[i]);
    }

    // Display student data
    cout << "\nStudent Information:\n";
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        displayStudentData(&students[i]);
    }

    // Calculate and display average age
    double averageAge = calculateAverageAge(students, MAX_STUDENTS);
    cout << "\nAverage Age of Students: " << averageAge << endl;

    return 0;
}
