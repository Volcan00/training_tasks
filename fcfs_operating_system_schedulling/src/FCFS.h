#ifndef FCFS_H
#define FCFS_H

#include <vector>

double roundToTwoDecimals(double num);

std::vector<double> fcfs(const std::vector<std::pair<int, int>>& processes);

#endif