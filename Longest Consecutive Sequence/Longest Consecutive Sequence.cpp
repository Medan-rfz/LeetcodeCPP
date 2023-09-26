#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) 
    {
        set<int> sortedData;
        int prev, curr, len = 0, maxLen = 0;

        if (nums.size() == 0) return 0;

        for (auto x : nums)
            sortedData.insert(x);

        prev = *sortedData.begin();
        for (auto x : sortedData)
        {
            curr = x;
            if (curr == (prev + 1) || curr == prev)
            {
                len++;
            }
            else
            {
                maxLen = (maxLen < len) ? len : maxLen;
                len = 1;
            }

            prev = curr;
        }

        maxLen = (maxLen < len) ? len : maxLen;
        return maxLen;
    }
};


int main()
{
    //vector<int> dataset { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    //vector<int> dataset { 100, 4, 200, 1, 3, 2 };
    vector<int> dataset { 9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6 };
    //vector<int> dataset {  };

    auto res = Solution::longestConsecutive(dataset);

    return 0;
}


