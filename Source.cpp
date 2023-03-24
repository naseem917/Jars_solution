#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Jar.h"
#include "ProblemSet.h"


int main(int argc, char* argv[])
{
	vector<int> newset = { 8, 5, 3 }; // jars capacity
	vector<int> Fullness = { 1, 0, 0 }; // intial status of empty and full jars
	vector<int> Dest = { 4, 4, 0 }; // destination status

	//vector<int> newset = { 12, 8, 5 , 3 }; // jars capacity
	//vector<int> Fullness = { 1, 0, 0, 0 }; // intial status of empty and full jars
	//vector<int> Dest = { 4, 4, 4, 0 }; // destination status

	//vector<int> newset = { 71, 61, 51 , 41, 31, 21, 11, 1 }; // jars capacity
	//vector<int> Fullness = { 1, 0, 0, 0, 0, 0, 0, 0 }; // intial status of empty and full jars
	//vector<int> Dest = { 10, 10, 10 , 10, 10, 10, 10, 1 }; // destination status

	ProblemSet problem1(newset, Fullness, Dest);
	if(problem1.solveProblem())
		problem1.print_solution();
	else 
		std::cout << "no solution found";
}