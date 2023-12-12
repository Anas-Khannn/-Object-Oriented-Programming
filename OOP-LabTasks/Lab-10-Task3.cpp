#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int numberOfSections, numberOfStudents, i, j;
  float gpa, averageGPA;
  char name[100];

  // Get the number of sections
  printf("Enter the number of sections: ");
  scanf("%d", &numberOfSections);

  // Iterate over the sections
  for (i = 0; i < numberOfSections; i++) {
    // Get the number of students in the section
    printf("Enter the number of students in section %d: ", i + 1);
    scanf("%d", &numberOfStudents);

    // Create a file for the section
    char filename[20];
    sprintf(filename, "section%d.txt", i + 1);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
    }

    // Iterate over the students in the section
    for (j = 0; j < numberOfStudents; j++) {
      // Get the student's name and GPA
      printf("Enter name and GPA for student %d in section %d: ", j + 1, i + 1);
      scanf("%s %f", name, &gpa);

      // Write the student's name and GPA to the file
      fprintf(fp, "%s %.2f\n", name, gpa);
    }

    // Close the file
    fclose(fp);
    printf("Data for section %d has been saved to file %s\n", i + 1, filename);
  }

  // Calculate the average GPA for each section
  for (i = 0; i < numberOfSections; i++) {
    float sumGPA = 0.0;
    averageGPA = 0.0;

    // Read the data from the file
    char filename[20];
    sprintf(filename, "section%d.txt", i + 1);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
    }

    // Iterate over the students in the section
    for (j = 0; j < numberOfStudents; j++) {
      fscanf(fp, "%s %f", name, &gpa);
      // Add the student's GPA to the sum
      sumGPA += gpa;
    }

    // Calculate the average GPA for the section
    averageGPA = sumGPA / numberOfStudents;

    // Print the average GPA
    printf("Average GPA for section %d: %.2f\n", i + 1, averageGPA);

    // Close the file
    fclose(fp);
  }

  return 0;
}
