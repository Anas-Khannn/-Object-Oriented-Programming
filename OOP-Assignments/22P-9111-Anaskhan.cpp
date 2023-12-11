#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Course {
public:
    char number[10];
    char name[20];
    int creditHours;
    char grade;
};

class Student {
    
    double midSemesterGPA;

    int getTotalCredits() const {
        int totalCredits = 0;
        for (int i = 0; i < numberOfCourses; ++i) {
            totalCredits += courses[i].creditHours;
        }
        return totalCredits;
    }

    public:
        char name[50];
        int ID;
        char isTuitionPaid;
        int numberOfCourses;
        Course courses[10];

        void calculateGPA() {
            double totalCredits = 0;
            double totalPoints = 0;

            for (int i = 0; i < numberOfCourses; ++i) {
                totalCredits += courses[i].creditHours;

                if (courses[i].grade == 'A') {
                    totalPoints += 4 * courses[i].creditHours;
                } else if (courses[i].grade == 'B') {
                    totalPoints += 3 * courses[i].creditHours;
                } else if (courses[i].grade == 'C') {
                    totalPoints += 2 * courses[i].creditHours;
                } else if (courses[i].grade == 'D') {
                    totalPoints += courses[i].creditHours;
                }
            }

            midSemesterGPA = totalPoints / totalCredits;
        }

        void printGradeReport() const {
            cout << "Student Name: " << name << "\n";
            cout << "Student ID: " << ID << "\n";
            cout << "Number of courses enrolled: " << numberOfCourses << "\n";

            cout << setw(10) << "Course No" << setw(20) << "Course Name" << setw(8) << "Credits" << setw(5) << "Grade\n";

            for (int i = 0; i < numberOfCourses; ++i) {
                cout << setw(10) << courses[i].number << setw(20) << courses[i].name << setw(8) << courses[i].creditHours << setw(5) << courses[i].grade << "\n";
            }

            cout << "\nTotal number of credits: " << getTotalCredits() << "\n";
            cout << fixed << setprecision(2) << "Mid-Semester GPA: " << midSemesterGPA << "\n";

            if (isTuitionPaid == 'N') {
                cout << "Grades held for nonpayment of tuition.\n";
            }
            cout << "\n";
        }
};

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file.\n";
        return 1;
    }

    int numStudents;
    inputFile >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        inputFile >> student.ID >> student.isTuitionPaid >> student.numberOfCourses;

        inputFile.ignore(); 
        inputFile.getline(student.name, sizeof(student.name));

        for (int j = 0; j < student.numberOfCourses; ++j) {
            Course course;
            inputFile >> course.number >> course.name >> course.creditHours >> course.grade;
            student.courses[j] = course;
        }

        student.calculateGPA();
        student.printGradeReport();
    }

    inputFile.close();

    return 0;
}
