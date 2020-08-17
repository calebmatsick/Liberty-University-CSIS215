#pragma once

/*
  Implementation for the dictionary functions
*/

// Include statements
#include <memory>
#include "dictionaryADT.h"
#include "kvpair.h"
#include "ABag.h"

/*
  Template dictionary class that uses Key Value pairs to access and store data
*/
template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E>
{
public:

    /*
      Constructer
    */
    BDictionary(int dictSize) {}

    /*
      Destructer
    */
    ~BDictionary() {}

    /*
      Reinitializes dictionary
    */
    void clear() {
        // Clears the dictionary by using ABag's emptyBag fucntion
        myDictionary.emptyBag();
    }

    /*
      Inserts a new record
    */
    bool insert(const Key& k, const E& e) {

        // Flag to determine if insert works
        bool flag;

        // Creates new KV pair
        KVpair<Key, E> temp(k, e);

        // Adds new KV pair to the bag
        flag = myDictionary += temp;

        // Return true
        return flag;
    }

    /*
      Looks for a record using the key and removes the record from the dictionary
    */
    bool remove(const Key& k, E& rtnVal) {

        // Flag to determine if remove was successful
        bool flag = false;

        // Creates new KV pair
        KVpair<Key, E> temp(k, rtnVal);

        // If Bag isn't empty attempts to find value and remove value in the bag
        if (size() > 0) {
            flag = myDictionary.remove(temp);
            rtnVal = temp.value();
        }

        // Returns flag
        return flag;
    }
    /*
      Removes a random record from the dictionary
    */
    bool removeAny(E& returnValue) {

        // Flag to determine is remove was successful
        bool flag = false;

        // Creates temporary KV pair
        KVpair<Key, E> temp;

        // Removes value from index
        flag = myDictionary.removeTop(temp);
        returnValue = temp.value();
        
        // Returns flag
        return flag;
    }

    /*
      Finds a record using the key
    */
    bool find(const Key& k, E& returnValue) const {

        // Flag to determine if find was successful
        bool flag = true;

        // Creates new temporary key
        KVpair<Key, E> temp(k, returnValue);

        // Attempts to find key
        flag = myDictionary.find(temp);
        returnValue = temp.value();

        // Returns flag
        return flag;
    }

    /*
    Returns the number of records in the dictionary
    */
    int size() {
        // Returns size of dictionary using bag find function
        return myDictionary.size();
    }

private:
    ABag<KVpair<Key, E>> myDictionary; // Dictionary created using smart pointers
};