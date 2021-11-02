/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/


 

//This header file sets up all the needed methods and libraies to make sure we can handle files reading/writing.
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H


//include input/output library for cin/cout and others
#include <iostream>
//enables us to read and write to files
#include <fstream>
//include DNAComplement library to conduct all necessary methods
#include "DNAComplement.h"

//includes the standard C++ library 
using namespace std;


//Class to handle all file processing
class FileProcessor{

public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //default destructor
    void processFile(string inOne); //void method that will read from a file and write the DNAComplements to the output file
    

};

#endif