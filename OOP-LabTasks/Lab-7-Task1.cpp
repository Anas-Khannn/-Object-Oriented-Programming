#include <iostream>

using namespace std;

class Array {
private:
  float* array; // Pointer to the array
  int size; // Size of the array

public:
  // Constructor
  Array(int size) {
    array = new float[size];
    this->size = size;
  }

  // Destructor
  ~Array() {
    delete[] array;
  }

  // Store a number in an element of the array
  void store(int index, float value) {
    if (index < 0 || index >= size) {
      return;
    }

    array[index] = value;
  }

  // Retrieve a number from an element of the array
  float retrieve(int index) {
    if (index < 0 || index >= size) {
      return 0;
    }

    return array[index];
  }

  // Return the highest value stored in the array
  float highest() {
    float highest = array[0];
    for (int i = 1; i < size; i++) {
      if (array[i] > highest) {
        highest = array[i];
      }
    }

    return highest;
  }

  // Return the lowest value stored in the array
  float lowest() {
    float lowest = array[0];
    for (int i = 1; i < size; i++) {
      if (array[i] < lowest) {
        lowest = array[i];
      }
    }

    return lowest;
  }

  // Return the average of all the numbers stored in the array
  float average() {
    float sum = 0;
    for (int i = 0; i < size; i++) {
      sum += array[i];
    }

    return sum / size;
  }
};

// Example usage:

int main() {
  Array array(10);

  // Store some numbers in the array
  array.store(0, 10.0f);
  array.store(1, 20.0f);
  array.store(2, 30.0f);

  // Retrieve a number from the array
  float value = array.retrieve(0); // value will be 10.0f

  // Get information about the values stored in the array
  float highestValue = array.highest(); // highestValue will be 30.0f
  float lowestValue = array.lowest(); // lowestValue will be 10.0f
  float averageValue = array.average(); // averageValue will be 20.0f

  // Print the results
  cout << "Highest value: " << highestValue << endl;
  cout << "Lowest value: " << lowestValue << endl;
  cout << "Average value: " << averageValue << endl;

  // Free the memory allocated by the array
  array.~Array();

  return 0;
}
