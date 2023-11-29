#include <iostream>
#include <vector>
#include <algorithm>

// Optional to use: 
using intPair = std::pair<int, int>;

bool comp(const intPair& a, const intPair& b)
{
    return static_cast<double>(a.first / a.second > b.first / b.second);
}

int knapSackProblem(std::vector<intPair>& valueWeightList, int capacity)
{
    std::sort(valueWeightList.begin(), valueWeightList.end(), comp);

    int counter = 0;

    for(const auto& Pair : valueWeightList)
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
    std::vector<intPair> valueWeightList = {{100, 20}, {60, 10}, {120, 30}};
    int capacity = 50;

    int maxVal = knapSackProblem(valueWeightList, capacity); // Expected output is 160

    std::cout << "Solution to the KnapSack problem using Greedy approach is: " << maxVal << std::endl;

    return 0;
}
*/