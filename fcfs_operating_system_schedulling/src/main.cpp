#include "FCFS.h"
#include <iostream>

int main()
{
    std::vector<std::pair<int, int>> processes = {{0, 3}, {2, 6}, {4, 4}};
    std::vector<double> avgMetrics = fcfs(processes);

    std::cout << "Average Completion Time: " << avgMetrics[0] << std::endl;
    std::cout << "Average Turn Around Time: " << avgMetrics[1] << std::endl;
    std::cout << "Average Waiting Time: " << avgMetrics[2] << std::endl;
    std::cout << "Throughput: " << avgMetrics[3] << std::endl;

    return 0;
}