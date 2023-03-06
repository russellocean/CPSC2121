/*
 * Name: Russell Welch
 * Date Submitted: 03/06/2023
 * Lab Section: 001 
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

/**
 * @brief Inserts word into the Stringset if it is not already there,
 * doubles the size of the Stringset if num_elems == size.
 * 
 * @param word The string to be inserted into the Stringset.
 */
void Stringset::insert(string word) {
    // Initialize the hash function
    hash<string> stringHash;

    // If num_elems == size, double the size of the Stringset
    if (num_elems == size) {
        // Double the size
        size *= 2;

        // Create a new table
        vector<list<string>> newTable(size);

        // Increment through the old table
        for (int i = 0; i < size / 2; i++) {
            // Increment through the list at index i
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                // Get the new hash index
                int index = stringHash(*it) % size;

                // Insert the word at the hash index in the new table
                newTable[index].push_back(*it);
            }
        }

        // Deallocate the old table
        vector<list<string>>().swap(table);

        // Set the table to the new table
        table = newTable;
    }

    // Get the hash index
    int index = stringHash(word) % size;

    // If the word is not in the Stringset, insert it at the hash index
    if (!find(word)) {
        table[index].push_back(word);

        // Increment the number of elements
        num_elems++;
    }
}

/**
 * @brief Returns true if word is in the Stringset, false otherwise.
 * 
 * @param word The string to be searched for in the Stringset.
 * @return True if word is in the Stringset, false otherwise.
 */
bool Stringset::find(string word) const {
    // Initialize the hash function
    hash<string> stringHash;

    // Get the hash index
    int index = stringHash(word) % size;

    // Increment through the list at the hash index, if the word is found, return true
    for (auto it = table[index].begin(); it != table[index].end(); it++) {
        if (*it == word) {
            return true;
        }
    }

    // If the word is not found, return false
    return false;
}

/**
 * @brief Removes word from the Stringset if it is there.
 * 
 * @param word The string to be removed from the Stringset.
 */
void Stringset::remove(string word) {
    // Initialize the hash function
    hash<string> stringHash;

    // Get the hash index
    int index = stringHash(word) % size;

    // Increment through the list at the hash index, if the word is found, remove it
    for (auto it = table[index].begin(); it != table[index].end(); it++) {
        if (*it == word) {
            table[index].erase(it);

            // Decrement the number of elements
            num_elems--;
            break;
        }
    }
}