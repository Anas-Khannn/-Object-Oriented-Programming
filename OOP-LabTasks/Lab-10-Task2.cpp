#include <stdio.h>
#include <stdlib.h>

int main() {
  // Open the file for reading
  FILE *fp = fopen("Sales.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Variables for reading data and calculating average
  int item, week, sales;
  int mangoesTotal = 0;
  int appleTotal = 0;
  int mangoesCount = 0;
  int appleCount = 0;

  // Read the file line by line and calculate the totals
  while (fscanf(fp, "%d", &item) != NULL) {
    // Read the sales data for each week
    for (week = 0; week < 10; week++) {
      fscanf(fp, "%d", &sales);
      if (item == 0) {
        mangoesTotal += sales;
        mangoesCount++;
      } else if (item == 1) {
        appleTotal += sales;
        appleCount++;
      }
    }
  }

  // Calculate the average sales
  float mangoesAverage = (float)mangoesTotal / mangoesCount;
  float appleAverage = (float)appleTotal / appleCount;

  // Print the results
  printf("Average sales of Mangoes: %.2f\n", mangoesAverage);
  printf("Average sales of Apples: %.2f\n", appleAverage);

  // Close the file
  fclose(fp);

  return 0;
}
