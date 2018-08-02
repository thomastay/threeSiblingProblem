#ifndef THREEPERSONgenerateR
#define THREEPERSONgenerateR

#include <vector>
#include <map>
#include <unordered_map> 

enum class oddOneOut {NONE, OLDEST, YOUNGEST};
using TripletVec = std::vector<std::vector<int>>;
using PHash = std::unordered_map<int, std::vector<TripletVec>>;
using ResultHash = std::map<int, TripletVec>;

/*
 * Helper functions
 */
oddOneOut twoEqual(std::vector<int> v);

/* This program determines if one of two std::vectors has the twoEqual thingy and
   returns the odd One out 
   */
oddOneOut vecTwoEqual(const std::vector<std::vector<int>>& triplets);

/*
 * Main programs
 */

/* In the range [1,end), it creates a Hash of vectors of TripletVectors, hashed
 * by product, then sum 
 */
PHash hashProducts(int end);

/* Given a product Hash, it finds the relevant results and returns it in a hash
 * that is hashed by product
 */
ResultHash findResult(const PHash& productHash);

/* Finds the pair of triplets that correspond to the problem
 * If it can't return as its first pair of triplets: -1,-1,-1
 */
TripletVec findPairofTriplets(int num, oddOneOut ansType);

#endif
