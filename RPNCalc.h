/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/

#ifndef RPNCALC_H
#define RPNCALC_H


#include <iostream>
#include <exception>
#include <sstream>
#include "GenStack.h"

using namespace std;


class RPNCalc{
    public:
        RPNCalc(); //default constructor
        ~RPNCalc(); //default destructor
        void run(); //run method to handle how the user interface
        int calculate(string in); //calculate the user's answer
        string justNumbers(string in); //convert a user's string into just a string of numbers
       
    private:
        int numberOfInts(string in); //return the number of integers provided by the user
        int numberOfOperators(string in); //return the number of operators provided by the user's input string
        string input; //represents the user input
};


#endif