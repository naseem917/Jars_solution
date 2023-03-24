#include "ProblemSet.h"
#include <iostream>
#include <stack>

bool ProblemSet::solveProblem()
{
	for (int i = 0; i < Jars.size(); i++)
		amounts.push_back(Jars[i].getAmount());

	std::pair<MyMapType::iterator, bool> result = tree_map.try_emplace(amounts, 1);
	queue_father.push(amounts);
	pour_queue.push(make_pair(-1, -1));
	for (int i = 0; i < Jars.size(); i++)
		for (int j = 0; j < Jars.size(); j++)
			if (i != j)
				if(Jars[i].getAmount())
					pour_queue.push(make_pair(i, j));

	vector<int> father_amounts = amounts;
	vector<Jar> Jars_father = Jars;

	while (!pour_queue.empty())
	{
		pair<int, int> current_pour = pour_queue.front();
		if (current_pour == make_pair(-1, -1))
		{
			father_amounts = queue_father.front();
			
			for (int i = 0; i < Jars.size(); i++)
				Jars_father[i].setAmount(father_amounts[i]);

			queue_father.pop();
			pour_queue.pop();
			continue;
		}
		amounts = father_amounts;
		Jars = Jars_father;

		if (!Jars[current_pour.first].pour(&Jars[current_pour.second]))
		{
			pour_queue.pop();
			continue;
		}
		amounts[current_pour.first] = Jars[current_pour.first].getAmount();
		amounts[current_pour.second] = Jars[current_pour.second].getAmount();

		std::pair<MyMapType::iterator, bool> result = tree_map.try_emplace(amounts, father_amounts);
		//std::pair<MyMapType::iterator, bool> result = tree_map.insert(make_pair(amounts, father_amounts));
		if (amounts == Dest)
			return true;

		if (result.second)
		{
			queue_father.push(amounts);
			pour_queue.push(make_pair(-1, -1));
			for (int i = 0; i < Jars.size(); i++)
				for (int j = 0; j < Jars.size(); j++)
					if (i != j)
						if (Jars[i].getAmount())
						{
							pour_queue.push(make_pair(i, j));
						}
			
		}
		pour_queue.pop();

	}
	return false;
}

void ProblemSet::print_solution()
{
	vector<int> temp = tree_map[amounts];
	stack<vector<int>> stack_output;
	stack_output.push(amounts);

	while (temp.size()!=1) 
	{
		stack_output.push(temp);
		temp = tree_map[temp];
	}

	while (!stack_output.empty())
	{
		temp = stack_output.top();
		stack_output.pop();

		for (auto i : temp)
			std::cout << i << ' ';
		std::cout << '\n';
	}
}
