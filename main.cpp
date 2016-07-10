#include <array>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "mss.h"

using namespace std;

void run_algorithm (int algorithm) {
    // open input file
    ifstream inputFile;
    inputFile.open("MSS_Problems.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file";
    }
    
    //open output file
    ofstream outputFile;
    if (algorithm == 1)
        outputFile.open("MSS_Results.txt"); // open a new file for output
    else
        outputFile.open("MSS_Results.txt", ios::app);   // append the existing output file
    
    if (algorithm == 1)
        outputFile << "Algorithm 1: Enumeration" << endl;
    else if (algorithm == 2)
        outputFile << "Algorithm 2: Better Enumeration" << endl;
    else if (algorithm == 3)
        outputFile << "Algorithm 3: Divide and Conquer" << endl;
    else if (algorithm == 4)
        outputFile << "Algorithm 4: Linear Time" << endl;
    
    // read each line in input file as an array of integers and process that array
    string line;
    while (getline(inputFile, line)) {
        
        // count the number of elements in the array, which is the number of commas plus 1
        size_t commaCount = count(line.begin(), line.end(), ',');
        int intCount = (int)commaCount + 1;
        
        //initialize the input array
        int inputArray[intCount];
        
        outputFile << line << endl; //print original array to output file
        std::stringstream ss(line);
        
        int currentNum; //read into currentNum
        int index=0;
        
        if (ss.peek() == '[')
            ss.ignore();//ignore open bracket
        while (ss >> currentNum)
        {
            inputArray[index]=currentNum;
            index++;
            
            if (ss.peek() == ',' || ss.peek()==' ')
                ss.ignore();
        }
        
        //processing the arrays
        //***TODO: adding cases for algorithms 3 and 4****
        struct MSS_result result;
        if (algorithm == 1) {
            result = MaxSubarray_enum(inputArray, intCount);}
        else if (algorithm == 2){
            result = MaxSubarray_better_enum(inputArray, intCount);}
        else if (algorithm == 3){ 
            result = MaxSubarray_divideconquer(inputArray, intCount);}
      
        //writing result to the output file
        outputFile << "[";
        for (int i = result.leftEnd; i <= result.rightEnd; i++) {
            outputFile << inputArray[i];
            if (i != result.rightEnd)
                outputFile << ", ";
            else
                outputFile << "]" << endl;
        }
        
        outputFile << result.maxSum << endl << endl;
    }
    
    inputFile.close();
    outputFile.close();
}

int main(int argc, const char * argv[]) {
    run_algorithm(1);
    run_algorithm(2);
    run_algorithm(3); 
    return 0;
}
