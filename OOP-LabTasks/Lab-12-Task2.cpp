#include <stdio.h>
void TotalBill(int *No_Of_Fruits, float *fruitPrices, int size);//function declare
int main() {
  int No_Of_Fruits[] = {3, 2, 0, 0, 1}; //  no of  fruits
  float fruitPrices[] = {0.75, 0.60, 0.80, 1.20, 1.00};
  TotalBill(No_Of_Fruits, fruitPrices, 5); // function call giving the size of array 5
  return 0;
}
void TotalBill(int *No_Of_Fruits, float *fruitPrices, int size) {
  float total = 0.0;
  
  for (int i = 0; i < size; i++) {
    total =total + No_Of_Fruits[i] * fruitPrices[i];
  }
  printf("IF The Customer Bought\n3 APPLE\n2 BANANAS\n1 Kiwi\n");
  printf("Total bill: %.2f\n", total);
}
