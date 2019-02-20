// Data Structures Project 1.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>

//prototypes

//print out passed vector, by line with line identified by list + position
void printAdjList(std::vector<std::list<int>> &path);

//find entry point to insert value into list
//return end otherwise
std::list<int>::iterator  find_gt(std::list<int>::iterator start, std::list<int>::iterator stop, int x);

//if there is a common element in both lists, return true otherwise false
// assumes lists are sorted in ascending order and elements are unique
bool connComponent(const std::list<int> &, const std::list<int> &);

//merges 2 lists, merging the smaller into the larger
//returns once successfully merged
bool merge2(std::list<int> &, std::list<int> &);