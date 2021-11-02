/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/
 
//generic stack file


#ifndef GENSTACK_H
#define GENSTACK_H


#include <iostream>
#include <exception>
#include "GenLinkedList.h"

using namespace std;

template <typename T>
class GenStack{
    public:
        GenStack(); //default constructor
        ~GenStack(); //default destructor

        //core functions
        void push(T data); //push data onto the stack
        T pop(); //pop the first item in the stack

        //helper functions
        T peek(); //peek at the top of the stack and return the value
        int getSize(); //get the size of the stack
        bool isEmpty(); //is the stack empty?
       
    private:
        GenLinkedList<T> *list; //LinkedList that will be used to build the stack
        int mSize; //size of the stack

};

template <typename T>
/** Default constructor of data type T that will create a new LinkedList based stack
 *
 */
GenStack<T>::GenStack(){
    list = new GenLinkedList<T>(); //intialize LinkedList of data type T
    mSize = 0; //size is 0
}

template <typename T>
GenStack<T>::~GenStack(){
    delete list; //delete the LinkedList
}

template <typename T>
/** This is the method used to push data onto the stack
 * param: type T data represents the information to be pushed into the stack
 */
void GenStack<T>::push(T data){
    
    list->insertHead(data); //following the LIFO model the newest data should be at the top
    ++mSize; //increment size
}

template <typename T>
/** This method is used to pop the first item in the stack
 * return: type T representing the data removed from the top of the stack
 */
T GenStack<T>::pop(){
    if(isEmpty()){
        throw runtime_error("EMPTY STACK!!!");
    }
    T data = list->removeHead();
    --mSize;
    return data;
}


template <typename T>
/** This method lets the user look at the information at the top of the stack without removing it
 * return: type T representing the data at the top
 */
T GenStack<T>::peek(){
    //error check
    if(isEmpty()){
        throw runtime_error("EMPTY STACK!!!");
    }
    //peek at the data
    T data = list->removeHead();
    list->insertHead(data);
    return data;
}


template <typename T>
/** This method shows us the size of the stack
 * return: int representing the size of the stack
 */
int GenStack<T>::getSize(){
    return mSize;
}

template <typename T>
/** Method to check if the stack is empty
 * return: bool representing if the stack is empty (true) or not (false)
 */
bool GenStack<T>::isEmpty(){
    return (mSize == 0);
}


#endif