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
void printAdjList(std::vector<std::list<int>> &path);
std::list<int>::iterator  find_gt(std::list<int>::iterator start, std::list<int>::iterator stop, int x);