#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int i, week, sales;
  int mangoes[10] = {200, 430, 200, 490, 100, 122, 301, 2000, 1330, 11};
  int apple[10] = {330, 11, 331, 123, 340, 430, 440, 33, 234, 330};
  int banana[10] = {120, 220, 213, 120, 123, 1230, 123, 2220, 1230, 23};
  int orange[10] = {100, 430, 334, 420, 490, 1233, 122, 333, 12, 11};
  int grapes[10] = {220, 110, 122, 123, 1230, 131, 330, 1233, 340, 40};

  // Open file for writing
  FILE *fp = fopen("sales.txt", "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Print header to the console
  printf("Item\tWeek 1\tWeek 2\tWeek 3\tWeek 4\tWeek 5\tWeek 6\tWeek 7\tWeek 8\tWeek 9\tWeek 10\tTotal\n");

  // Print header to the file
  fprintf(fp, "%-10s", "Item");
  for (week = 1; week <= 10; week++) {
    fprintf(fp, "Week %-4d", week);
  }
  fprintf(fp, "Total\n");

  // Print sales for each i
  for (i = 0; i < 5; i++) {
    // Print i name to the console
    if (i == 0) {
      printf("%-10s", "Mangoes");// the purpose of -10s is for consisting column
    } else if (i == 1) {
      printf("%-10s", "Apple");
    } else if (i == 2) {
      printf("%-10s", "Banana");
    } else if (i == 3) {
      printf("%-10s", "Orange");
    } else {
      printf("%-10s", "Grapes");
    }

    // Print i name to the file
    if (i == 0) {
      fprintf(fp, "%-10s", "Mangoes");
    } else if (i == 1) {
      fprintf(fp, "%-10s", "Apple");
    } else if (i == 2) {
      fprintf(fp, "%-10s", "Banana");
    } else if (i == 3) {
      fprintf(fp, "%-10s", "Orange");
    } else {
      fprintf(fp, "%-10s", "Grapes");
    }

    int total = 0; // Variable to store the total sales

    // Print sales data for each week
    for (week = 0; week < 10; week++) {
      switch (i) {
        case 0:
          sales = mangoes[week];
          break;
        case 1:
          sales = apple[week];
          break;
        case 2:
          sales = banana[week];
          break;
        case 3:
          sales = orange[week];
          break;  case 4:
          sales = grapes[week];
          break;
      }
      total =total+ sales; // Accumulate the sales to calculate the total

      // Print sales data to the console
      printf("%-8d", sales);

      // Print sales data to the file
      fprintf(fp, "%-9d", sales);
    }

    // Print the total sales for the fruit
    printf("%-9d\n", total);//-9d is the width specifier for the integer field, which specifies the minimum width of the printed output

    // Print the total sales for the fruit to the file
    fprintf(fp, "%-8d\n", total);
  }

  // Close the file
  fclose(fp);

  return 0;
}