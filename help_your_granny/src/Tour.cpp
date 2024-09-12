#include "Tour.h"
#include <cmath>
#include <algorithm>

// Typedef for a map of town distances
using stringdblmap = std::unordered_map<std::string, double>;

int Tour::tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h) {
    // Map friend names to their corresponding towns
    std::unordered_map<std::string, std::string> friendTowns {};
    for (const auto &ft : ftwns) {
        friendTowns[ft[0]] = ft[1]; // ft[0] is the friend's name, ft[1] is the town
    }

    double totalDistance { 0.0 };
    std::string lastTown { "X0" }; // Start at Granny's town (X0)
    double lastTownDistance { 0.0 };

    for (const auto &friendName : arrFriends) {
        // Check if the friend has a known town
        if (friendTowns.find(friendName) == friendTowns.end()) {
            continue; // Skip if town not known
        }

        std::string currentTown { friendTowns[friendName] };

        // Ensure the current town is in the distance map
        if (h.find(currentTown) == h.end()) {
            continue; // Skip if distance data not available
        }

        double currentTownDistance { h[currentTown] };

        // Apply the Pythagorean theorem to calculate the distance between two towns
        double segmentDistance {sqrt(pow(currentTownDistance, 2) - pow(lastTownDistance, 2)) };

        // Add the distance to the total
        totalDistance += segmentDistance;

        // Update the last visited town and its distance
        lastTown = currentTown;
        lastTownDistance = currentTownDistance;
    }

    // Add the distance from the last visited town back to X0 (Granny's town)
    totalDistance += lastTownDistance;

    // Return the floored total distance as an integer
    return static_cast<int>(totalDistance);
}
