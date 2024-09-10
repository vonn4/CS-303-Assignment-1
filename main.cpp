#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "main.h"

using namespace std;

int main() {
    // Reading data from input file
    ifstream inFile("A1input.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Read integers from file into the array
    while (inFile >> arr[size] && size < MAX_SIZE) {
        size++;
    }
    inFile.close();

    cout << "What would you like to do?" << endl;
    cout << "1. Print the array" << endl;
    cout << "2. Search for a number" << endl;
    cout << "3. Change a number" << endl;
    cout << "4. Add a number" << endl;
    cout << "5. Remove a number" << endl;
    cout << "6. Quit" << endl;

    int choice;
    cin >> choice ;
    while(choice != 6){
        if(choice == 1){
            // Display array content
            cout << "Array contents: " << endl;
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << endl;
            cout << "Would you like to do something else?" << endl;
            cout << "1. Print the array" << endl;
            cout << "2. Search for a number" << endl;
            cout << "3. Change a number" << endl;
            cout << "4. Add a number" << endl;
            cout << "5. Remove a number" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
        }
        else if(choice == 2){
            //search for a number
            int numToFind;
            cout << "Enter the number to search for: ";
            cin >> numToFind;
            
            int index = findInteger(numToFind);
            if (index != -1) {
                cout << numToFind << " found at index " << index << endl;
                cout << endl;
            } else {
                cout << numToFind << " not found in the array." << endl;
                cout << endl;
            }
            cout << "Would you like to do something else?" << endl;
            cout << "1. Print the array" << endl;
            cout << "2. Search for a number" << endl;
            cout << "3. Change a number" << endl;
            cout << "4. Add a number" << endl;
            cout << "5. Remove a number" << endl;
            cout << "6. Quit" << endl;
            cin >> choice ;
        }
            
        else if(choice == 3){
            cout << "Enter the index of the number to change: ";
            int index_for_change;
            cin >> index_for_change;
            cout << "Enter the new value: ";
            int new_value;
            cin >> new_value;
            modifyInteger(index_for_change, new_value);
            cout << "Would you like to do something else?" << endl;
            cout << "1. Print the array" << endl;
            cout << "2. Search for a number" << endl;
            cout << "3. Change a number" << endl;
            cout << "4. Add a number" << endl;
            cout << "5. Remove a number" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
        }
        else if(choice == 4){
            //Add a number at the end of the array
            cout << "Enter the number to add: ";
            int numToAdd;
            cin >> numToAdd;
            addInteger(numToAdd);  
            cout << "Would you like to do something else?" << endl;
            cout << "1. Print the array" << endl;
            cout << "2. Search for a number" << endl;
            cout << "3. Change a number" << endl;
            cout << "4. Add a number" << endl;
            cout << "5. Remove a number" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
        }
        else if(choice == 5){
            //remove a number
            cout << "Enter an index to remove from:" ;
            int index_for_remove;
            cin >> index_for_remove;
            srand(static_cast<unsigned int>(time(0)));
            // Generate a random number (0 or 1)
            int randomNumber = rand() % 2;
            if(randomNumber == 0){
                removeInteger(index_for_remove,false);
            }
            else{
            removeInteger(index_for_remove, true);     
            }
            cout << "Would you like to do something else?" << endl;
            cout << "1. Print the array" << endl;
            cout << "2. Search for a number" << endl;
            cout << "3. Change a number" << endl;
            cout << "4. Add a number" << endl;
            cout << "5. Remove a number" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
        }
        else{
            cout << "Invalid choice. Please try again." << endl;
            cin >> choice;
        }    
    }
    return 0;
}
