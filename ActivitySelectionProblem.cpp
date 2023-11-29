#include <iostream>
#include <vector>
#include <algorithm> // std::sort

// Optional to use: 
using intPair = std::pair<int, int>;

// Compare to achive ascending order and use it in std::sort
bool comp(const intPair& a, const intPair& b)
{
    return a.second < b.second;
}

int activitySelectionProblem(std::vector<intPair>& startFinishTimes) 
{
    // Sort in acsending order according to the finish times
    std::sort(startFinishTimes.begin(), startFinishTimes.end(), comp);

    int maxActivities = 0, currMaxFinishTime = 0;

    for(const auto& Pair : startFinishTimes)
    {
        // If the start time is later than the current finish time
        // the activity does not overlap another one so it can be performed
        if(Pair.first >= currMaxFinishTime) 
        {
            std::cout << "[" << Pair.first << ", " << Pair.second << "] ";

            currMaxFinishTime = Pair.second; // assign to the new finish time
            maxActivities++;
        }
    }

    std::cout << "\nThe max number of activities is: " << maxActivities << std::endl;

    return maxActivities;
}

/*
// Example input

int main() 
{
    std::vector<intPair> startFinishTimes = {{5, 9}, {1, 2}, {0, 6}, {5, 7}, {8, 9}, {3, 4}};

    activitySelectionProblem(startFinishTimes); 
    
    // Expected output: 
    // [1, 2] [3, 4] [5, 7] [8, 9]                                            
    // The max number of activities is: 4

    return 0;
}
*/