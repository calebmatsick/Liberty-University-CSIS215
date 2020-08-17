#pragma once

// Include statements
#include "bagADT.h"
#include <memory>

/*
  Implementation of bag functions
*/
template <typename E>
class ABag : public Bag <E> 
{
public:
    
    /*
      Constructer
    */
    ABag() {}

    /*
      Destructer
    */
    ~ABag() {}

    /*
      Add item to the bag
    */
    bool addItem(const E& item) {
        // Flag to determine if add item was successful
        bool flag = true;

        // Checks to see if bag is full
        if (size() == bagCapacity()) {
            flag = false;
        }

        // If it is not full, add new item and add 1 to count
        else {
            int temp = size();
            bag[temp] = item;
            count++;
        }

        // Returns flag
        return flag;
     }

    /*
      Overloads += operator
    */
    bool operator+=(const E& addend) {
        // Flag to determine if += was successful
        bool flag;

        // Adds new item
        flag = addItem(addend);

        // Returns flag
        return flag;
    }

    /*
      Removes item from the bag
    */
    bool remove(E& item) {
        // Flag
        bool flag = true;

        // Checks to see if bag is empty
        if (size() == 0) {
            flag = false;
        }

        // Sets flag equal to the return value of the find function (True if found)
        flag = find(item);

        // If flag is true, loops through all items until item is found, removes it, and shifts others down
        if (flag == true) {

            // Variable that holds the index of the top element
            int i = size() - 1;

            // Finds the element that needs to be removed
            while (!(bag[i] == item))
                i--;

            // Shifts all elements above the one that needs to be removed down one
            for (int j = i; j < size(); j++) {
                bag[j] = bag[j + 1];
            }

            // Decrements size
            count--;
        }
        // Returns flag
        return flag;
    }

    /*
      Removes the top item from the bag
    */
    bool removeTop(E& returnValue) {
        // Flag to determine if remove was successful
        bool flag = true;

        // If there are no items in the bag, sets flag equal to false
        if (size() == 0) {
            flag = false;
        }
        // Else removes top element and decrements count
        else {
            inspectTop(returnValue);
            count--;
        }
        // Returns flag
        return flag;
    }

    /*
      Finds item in the bag
    */
    bool find(E& returnValue) const {
        // Temporary index variable
        int i = 0;

        // Flag to determine whether find was successful
        bool flag = false;

        // Loops through the bag and sets bag equal to true if it was found
        while (!flag) {
            // If item is found, sets flag equal to true and escapes the loop
            if (bag[i] == returnValue) {
                returnValue = bag[i];
                flag = true;
            }
            i++;
        }

        // Returns flag
        return flag;
    }

    /*
      Looks at top item in the bag
    */
    bool inspectTop(E& item) const{
        // Flag to determine is there was a top object
        bool flag = true;

        // If size is 0, sets flag to false
        if (size() == 0) {
            flag = false;
        }
        // If bag is not empty, sets item equal to the top element
        else {
            item = bag[size() - 1];
        }

        // Returns flag
        return flag;
    }

    /*
      Clears everything out of the bag
    */
    void emptyBag() {
        // Emptys the bag by iterating through each index and removing the object in it
        for (int i = size() - 1; i > 0; i--) {
            remove(bag[i]);
        }

        // Sets count to 0
        count = 0;
    }

    /*
      Returns the size of the bag
    */
    int size() const {
        // Returns the number of objects currently in the bag
        return count;
    }

    /*
      Returns the capacity of the bag
    */
    int bagCapacity() const {
        // Returns max capacity of the bag
        return 10;
    }

private:
    int count = 0; // Number of objects in bag
    E bag[10]; // Bag created
};