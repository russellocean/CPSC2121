/*
 * Name: Russell Welch
 * Date Submitted: 1/23/23
 * Lab Section: 001
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  while(size() != 0) {
    removeEnd();
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if(size() == 0)
    return true;
  return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T>* tempStart = new Node<T>(value);
  tempStart->next = start;
  start = tempStart;
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> * end = new Node<T>(value);

  Node<T> * iterator = start;
  if(iterator == nullptr){
    start = end;
    mySize++;
    return;
  }
  while(iterator->next != nullptr)
    iterator = iterator->next;

  iterator->next = end;
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> * iterator = start;
  
  if (j == 0)
    insertStart(value);
  else if (j == size())
    insertEnd(value);
  else {
    for(int i = 0; i < j - 1; i++)
      iterator = iterator->next;
    Node<T> * temp = new Node<T>(value);
    temp->next = iterator->next;
    iterator->next = temp;
    mySize++;
  }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node<T> * iterator = start;
  start = iterator->next;
  delete iterator;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> * iterator = start;
  if(iterator->next == nullptr){
    delete iterator;
    start = nullptr;
    mySize--;
    return;
  }
  while(iterator->next->next != nullptr)
    iterator = iterator->next;

  delete iterator->next;
  iterator->next = nullptr;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> * iterator = start;
  if(j == 0)
    removeStart();
  else if(j == size() - 1)
    removeEnd();
  else {
    for(int i = 0; i < j - 1; i++)
      iterator = iterator->next;
    Node<T> * temp = iterator->next;
    iterator->next = temp->next;
    delete temp;
    mySize--;
  }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  Node<T> * iterator = start;
  while(iterator->next != nullptr)
    iterator = iterator->next;

  return iterator->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> * iterator = start;
  for(int i = 0; i < j; i++)
    iterator = iterator->next;

  return iterator->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> * iterator = start;
  for(int i = 0; i < size(); i++) {
    if(iterator->value == key)
      return i;
    iterator = iterator->next;
  }
  return -1;
}
