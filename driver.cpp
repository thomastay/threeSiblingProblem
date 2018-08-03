#include "threeSiblingSolver.hpp"
#include "getopt.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

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
    if (tripPair.size() == 1){
        if (tripPair.front()[0] == -1)
            cout << "No solution found" << endl;
        else
            cout << "Solver found more than one answer. This problem is invalid." << endl
                << "Sorry about that."
                << endl;
        return;
    }
    oddOneOut firstType = twoEqual(tripPair.front());

    cout << "Solved!" << endl;
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
    string ansTypeStr;
    if(ansType == oddOneOut::OLDEST)
        ansTypeStr = "eldest";
    else if(ansType == oddOneOut::YOUNGEST)
        ansTypeStr = "youngest";
    cout << "For the problem of siblings whose ages multiply to " << problem << ", " << endl;
    cout << "and the neighbor specified his " << ansTypeStr << " daughter," << endl;
    cout << "Solving ..." << endl << endl;

    /* Actual solving here */
    TripletVec tripPair = findPairofTriplets(problem, ansType);
    parseTripletVec(tripPair, problem, ansType);
}

int main(int argc, char** argv){
    std::ios::sync_with_stdio(false);
    bool toSolve = false;
    bool isSolveType = false;
    int solveNum;
    oddOneOut solveNumType;
    int option_index = 0, option = 0;

	// Don't display getopt error messages about options
	opterr = false;

	// use getopt to find command line options
	struct option longOpts[] = {
	{ "solve", required_argument, nullptr, 's' },
	{ "generate", required_argument, nullptr, 'g' },
	{ "type", required_argument, nullptr, 't' },
	{ "help", no_argument, nullptr, 'h' },
	{ "version", no_argument, nullptr, 'V' },
	};

	while ((option = getopt_long(argc, argv, "s:g:t:hv", longOpts, &option_index)) != -1) {
		switch (option) {

		case 's':
            toSolve = true;
            solveNum = atoi(optarg);
            break;

		case 't':
            isSolveType = true;
            /* Unsafe code please refactor. Converts to lowercase */
            for(char* ptr = optarg; *ptr; ++ptr)
                *ptr = tolower(*ptr);
            if(strcmp(optarg, "oldest") == 0)
                solveNumType = oddOneOut::OLDEST;
            else if(strcmp(optarg, "o") == 0)
                solveNumType = oddOneOut::OLDEST;
            else if(strcmp(optarg, "eldest") == 0)
                solveNumType = oddOneOut::OLDEST;
            else if(strcmp(optarg, "e") == 0)
                solveNumType = oddOneOut::OLDEST;
            else if(strcmp(optarg, "youngest") == 0)
                solveNumType = oddOneOut::YOUNGEST;
            else if(strcmp(optarg, "y") == 0)
                solveNumType = oddOneOut::YOUNGEST;
            else{
                cout << "Incorrect type entered." << endl
				<< "Usage:\tthreeSiblingSolver -s [NUMBER] -t [ANSWER-TYPE]" << endl
                ;
                exit(0);
            }
            break;

		case 'g':
            generate(atoi(optarg));
            return 0;

		case 'h':
			cout << "This program can do one of two things" << endl
                << "\t1. Solve the three Sibling Problem" << endl
                << "\t2. Generate solutions for the three Sibling Problem."<< endl
                << endl
				<< "Usage:\tthreeSiblingSolver -s [NUMBER] -t [ANSWER-TYPE]" << endl
				<< "or:\tthreeSiblingSolver -g [NUMBER]"
				<< std::endl;
			// Terminate the program, but it's not an error.
			exit(0);

		case 'v':
			cout << "threeSiblingSolver 0.1.0"<< endl
                << "Copyright (C) 2018 Thomas Tay." << endl
                << "This software is licenced under the MIT licence." << endl
                << "Versioning system: [MAJOR].[MINOR].[PATCH]" << endl
                ;
			// Terminate the program, but it's not an error.
			exit(0);
		} // switch
	} // while
    if(toSolve && isSolveType){
        solve(solveNum, solveNumType);
        return 0;
    }
    /* If nothing, display this help message */
    cout << "This program can do one of two things" << endl
        << "\t1. Solve the three Sibling Problem" << endl
        << "\t2. Generate solutions for the three Sibling Problem."<< endl
        << endl
        << "Usage:\tthreeSiblingSolver -s [NUMBER] -t [ANSWER-TYPE]" << endl
        << "or:\tthreeSiblingSolver -g [NUMBER]"
        << std::endl;



    return 0;
}
