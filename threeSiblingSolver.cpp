#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map> 
#include <cassert>
#include "threeSiblingSolver.hpp"

using namespace std;

/*
 * Helper functions
 */
oddOneOut twoEqual(vector<int> v){
    if(v.size()!= 3){
        cerr << "Oh no! Something went wrong";
        assert(false);
    }
    int a,b,c;
    a=v[0]; b=v[1]; c=v[2];
    if(a == b && b != c)
        return oddOneOut::OLDEST;
    if(b == c && a != c)
        return oddOneOut::YOUNGEST;
    return oddOneOut::NONE;
}

/*
   This program determines if one of two vectors has the twoEqual thingy and
   returns the odd One out
*/
oddOneOut vecTwoEqual(const vector<vector<int>>& triplets){
    if(triplets.size()!= 2){
        cerr << "Oh no! Something went wrong";
        assert(false);
    }
    oddOneOut firstStatus = twoEqual(triplets.front());
    oddOneOut secondStatus = twoEqual(triplets.back());

    if(firstStatus == oddOneOut::NONE && secondStatus == oddOneOut::NONE){
        return oddOneOut::NONE;
    }
    if(firstStatus == secondStatus){
        cerr << "Oh no! Statuses are the same! This shouldn't be possible";
        assert(false);
        return oddOneOut::NONE;
    }
    if(firstStatus != oddOneOut::NONE){
        return firstStatus;
    }
    /* If we reach this point, then there's no way that both are none
       Also they are not the same
       Thus second status has to be legit
       */
    return secondStatus;
}

PHash hashProducts(int end){
    int i, j, k;
    /*Hashed by product, then sum, then a vector of triplet vectors */
    unordered_map<int, vector<vector<vector<int>>>> productHash;

    for(i=1; i < end; ++i){
        for(j=i; j < end; ++j){
            for(k=j; k < end; ++k){
                int prod = i * j * k;
                int sum = i + j + k;
                /* Initialize the vector which will be our hash table*/
                productHash[prod].resize(3 * end);
                productHash[prod][sum].push_back({i,j,k});
            }
        }
    }
    return productHash;
}

ResultHash findResult(const PHash& productHash){
    /* Find the stuff that satisfy two conditions
       1. Only two have the same sum (i.e. length of the vector is 2)
       2. One of them has that two_equals thing
       */
    ResultHash result;
    for(auto prodItr : productHash){
        for(auto sumItr : prodItr.second){ /* sumItr is a vector of vectors */
            if(sumItr.size() == 2 && vecTwoEqual(sumItr) != oddOneOut::NONE){
                //Satisified condition 1 and two
                /* result[key] is a vector of vectors */
                result[prodItr.first] = sumItr;
            }
        }

    }
    return result;
}

void printResult(const ResultHash& result){
    for (auto vv : result){ //Vector of vectors
        cout << setw(5) << vv.first << ": ";
        for(auto i : vv.second.front())
            cout << setw(2) << i << " ";
        cout << "& ";
        for(auto i : vv.second[1])
            cout << setw(2) << i << " ";
        cout << endl;
    }
}

/* Main program */

void solve(int end){
    PHash productHash = hashProducts(end);
    ResultHash result = findResult(productHash);
    printResult(result);
}
