#include "FCFS.h"
#include <unordered_map>
#include <cmath>

double roundToTwoDecimals(double num)
{
    return std::ceil(num * 100) / 100;
}

// Function accepts a vector of std::pair<int, int> as its parameter
// First elements of a pair is Arrival Time (AT), second element is Burst Time (BT)
// Function returns a vector of doubles which are the avg values of the processe's Completion Time(CT), Turn Around Time(TAT), Waitng Time(WT), Response Time(RT)
// and Throughput 
std::vector<double> fcfs(const std::vector<std::pair<int, int>>& processes)
{
    int arrSize { static_cast<int>(processes.size()) };

    if (arrSize == 0) 
    {
        return {0.0, 0.0, 0.0, 0.0};
    }

    std::vector<int> CT(arrSize);
    std::vector<int> TAT(arrSize);
    std::vector<int> WT(arrSize);

    int totalCT            {};
    int totalTAT           {};
    int totalWT            {};
    int totalThroughoutput {};
    int currentTime {};

    for(int i = 0; i < arrSize; ++i)
    {
        int AT { processes[i].first };
        int BT { processes[i].second };

        if(currentTime < AT)
            currentTime = AT;

        CT[i] = currentTime + BT;
        currentTime = CT[i];

        TAT[i] = currentTime - AT;
        WT[i] = TAT[i] - BT;

        totalCT += CT[i];
        totalTAT += TAT[i];
        totalWT += WT[i];
        totalThroughoutput += BT; 
    }

    double avgCT = totalCT / static_cast<double>(arrSize);
    double avgTAT = totalTAT / static_cast<double>(arrSize);
    double avgWT = totalWT / static_cast<double>(arrSize);
    double avgThroughput = totalThroughoutput / static_cast<double>(arrSize);

    return { roundToTwoDecimals(avgCT), roundToTwoDecimals(avgTAT), roundToTwoDecimals(avgWT), roundToTwoDecimals(avgThroughput) };
}