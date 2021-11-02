/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/


#include "DNAComplement.h"
#include "RPNCalc.h"
#include "FileProcessor.h"
using namespace std;

int main(int argc, char** argv){
    string input;
    RPNCalc* rpn = new RPNCalc();
    DNAComplement* dna = new DNAComplement();
    cout << "Would you like to do \"RPN\" or \"DNA\" " << endl; 
    cin >> input;
    cin.ignore();
    
    //run the proper outcome given the user's input 
    if(input == "RPN"){
        rpn->run();
    }
    else if(input == "DNA"){
        dna->run();
    }
    else{
        cout << "INVALID SELECTION" << endl;
    }
    return -1;
}