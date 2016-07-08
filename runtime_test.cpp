//
//  runtime_test.cpp
//  CS325_Proj1
//
//  Created by Linh Dao on 7/8/16.
//  Copyright © 2016 Linh Dao. All rights reserved.
//

#include <array>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mss.h"

void generate_rand_num(int count, int array[]) {
    for (int i = 0; i < count; i++) {
        array[i] = rand() % 200 - 100;
    }
}

double run_test (int algorithm, int count) {
    //struct timespec start, finish;
    float elapsed = 0;
    for (int i = 0; i < 10; i++) {
        int array[count];
        generate_rand_num(count, array);
        //start clock
        clock_t begin = clock();
        if (algorithm == 1)
            MaxSubarray_enum(array, count);
        else if (algorithm == 2)
            MaxSubarray_better_enum(array, count);
        clock_t end = clock();
        elapsed += double (end - begin) / CLOCKS_PER_SEC;   // return # of secs
    }
    return elapsed/10;
}