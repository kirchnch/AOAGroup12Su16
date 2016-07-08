// enumeration.cpp
// Loop over each pair of indices i, j and compute the sum of the subarray A[i,...,j].
// Keep the best sum you have found so far

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

struct MSS_result MaxSubarray_enum(int array[], int arrayLength) {
    struct MSS_result result;
    result.maxSum = 0;
    result.leftEnd = 0;
    result.rightEnd = 0;
    
    for (int i = 0; i < arrayLength; i++) {
        for (int j = i; j < arrayLength; j++) {
            int index = i;
            int currentSum = 0;
            while (index <= j) {
                currentSum += array[index];
                index++;
            }
            if (currentSum > result.maxSum) {
                result.maxSum = currentSum;
                result.leftEnd = i;
                result.rightEnd = j;
            }
        }
    }
    return result;
}