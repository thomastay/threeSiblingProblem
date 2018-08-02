#include "threeSiblingSolver.hpp"
#include "getopt.h"
#include <iostream>
#include <iomanip>

using namespace std;
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

void printTriplet(vector<int>& triplet){
    cout << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << endl;
}

void parseTripletVec(TripletVec& tripPair, int problem, oddOneOut ansType){
    cout << "For the problem of siblings with ages " << problem << endl;
    if (tripPair.size() == 1){
        if (tripPair.front()[0] == -1)
            cout << "No solution found" << endl;
        else
            cout << "Found more than one answer!" << endl;
        return;
    }
    oddOneOut firstType = twoEqual(tripPair.front());

    cout << "The ages of the siblings are: ";

    if(firstType == oddOneOut::NONE)
        /* We are only able to distinguish NONE */
        printTriplet(tripPair.front());
    else if(firstType == ansType)
        /* We are guaranteed that secondType is NOT NONE by previous work */
        printTriplet(tripPair.front());
    else
        printTriplet(tripPair.back());
    return;
}

void generate(int end){
    PHash productHash = hashProducts(end);
    ResultHash result = findResult(productHash);
    printResult(result);
}

void solve(int problem, oddOneOut ansType){
    TripletVec tripPair = findPairofTriplets(problem, ansType);
    parseTripletVec(tripPair, problem, ansType);
}

int main(int argc, char** argv){
    int option_index = 0, option = 0;

	// Don't display getopt error messages about options
	opterr = false;

	// use getopt to find command line options
	struct option longOpts[] = {
	{ "solve", required_argument, nullptr, 's' },
	{ "generate", no_argument, nullptr, 'g' },
	{ "help", no_argument, nullptr, 'g' }
	};

	while ((option = getopt_long(argc, argv, "s:gh", longOpts, &option_index)) != -1) {
		switch (option) {

		case 's': {
            
		}

		case 'g': {
            
		}

		case 'h':
			std::cout << "To use this program, please enter arguments of the following form:\n"
				<< "-s [NUMBER] [ANSWER TYPE]"
				<< std::endl
				<< "-g"
				<< std::endl;
			// Terminate the program, but it's not an error.
			exit(0);
		} // switch
	} // while

    std::ios::sync_with_stdio(false);
    solve(900, oddOneOut::OLDEST);

    return 0;
}
