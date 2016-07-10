//
//  mss.cpp
//  CS325_Proj1
//
//  Created by Linh Dao on 7/7/16.
//  Copyright © 2016 Linh Dao. All rights reserved.
//

#ifndef MSS_H
#define MSS_H

struct MSS_result {
    int maxSum;
    int leftEnd;
    int rightEnd;
};

struct MSS_result MaxSubarray_enum(int array[], int arrayLength);

struct MSS_result MaxSubarray_better_enum(int array[], int arrayLength);

struct MSS_result MaxSubarray_divideconquer(int array[], int arrayLength);

void generate_rand_num(int count, int array[]);

double run_test (int algorithm, int count);

#endif
