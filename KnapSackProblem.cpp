#include <iostream>
#include <vector>
#include <algorithm>

bool comp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return static_cast<double>(a.first / a.second > b.first / b.second);
}

int knapSackProblem(std::vector<std::pair<int, int>> valueWeightList, int capacity)
{
    std::sort(valueWeightList.begin(), valueWeightList.end(), comp);

    int counter = 0;

    for(std::pair Pair : valueWeightList)
    {
        if(Pair.second <= capacity)
        {
            capacity -= Pair.second;
            counter += Pair.first;            
        }
    }

    return counter;
}

/*
//Example input

int main()
{
    std::vector<std::pair<int, int>> valueWeightList = {{100, 20}, {60, 10}, {120, 30}};
    int capacity = 50;

    int maxVal = knapSackProblem(valueWeightList, capacity); // Expected output is 160

    std::cout << "Solution to the KnapSack problem using Greedy approach is: " << maxVal << std::endl;

    return 0;
}
*/