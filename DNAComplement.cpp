/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/

//This program takes dna strands and creates their complement and reverse complement

//include its respective header file
#include "DNAComplement.h"

/** Default constructor
 */
DNAComplement::DNAComplement(){

}
/** Default destructor
 */
DNAComplement::~DNAComplement(){

} 

/** A method that reverses the complement of the original DNA strand given
 * param: string dnaStrand represents the original dna 
 * return: string returned representing the complement of the DNA string provided
 */
string DNAComplement::complement(string dnaStrand){
    //string that represents the complement
    string c = "";
    //loop and find the complements
    char input;
    istringstream dna(dnaStrand);
    //test if the stream was successful 
    while(dna){
        dna >> input;
        //if stream is not empty
        if(dna){
            if(input == '\n'){
                continue;
            }
            if(input == 'A'){
                c += "T";
            }
            else if(input == 'T'){
                c += "A";
            }
            else if(input == 'C'){
                c += "G";
            }
            else if(input == 'G'){
                c += "C";
            }
            else{
                string d = "";
                d += input;
                cout << d << endl;
                throw runtime_error("INVALID DNA CHARACTER...EXITING PROGRAM...PLEASE TRY AGAIN");
            }
        }
        
    }

    return c;
}


/** A method that reverses the complement of the original DNA strand given
 * param: string c represents the complement to be reversed
 * return: string returned representing the reverse of the complement string
 */
string DNAComplement::reverseComplement(string c){
    GenStack<char>* stack = new GenStack<char>();
    for(int i = 0; i < c.length(); ++i){
        stack->push(c[i]);
    }
    string reverse = "";
    while(stack->getSize() > 0){
        reverse += stack->pop();
    }

    delete stack;
    return reverse;
}

/** This is thr run method that asks the user for all the necessary information
 *
 */
void DNAComplement::run(){
    cout << "Welcome to the DNAComplement program" << endl;
    cout << "Please provide a valid file to be read from" << endl;
    string in;
    cin >> in;
    FileProcessor *fp = new FileProcessor();
    fp->processFile(in);
    delete fp;

}