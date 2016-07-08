// better_enumeration.cpp
// A smarter version of enumeration

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

struct MSS_result MaxSubarray_better_enum(int array[], int arrayLength) {
    struct MSS_result result;
    result.maxSum = 0;
    result.leftEnd = 0;
    result.rightEnd = 0;
    
    for (int i = 0; i < arrayLength; i++) {
        int currentSum = 0;
        for (int j = i; j < arrayLength; j++) {
            currentSum += array[j];
            
            if (currentSum > result.maxSum) {
                result.maxSum = currentSum;
                result.leftEnd = i;
                result.rightEnd = j;
            }
        }
    }
    return result;
}