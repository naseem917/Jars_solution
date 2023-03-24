#pragma once
#include "Jar.h"
#include <vector>
#include <queue>
//#include <unordered_map>
#include <map>

using namespace std;
typedef map<vector<int>, vector<int>> MyMapType;

class ProblemSet
{
public:
	ProblemSet(vector<int> Capacity, vector<int> fullness, vector<int> in_Dest)
	{
		Dest = in_Dest;
		for (int i = 0; i < Capacity.size(); i++)
			Jars.push_back(Jar(Capacity[i], fullness[i]));
	}
	bool solveProblem();
	void print_solution();

private:
	vector<Jar> Jars;
	vector<int> Dest;
	vector<int> amounts;
	queue<pair<int, int>> pour_queue;
	queue<vector<int>> queue_father;
	map<vector<int>, vector<int>> tree_map;
};

