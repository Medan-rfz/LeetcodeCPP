#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool static containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numbers;

        for (auto x : nums)
        {
            if (numbers.count(x) != 0) return true;
            numbers.insert(x);
        }

        return false;
    }
};


int main()
{
    vector<int> dataset { 1, 1, 3, 4, 7, 8, 9, 3 };

    Solution::containsDuplicate(dataset);

    return 0;
}


