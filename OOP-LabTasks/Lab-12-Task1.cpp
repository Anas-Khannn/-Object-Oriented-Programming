#include <stdio.h>
int secondMax(int *array, int size); //function Declare 
int main() {
  int array[10];
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    printf("Enter the %d element : ", i+1);
    scanf("%d", &array[i]);
  }
  int result = secondMax(array, size); // function call
  printf("The second largest element in the array is: %d\n", result);
  return 0;
}
int secondMax(int *array, int size)  // defining the function
 {
  int max =array[0];  // giving first value of array to max for checking the 2nd largest element
  int secondMax = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      secondMax = max;
      max = array[i];
    } else if (array[i] > secondMax) {
      secondMax = array[i];
    }
  }
  return secondMax;
}