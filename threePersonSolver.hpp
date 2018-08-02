#ifndef THREEPERSONSOLVER
#define THREEPERSONSOLVER

#include <vector>
#include <map>
#include <unordered_map> 
enum class oddOneOut {NONE, OLDEST, YOUNGEST};
using PHash = std::unordered_map<int, std::vector<std::vector<std::vector<int>>>>;
using ResultHash = std::map<int, std::vector<std::vector<int>>>;

/*
 * Helper functions
 */
oddOneOut twoEqual(std::vector<int> v);

/*
   This program determines if one of two std::vectors has the twoEqual thingy and
   returns the odd One out
*/
oddOneOut vecTwoEqual(const std::vector<std::vector<int>>& triplets);

/*
 * Main programs
 */

PHash hashProducts(int end);

ResultHash findResult(const PHash& productHash);

void printResult(const ResultHash& result);

/* Main program */

void solve(int end);

#endif
