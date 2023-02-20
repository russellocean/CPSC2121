/*
 * Name: Russell Welch
 * Date Submitted: 02/20/23
 * Lab Section: 001
 * Assignment Name: Lab 4 - Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i; // Found the target, return its index
        }
    }
    return -1; // Target not found
}

template <class T>
int binarySearch(std::vector<T> data, T target){
    int left = 0;
    int right = data.size() - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (data[mid] == target) {
            return mid; // Found the target, return its index
        } else if (data[mid] < target) {
            left = mid + 1; // Target is in right half of array
        } else {
            right = mid - 1; // Target is in left half of array
        }
    }
    
    return -1; // Target not found
}