#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target)
    {
        auto size = numbers.size();

        for (int i = 0, j = size - 1; i < j; )
        {
            if (numbers[i] + numbers[j] == target)
                return vector<int>{ i + 1, j + 1 };

            else if (numbers[i] + numbers[j] < target)
                i++;

            else
                j--;
        }

        return vector<int>();
    }
};


int main()
{
    auto dataset = make_pair<vector<int>, int>(vector<int>{ 2, 7, 11, 15 }, 9);

    auto res = Solution::twoSum(dataset.first, dataset.second);

    return 0;
}


