#include <stdio.h>
#include <stdbool.h>
#include "bruteForcer.h"

bool twoEqual(int a, int b, int c){
    if(a == b && b != c)
        return true;
    if(a == c && b != c)
        return true;
    if(b == c && a != c)
        return true;
    return false;
}

void bruteForce(int end){
    int i, j, k;
    int arr[MAX_SIZE][7] = {{0}};
    /* The 7-sized array consists of
       Number of visits
       First three numbers
       Second three numbers
       */
    if (end * end * end > MAX_SIZE){
        fprintf(stderr, "ERROR: MAX SIZE EXCEEDED\n");
        return;
    }
    for(i=1; i < end; ++i){
        for(j=i; j < end; ++j){
            for(k=j; k < end; ++k){
                int prod = i * j * k;
                if(twoEqual(i,j,k)){
                    if(!arr[prod][0]){
                        arr[prod][1] = i;
                        arr[prod][2] = j;
                        arr[prod][3] = k;
                    } else if (arr[prod][0] == 1){
                        arr[prod][4] = i;
                        arr[prod][5] = j;
                        arr[prod][6] = k;
                    }
                    ++arr[prod][0];
                }
            }
        }
    }
    /*Loop through the array to see which ones have two or above*/
    for(i=0; i < MAX_SIZE; ++i){
        if(arr[i][0] > 1){
            printf("%4d: %2d, %2d, %2d & %2d %2d %2d\n", i, arr[i][1], arr[i][2],
                    arr[i][3], arr[i][4], arr[i][5], arr[i][6]);
        }
    }
}
