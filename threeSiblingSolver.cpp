#include <iostream>
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
oddOneOut vecTwoEqual(const TripletVec& triplets){
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
    PHash productHash;

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

bool feasibleTripletVec(const TripletVec& tripVec, oddOneOut ansType){
    assert(ansType != oddOneOut::NONE);
    if(tripVec.size() != 2)
        return false;
    oddOneOut firstState = twoEqual(tripVec.front());
    oddOneOut secondState = twoEqual(tripVec.back());
    if(firstState == secondState)
        return false;
    /* If the first is a NONE, then the second cannot be the same as the
     * ansType, because it means that there is no way to distinguish the two
     * The second one below is by symmetry
     */
    if(firstState == oddOneOut::NONE && secondState == ansType)
        return false;
    if(secondState == oddOneOut::NONE && firstState == ansType)
        return false;
    return true;
}

/* Finds the pair of triplets that correspond to the problem
 * If it can't return as its first pair of triplets: -1,-1,-1
 * Complexity is O(n^2)
 */
TripletVec findPairofTriplets(int num, oddOneOut ansType){
    /* First we start by factorizing the number
     * Then, we systematically generate triplets that correspond to some sum
     * Hash them in some vector by sum
     * Then, loop through the vector and see which numbers have a size = 2
     * Then, if it has a size greater than 2, check if it is feasible
     * We will define feasibility in the feasible() function
     * Then we save that to triplet Vec, and turn found to true
     * Then we continue looking. If found is true twice, then we return an error
     * and stop looking.
     */
    bool found = false;
    /* Hash of the triplets by sum
     * Consider changing to Vector
     */
    unordered_map<int, TripletVec> sumHash; 
    /* The answer vector */
    TripletVec resultVec = {{-1,-1,-1}};

    /* Factorize the number */
    for(int i = 1; i < num; ++i){
        for(int j = i; j < num; ++j){
            int k = (num / i) / j;
            if(k >= j && i*j*k == num){
                /* Then we have found a factor */
                int sum = i + j + k;
                sumHash[sum].push_back({i,j,k});
            }
        }
    }
    for(auto sumItr : sumHash){
        if(sumItr.second.size() == 2 && feasibleTripletVec(sumItr.second, ansType)){
            if(!found){
                found = true;
                resultVec = sumItr.second;
            } else{
                cerr << "Found more than one answer!" << endl;
                /* error condition */
                return {{-2,-1,-1}};
            }
        }
    }
    return resultVec;
}





