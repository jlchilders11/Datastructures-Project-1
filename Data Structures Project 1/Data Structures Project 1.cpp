// Data Structures Project 1.cpp : Defines the entry point for the application.
//

#include "Data Structures Project 1.h"

int main()
{
	std::string graph_name;
	std::cout << "Please enter your data file name: ";
	std::cin >> graph_name;

	std::ifstream graph_file (graph_name);

	if (graph_file.is_open())
	{
		std::vector<std::list<int>> adjList;
		std::string str;

		while (std::getline(graph_file, str)) 
		{

			std::list<int> mtLst;
			std::istringstream ss(str);
			std::string c;
			while (std::getline(ss, c, ' ')) 
			{
				mtLst.push_back(std::stoi(c));
			}
			adjList.push_back(mtLst);
		}

		printAdjList(adjList);

		std::string terminator = "0";
		while (terminator != "-1")
		{
			std::cout << "Enter graphs to merge, or -1 to exit: ";
			std::cin >> terminator;
		}
	}
	else
	{
		std::cout << "That file does not exist. ";
		std::system("pause");
	}

	
	return 0;
}

//print out passed vector, by line with line identified by list + position
void printAdjList(std::vector<std::list<int>> &path)
{
	for (auto i = path.begin(); i != path.end(); ++i)
	{
		std::cout << "list" << i - path.begin() << " ";
		for (auto it = i->begin(); it != i->end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}