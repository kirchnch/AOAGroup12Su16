/*Algorithm 3: Divide and Conquer. If we split the array into two halves, we know that the maximum subarray will either be
- Contained entirely in the first half,
- Contained entirely in the second half or
- Made of a suffix of the first half of the subarray and a prefix of the second half*/
#include <array>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "mss.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define MAX(a,b) (((a)>(b))?(a):(b))

//Returns the sum across left and second hald of the array
struct MSS_result MaxCrossingSum(int a[],int l,int mid,int h)
{
        struct MSS_result crossTempResult;
        crossTempResult.maxSum=0;

        //left
	int leftTempSum = 0;
	int leftSum = INT_MIN;
	for(int i=mid; i>=l; i--)
	{
		leftTempSum += a[i];
		if(leftTempSum > leftSum)
                {
                        leftSum = leftTempSum;
			crossTempResult.leftEnd = i;
		}
        }

        //right
	int rightTempSum = 0;
	int rightSum = INT_MIN;
	for(int i=mid+1; i<=h;i++)
	{
		rightTempSum += a[i];
                if(rightTempSum > rightSum)
                {
		     	rightSum = rightTempSum;
			crossTempResult.rightEnd = i;
                }
	}
        
        crossTempResult.maxSum = leftSum + rightSum;

	return crossTempResult;
}

//returns the maximum sum based on comparing the results from left, right and cross
struct MSS_result MaxSubArraySum(int a[],int l,int h)
{
        struct MSS_result base;
        struct MSS_result leftResult;
        struct MSS_result rightResult;
        struct MSS_result crossResult;

        base.maxSum =0 ;
        leftResult.maxSum=0;
        rightResult.maxSum=0;
        crossResult.maxSum=0;

        //base case
	if(l==h)
        {
                base.maxSum=a[l];
                base.leftEnd=l;
                base.rightEnd=h;
		return base;
	}
	int mid = (l+h)/2;

        leftResult = MaxSubArraySum(a,l,mid);
        rightResult = MaxSubArraySum(a,mid+1,h);
        crossResult = MaxCrossingSum(a,l,mid,h);

        //maximum sum       
        int MSS = MAX((MAX(leftResult.maxSum,rightResult.maxSum)),crossResult.maxSum);	

        if (MSS == leftResult.maxSum)
		return leftResult;
        else if (MSS == rightResult.maxSum)
                return rightResult;
        else
		return crossResult;
}

//returns result
struct MSS_result MaxSubarray_divideconquer(int array[],int arrayLength)
{
        struct MSS_result result;
	result.leftEnd=0;
        result.rightEnd=0;
        result.maxSum=0;     
 
        result = MaxSubArraySum(array,0,arrayLength-1);

        return result;
}
