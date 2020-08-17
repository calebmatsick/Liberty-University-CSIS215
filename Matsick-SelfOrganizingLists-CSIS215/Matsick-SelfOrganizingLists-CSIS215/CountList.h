#pragma once

// Include statements
#include <iostream>
#include "link.h"
#include "SelfOrderedListADT.h"

/*
  LinkedList that Self-Orders based on the number of times each node has been accessed
*/
template <typename E>
class CountList : public SelfOrderedListADT<E> {
private:
    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int compares;        // Number of compares made
    int numElements;     // Number of elements in LinkedList
public:

    /*
      Constructer
    */
    CountList() {
        curr = tail = head = new Link<E>; // Initialize current, head, and tail node
        numElements = 0; // Initialize number of elements
        compares = 0;  // Initialize number of compares
    }

    /*
      Destructer
    */
    ~CountList() {}

    /*
      Look for 'it'.  If found return true and execute the self-ordering
      heuristic used for ordering the list: count, move-to-front, or transpose.
      Increments the compare instance variable every time it compares 'it' to
      other members of the list. Returns true if 'it' is found.
    */
    bool find(const E& it) {

        curr = head; // Sets current to the head of the list
        bool flag = false; // Flag for whether or not it is in the list

        // Checks to see if it is in List
        while (curr->element != it && curr->next != NULL) {
            curr = curr->next;
            compares++;
        }

        // Appends to end of list if not found
        if (curr == tail && curr->element != it) {
            if (size() != 0) {
                compares++;
            }
            add(it);
        }
        // Otherwise, iterates frequency
        else {
            curr->freq += 1;
            flag = true;
            compares++;
            
        }
        
        // Reorders list based on new element
        reorder();

        // Returns flag
        return flag;
    }

    /*
      Called by find if 'it' is not in the list. Adds the new 'it' to the list
      Can also be called independently when initially loading the list with
      unique values and when you want to load the list in the order 'it' is
      read without your re-order method being called (or the number of compares
      being incremented.
    */

    /*
      Add new 'it' to the list
    */
    void add(const E& it) {
        // If there are no elements, adds head node
        if (numElements == 0 ) {
            head = new Link<E>(it, NULL);
            tail = head;
            // Icrease size of the list
            numElements++;
        }
        // Otherwise, append to the end of the list
        else {
            tail = tail->next = new Link<E>(it, NULL);
            curr = tail;
            // Increases size of list
            numElements++;
        }
    }

    /*
      Returns the number of accumulated compares
    */
    int getCompares() const {
        return compares;
    }

    /*
      Returns the size of the list
    */
    int size() const {
        return numElements;
    }

    /*
      Prints the entire list
    */
    void printlist() {
        curr = head; // Sets current to head

        // Iterates through list and prints
        for (int i = 0; i < size(); i++) {
            std::cout << curr->element << "-" << curr->freq << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /*
      Prints n nodes
    */
    void printlist(int n) {
        curr = head; // Sets current to head

        // Iterates through the list and prints
        for (int i = 0; i < n; i++) {
            std::cout << curr->element << "-" << curr->freq << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /*
      Reorders the list based on which values have been used the most
    */
    void reorder() {  

        Link<E>* prev = new Link<E>; // Will be set to previous node from current
        Link<E>* temp = new Link<E>; // Temp used for swap

        // Sets curr to head if only one element has been added
        if (numElements == 1) {
            curr = head;
        }

        // Finds previous element if it exists
        while (curr != head) {
            // Finds previous node from curr
            prev = head;
            while (prev->next != curr) prev = prev->next;

            // Swaps elements
            if (curr->freq > prev->freq) {
                temp->element = curr->element;
                temp->freq = curr->freq;
                curr->element = prev->element;
                curr->freq = prev->freq;
                prev->element = temp->element;
                prev->freq = temp->freq;
            }
            curr = prev;
        }
    }

    /*
      Return link nodes to free store
    */
    void removeall() {   
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
};