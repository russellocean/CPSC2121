/*
 * Name: Russell Welch
 * Date Submitted: 02/20/23
 * Lab Section: 001
 * Assignment Name: Lab 4 - Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib> // for rand() function

template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right){
    std::vector<T> result;
    int i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    
    return result;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    if (lst.size() <= 1) {
        return lst; // Base case: list is already sorted
    }
    
    int mid = lst.size() / 2;
    std::vector<T> left, right;
    
    for (int i = 0; i < mid; i++) {
        left.push_back(lst[i]);
    }
    
    for (int i = mid; i < lst.size(); i++) {
        right.push_back(lst[i]);
    }
    
    left = mergeSort(left); // Recursively sort left half
    right = mergeSort(right); // Recursively sort right half
    
    return merge(left, right); // Merge sorted sub-lists
}

template <class T>
void quickSortHelper(std::vector<T>& lst, int left, int right) {
    if (left < right) {
        int pivotIndex = rand() % (right - left + 1) + left; // Choose random pivot index
        T pivotValue = lst[pivotIndex];
        std::swap(lst[pivotIndex], lst[right]); // Move pivot to end
        int storeIndex = left;
        
        for (int i = left; i < right; i++) {
            if (lst[i] < pivotValue) {
                std::swap(lst[i], lst[storeIndex]);
                storeIndex++;
            }
        }
        
        std::swap(lst[storeIndex], lst[right]); // Move pivot to its final place
        
        quickSortHelper(lst, left, storeIndex - 1); // Recursively sort left side
        quickSortHelper(lst, storeIndex + 1, right); // Recursively sort right side
    }
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    quickSortHelper(lst, 0, lst.size() - 1); // Sort the entire list
    return lst;
}