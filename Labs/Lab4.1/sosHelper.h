#ifndef SOSHELPER_H
#define SOSHELPER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

typedef void sorting_algo(std::vector<int> &nums);

std::vector<std::vector<int> > getArrays(std::string fileName);
void code_to_time();
double measureTime(sorting_algo algorithm, std::vector<int> &nums);
void output(std::vector<double> data, std::string filename);

#endif