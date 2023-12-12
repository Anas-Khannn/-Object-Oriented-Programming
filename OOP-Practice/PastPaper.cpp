#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    // Constructor
    DynamicArray(int initialSize) {
        size = initialSize;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0; // Initialize array elements to 0
        }
        std::cout << "Constructor called\n";
    }

    // Copy Constructor
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Copy elements from the other array
        }
        std::cout << "Copy Constructor called\n";
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    // Function to display array elements
    void display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // Creating an object using the constructor
    DynamicArray arr1(5);
    std::cout << "Array 1: ";
    arr1.display();

    // Creating a new object using the copy constructor
    DynamicArray arr2 = arr1;
    std::cout << "Array 2 (Copy of Array 1): ";
    arr2.display();

    // Modifying the original array
    arr1.display(); // Array 1

    return 0;
}
