/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/


#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H


#include <iostream>
#include <sstream>
#include <exception>
#include "GenStack.h"
#include "FileProcessor.h"


using namespace std;

class DNAComplement{
    public:
        DNAComplement(); //constructor
        ~DNAComplement(); //destructor
        string complement(string dnaStrand); //find complement given a dna string
        string reverseComplement(string c); //find the reverseComplement (aka the complement string in reverse) given the complement
        void run(); //implements the user interface and takes in necessary information

};


#endif