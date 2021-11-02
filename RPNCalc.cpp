/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 4 
 **/


//program that adheres to the RPN rules and provides the answers


#include "RPNCalc.h"


/** Default constrcutor
 */
RPNCalc::RPNCalc(){
}

/** Default destructor
 */
RPNCalc::~RPNCalc(){
  
}

/** This method asks for the user for all the necessary inputs to conduct the calculations
 */
void RPNCalc::run(){

    cout << "Welcome to the RPN calculator" << endl;
    cout << "Please provide the equation" << endl;
    
    getline(cin, input);
    char c = input[input.length() - 1];
    
    //figure out how many ints were provided by the user
    int nums = numberOfInts(input);
    //figure out how many operators were provided by the user
    int ops = numberOfOperators(input);
  
    //the last character in the string must be an operator for the equation to be a valid one
    if(c != '-' && c != '+' && c != '/' && c != '*'){
        cout << "INVALID POSTFIX EQUATION: MISSING AN OPERATOR...PLEASE TRY AGAIN" << endl;
        
        
    }
    else{
        //if there are too many operators provided then it is invalid
        if(ops > nums){
            cout << "TOO MANY OPERATORS PROVIDED" << endl;
        }
        //if the number of operators and number provided are the same then it is invalid
        else if(ops == nums){
            cout << "INVALID INPUT: The number of operators and numbers are the same" << endl;
        }
        //if the difference between numbers provided and operators provided is 1 then it is a valid input
        else if((nums - ops) == 1){
            calculate(input);
        }
        //if there are other extreanous cases not accounted for then it will automatically be an invalid input
        else{
            cout << "INVALID INPUT" << endl;
        }
    }

}


/** this method will conduct all the calcuations necessary for the users input string
 * param: string in represents the user's input
 * return: an int representing the user's answer to their given equation
 */
int RPNCalc::calculate(string in){
    //string of the numbers provided by the user
    string nums = justNumbers(in);
    //stack containing the numbers/answers
    GenStack<int> *stack = new GenStack<int>();
    
    int val; //hold a number from the user input that will be pushed onto the stack
    istringstream stream(nums); //stream of the user input that will be used to conduct the calculations

    //valOne and valTwo represent the variables that will hold the numbers for the arithmetic operations
    int valOne;
    int valTwo;
    
    for(int i = 0; i < in.length(); ++i){       
        
        //skip any space characters
        if(in[i] == ' '){
            continue;
        }
        //check if the given position is a subtraction sign
        if(in[i] == '-'){
            valTwo = stack->pop();
            valOne = stack->pop();
            stack->push(valOne - valTwo);

        }
        //check if the given position is a addtion sign
        else if(in[i] == '+'){

            valTwo = stack->pop();
            valOne = stack->pop();
            stack->push(valOne + valTwo);

        }
        //check if the given position is a division sign
        else if(in[i] == '/'){

            valTwo = stack->pop();
            valOne = stack->pop();

            stack->push(valOne / valTwo);

        }
        //check if the given position is a multiplication sign
        else if(in[i] == '*'){

            valTwo = stack->pop();
            valOne = stack->pop();
            stack->push(valOne * valTwo);
            

        }
        //else add a number (if possible) to the stack
        else{
            //store the user value into a double and then truncate it (if necessary)
            double v;
            //pass the value into the variable v
            stream >> v;
            //regardless of the number given by the user it must be truncated into an integer value
            val = (int) v;
            if(stream){ //as long as the stream has not ended then push the value onto the stack
              
                //push the number onto the stack
                stack->push(val);
                
            }
            
           
        }
    }
    int ans = stack->pop();
    //output the user's final answer
    cout << ans << endl;
    //clear memory
    delete stack;
    //return answer   
    return ans; 
}

/** Take the user's input string and create a string of just numbers
 * param: string in represents the users input
 * return: a string of only the numbers in the user input
 */
string RPNCalc::justNumbers(string in){
    string ans = "";
    for(int i = 0; i < in.length(); ++i){
        if(in[i] != '-' && in[i] != '+' && in[i] != '/' && in[i] != '*'){
            ans += in[i];
            
        }
    }
    return ans;
}

/** Take the user's input string and return the number of ints in the string
 * param: string in represents the users input
 * return: an int representing the numbers in the string
 */
int RPNCalc::numberOfInts(string in){
    int numberOfInts = 0;
    string nums = justNumbers(in);
    for(int i = 0; i < in.length(); ++i){
        if(in[i] >= '0' && in[i] <= '9' && (in[i + 1] == ' ')){
            numberOfInts += 1;
        }
    }
    return numberOfInts;
}



/** Take the user's input string and return the number of operators in the string
 * param: string in represents the users input
 * return: an int representing the operators in the string
 */
int RPNCalc::numberOfOperators(string in){
    int numberOfOps = 0;

    for(int i = 0; i < in.length(); ++i){
        if(in[i] == '-' || in[i] == '+' || in[i] == '/' || in[i] == '*'){
            numberOfOps += 1;
        }
    }
    return numberOfOps;

}