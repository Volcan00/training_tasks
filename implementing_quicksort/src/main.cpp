#include "Quicksort.h"
#include <iostream>

int main()
{
    std::vector<int> data = {30, 50, 5, 30, 51, 10, 20, 99, 18, 30, 100, 33};

    Quicksort q {};
    std::vector<std::vector<int>> snapshots = q.quicksort(data);
    q.printSnapshots(snapshots);

    return 0;
}