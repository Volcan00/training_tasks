#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
class Quicksort
{
public:
    std::vector<std::vector<int>> quicksort(std::vector<int>& data);
    
    int partition(std::vector<int>& data, int low, int high, std::vector<std::vector<int>>& snapshots);

    void quickSortRecursive(std::vector<int>& data, int low, int high, std::vector<std::vector<int>>& snapshots);

    void printSnapshots(const std::vector<std::vector<int>>& snapshots);
};

#endif