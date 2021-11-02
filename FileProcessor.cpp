/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/


//Handle the file processing necessary for the DNAComplement class


#include "FileProcessor.h"

//default constructor
FileProcessor::FileProcessor(){

}
//default destructor
FileProcessor::~FileProcessor(){

}

/** This will process the user's input file and conduct all the necessary DNAComplement functions and output into the proper dnaoutput.txt file
 * Param: string inOne representing the input the file
 */
void FileProcessor::processFile(string inOne){
    //Create a Translator object to be able to call the translation methods
    DNAComplement t;

    //String that holds the DNA from the input file
    string words;
    //string that holds the complement form of the DNA
    string complement;
    //string that holds the reverse complement of the DNA
    string reverseComp;
    
    
    //Input file: holds english words/sentences
    ifstream inFile(inOne);
    
    
    
   
    //Check if the input file is open to be read
    if(inFile.is_open()){
        //Output file: holds translated words/sentences
        ofstream resultText("dnaoutput.txt");
        //Read the file and translate them into results file
        while(getline(inFile, words)){
            
            //find complement of DNA strand and write into the results file
            complement = t.complement(words);
            resultText << complement << "\n";

            //find the reverse complement and write into the results file
            reverseComp = t.reverseComplement(complement);
            resultText << reverseComp << "\n";

            //create a space after every dna strand for readability
            resultText << "\n";
        }
        //close the input file to avoid memory issues
        inFile.close();
        //close the output file to avoid memory issues
        resultText.close();
    }
    //if the file cannot be opened output this error
    else{
        cout << "Unable to open file" << endl;
    }


    
}