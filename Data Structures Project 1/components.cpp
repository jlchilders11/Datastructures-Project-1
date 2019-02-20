// Data Structures Project 1.cpp : Defines the entry point for the application.
//

#include "components.h"

int main()
{
	std::string graph_name;
	std::cout << "Please enter your data file name: ";
	std::cin >> graph_name;

	std::ifstream graph_file (graph_name);

	//if file exists and openable
	if (graph_file.is_open())
	{
		std::vector<std::list<int>> adjList;
		std::string str;

		//build initial vector of lists
		while (std::getline(graph_file, str))
		{

			std::list<int> mtLst;
			std::istringstream ss(str);
			std::string c;
			while (std::getline(ss, c, ' '))
			{
				mtLst.insert(find_gt(mtLst.begin(), mtLst.end(), std::stoi(c)), std::stoi(c));
			}
			adjList.push_back(mtLst);
		}

		int a , b;

		//main loop
		while (1)
		{
			printAdjList(adjList);

			std::cout << "Enter two list ids to potentially merge together or -1 to quit: ";
			std::cin >> a;

			if (a == -1)
				break;
			std::cin >> b;

			//indexes must be positive
			if (a < 0 || b < 0)
				std::cout << "Both list numbers must be positive.";
			else
			{

				//merge smaller into larger, if able
				if (adjList[a].size() > adjList[b].size())
				{
					if (merge2(adjList[b], adjList[a]))
					{
						adjList.erase(adjList.begin() + b);
						std::cout << "The lists are merged." << std::endl;
					}
					else
						std::cout << "The lists are not merged." << std::endl;
				}
				else
				{
					if (merge2(adjList[a], adjList[b]))
					{
						adjList.erase(adjList.begin() + a);
						std::cout << "The lists are merged." << std::endl;
					}
					else
						std::cout << "The lists are not merged." << std::endl;
				}
			}
		}
	}

	//if file name is incorrect, let user know and exit
	else
	{
		std::cout << "That file does not exist. ";
		std::system("pause");
	}

	return 0;
}

void printAdjList(std::vector<std::list<int>> &path)
{
	std::cout << "The adjacency list for your graph is:" << std::endl;
	for (auto i = path.begin(); i != path.end(); ++i)
	{
		std::cout << "list" << i - path.begin() << " ";
		for (auto it = i->begin(); it != i->end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::list<int>::iterator  find_gt(std::list<int>::iterator start, std::list<int>::iterator stop, int x)
{
	for (auto it = start; it != stop; ++it)
	{
		if (*it > x)
		{
			return it;
		}
	}
	return stop;
}

bool connComponent(const std::list<int> &list1, const std::list<int> &list2)
{
	std::list<int>::const_iterator it1 = list1.begin();
	std::list<int>::const_iterator it2 = list2.begin();

	while (it1 != list1.end() && it2 != list2.end())
	{
		if (*it1 == *it2)
			return true;
		else if (*it1 > *it2)
			it2++;
		else
			it1++;
	}
	return false;
}

bool merge2(std::list<int> &list1, std::list<int> &list2)
{
	if (connComponent(list1, list2))
	{
		for (auto it = list1.begin(); it != list1.end(); ++it)
		{
			list2.insert(find_gt(list2.begin(), list2.end(), *it), *it);
		}
		list2.unique();
		return true;
	}
	else
		return false;
}