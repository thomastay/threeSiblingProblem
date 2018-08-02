#include <iostream>
#include <vector>
#include <unordered_map> 
#include "threePersonSolver.hpp"

using namespace std;

/*
 * Helper functions
 */
oddOneOut twoEqual(int a, int b, int c){
    if(a == b && b != c)
        return oddOneOut::OLDEST;
    if(a == c && b != c)
        return oddOneOut::MIDDLE;
    if(b == c && a != c)
        return oddOneOut::YOUNGEST;
    return oddOneOut::NONE;
}

void solve(int end){
    int i, j, k;
    if (end * end * end > MAX_SIZE){
        cerr << "ERROR: MAX SIZE EXCEEDED";
        return;
    }
    for(i=1; i < end; ++i){
        for(j=i; j < end; ++j){
            for(k=j; k < end; ++k){
                int prod = i * j * k;
                int sum = i + j + k;
            }
        }
    }
}
