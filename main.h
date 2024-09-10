#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;


const int MAX_SIZE = 100;  // Max size of the array
int arr[MAX_SIZE];         // Array to hold integers from the file
int size = 0;              // Keeps track of the number of elements in the array

// Function to check if a certain integer exists in the array
//Pre: The array arr[] has been initialized and contains size number of elements.
//size should be less than or equal to the maximum allowed size (MAX_SIZE).
//The integer num is provided as an input to search within the array.
//Post:If the integer num is found in the array, the index of its first occurrence is returned.
//If the integer num is not found, the function returns -1.The array remains unchanged.
int findInteger(int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to modify the value of an integer at a given index (with try-catch block)
//PRE: The array arr[] has been initialized and contains size number of elements.
//index should be a valid index within the bounds of the array (0 ≤ index < size).
//newValue is provided as the value that should replace the current value at index.
//POST: The value at arr[index] is replaced with newValue.
//The old value at arr[index] is printed.
//The array is modified at the specified index.
void modifyInteger(int index, int newValue) {
    try {
        // Check if index is out of bounds
        if (index < 0 || index >= size) {
            throw out_of_range("Index is out of range.");
        }
        int oldValue = arr[index];
        arr[index] = newValue;
        cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
        cout << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to add a new integer to the end of the array (with try-catch block)
//PRE: The array arr[] has been initialized and contains size number of elements.
//size should be less than the maximum allowed size (MAX_SIZE).
//newValue is provided as the integer that should be added to the end of the array.
//POST:newValue is appended to the end of the array if there is enough space.
//size is incremented by 1 to reflect the new element.
//If the array is full, no changes are made, and an error message is printed.
void addInteger(int newValue) {
    try {
        // Check if the array is already full
        if (size >= MAX_SIZE) {
            throw overflow_error("Array is full.");
        }
        arr[size++] = newValue;
        cout << "Added " << newValue << " to the array." << endl;
        cout << endl;
    } catch (const overflow_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to replace value at a given index with 0 or remove the integer
//PRE:The array arr[] has been initialized and contains size number of elements.
//index should be a valid index within the bounds of the array (0 ≤ index < size).
//replaceWithZero is a boolean value:
    //If true, replace the value at index with 0.
    //If false, remove the value at index and shift subsequent elements to the left.
//POST: If replaceWithZero is true, the value at arr[index] is replaced with 0, and size remains the same.
//If replaceWithZero is false, the value at arr[index] is removed, elements are shifted left, and size is decremented by 1.
//If the index is invalid, no changes are made, and an error message is printed.
void removeInteger(int index, bool replaceWithZero) {
    if (index >= 0 && index < size) {
        if (replaceWithZero) {
            arr[index] = 0;
            cout << "Value at index " << index << " replaced with 0." << endl;
        } else {
            // Remove integer and shift elements left
            for (int i = index; i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            size--;  // Decrease the size
            cout << "Integer at index " << index << " removed from the array." << endl;
            cout << endl;
        }
    } else {
        cout << "Invalid index!" << endl;
    }
}