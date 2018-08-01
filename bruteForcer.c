#include <stdio.h>
#include <stdbool.h>
#include "bruteForcer.h"

enum oddoneOut twoEqual(int a, int b, int c){
    if(a == b && b != c)
        return OLDEST;
    if(a == c && b != c)
        return MIDDLE;
    if(b == c && a != c)
        return YOUNGEST;
    return NONE;
}

/*This functions either returns NONE if the number pos is invalid.
  If it is valid, then it returns the daughter who is COMMON across all of them
  meaning that she CANNOT be part of the final clue in the riddle
  */
enum oddoneOut checksout(int arr[][10], int pos){
    if(arr[pos][0] != 2)
        return NONE;
    if(arr[pos][1] == 1 && arr[pos][2] == 1) /*Oldest and Middle*/
        return YOUNGEST;
    if(arr[pos][1] == 1 && arr[pos][3] == 1) /*Oldest and Youngest*/
        return MIDDLE;
    if(arr[pos][2] == 1 && arr[pos][3] == 1) /*Middle and Youngest*/
        return OLDEST;
    return NONE;
}

void bruteForce(int end){
    int i, j, k;
    int arr[MAX_SIZE][10] = {{0}};
    /* The 10-sized array (which should really be replaced with a struct)
     * consists of:
       Number of total visits
       Number of visits from type Oldest
       Number of visits from type Middle
       Number of visits from type Youngest
       First three numbers
       Second three numbers
       For the purposes of this exercise, we will consider only cases
       where there is two viabilities - 
       */
    if (end * end * end > MAX_SIZE){
        fprintf(stderr, "ERROR: MAX SIZE EXCEEDED\n");
        return;
    }
    for(i=1; i < end; ++i){
        for(j=i; j < end; ++j){
            for(k=j; k < end; ++k){
                int prod = i * j * k;
                int sum = i + j + k;
                enum oddoneOut disparity = twoEqual(i,j,k);
                if(disparity != NONE){
                    if(!arr[prod][0]){
                        arr[prod][4] = i;
                        arr[prod][5] = j;
                        arr[prod][6] = k;
                        ++arr[prod][0];
                    } else if (arr[prod][0] == 1){
                        arr[prod][7] = i;
                        arr[prod][8] = j;
                        arr[prod][9] = k;
                    }
                    if(disparity == OLDEST)
                        ++arr[prod][1];
                    else if (disparity == MIDDLE)
                        ++arr[prod][2];
                    else 
                        ++arr[prod][3];
                    ++arr[prod][0];
                }
            }
        }
    }
    /*Loop through the array to see which ones have two or above*/
    for(i=0; i < MAX_SIZE; ++i){
        enum oddoneOut check = checksout(arr, i);
        if(check != NONE){
            printf("%4d: %2d, %2d, %2d & %2d %2d %2d", 
                    i, 
                    arr[i][4], arr[i][5], arr[i][6], 
                    arr[i][7], arr[i][8], arr[i][9]
                    );
        }
    }
}
