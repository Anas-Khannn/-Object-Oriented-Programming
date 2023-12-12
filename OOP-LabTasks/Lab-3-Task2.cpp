#include <iostream>
using namespace std;

struct Student {
  string name;
  int marks[3];
};

void DisplayData(Student students[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Student " << i + 1 << ":" << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "Marks: ";
    for (int j = 0; j < 3; j++) {
      cout << students[i].marks[j] << " ";
    }
    cout << endl;
  }
}

void ChangeMarks(Student& student, int courseNo, int newMarks) {
  student.marks[courseNo] = newMarks;
}

float CalcAverageMarks(Student student) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += student.marks[i];
  }
  return sum / 3.0f;
}

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;

  Student students[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter the name of student " << i + 1 << ": ";
    cin >> students[i].name;

    for (int j = 0; j < 3; j++) {
      cout << "Enter the marks of course " << j + 1 << " for student " << i + 1 << ": ";
      cin >> students[i].marks[j];
    }
  }

  int option;
  int studentNo;
  int courseNo;
  int newMarks;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Display Student Data\n";
    cout << "2. Calculate Average marks\n";
    cout << "3. Change Marks\n";
    cout << "4. Quit\n";
    cout << "Please select an Option: ";
    cin >> option;

    if (option == 4) {
      break;
    }

    cout << "Enter the student number: ";
    cin >> studentNo;

    if (studentNo < 1 || studentNo > n) {
      cout << "Invalid student number. Please enter a valid student number." << endl;
      continue;
    }

    if (option == 1) {
      DisplayData(&students[studentNo - 1], 1);
    } else if (option == 2) {
      cout << "Average marks: " << CalcAverageMarks(students[studentNo - 1]) << endl;
    } else if (option == 3) {
      cout << "Enter the course number to change marks: ";
      cin >> courseNo;

      if (courseNo < 1 || courseNo > 3) {
        cout << "Invalid course number. Please enter a valid course number (1-3)." << endl;
        continue;
      }

      cout << "Enter the new marks: ";
      cin >> newMarks;
      ChangeMarks(students[studentNo - 1], courseNo - 1, newMarks);
      cout << "Marks changed successfully." << endl;
    }
  }

  return 0;
}
