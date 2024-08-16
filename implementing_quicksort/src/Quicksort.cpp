#include "Quicksort.h"
#include <iostream>

int Quicksort::partition(std::vector<int>& data, int low, int high, std::vector<std::vector<int>>& snapshots)
{
    int pivot = data[low];
        auto i = low + 1;
        auto j = high;
        while (true)
        {
            while (i <= j && data[i] <= pivot) i++;
            while (i <= j && data[j] >= pivot) j--;
            if (i > j) break;
            std::swap(data[i], data[j]);
            snapshots.push_back(data);
        }

        if (data[low] != data[j])
        {
            std::swap(data[low], data[j]);
            snapshots.push_back(data);
        }
        
        return j;
}

void Quicksort::quickSortRecursive(std::vector<int>& data, int low, int high, std::vector<std::vector<int>>& snapshots)
{
    if(low < high)
    {
        int pivotIndex { partition(data, low, high, snapshots) };

        quickSortRecursive(data, low, pivotIndex - 1, snapshots);
        quickSortRecursive(data, pivotIndex + 1, high, snapshots );
    }
}

std::vector<std::vector<int>> Quicksort::quicksort(std::vector<int>& data)
{
    std::vector<std::vector<int>> snapshots{};

    quickSortRecursive(data, 0, data.size() - 1, snapshots);

    return snapshots;
}

void Quicksort::printSnapshots(const std::vector<std::vector<int>>& snapshots) {
    int step = 0;
    for (const auto& snapshot : snapshots) {
        std::cout << "Step " << step++ << ": [ ";
        for (int value : snapshot) {
            std::cout << value << " ";
        }
        std::cout << "]\n";
    }
}