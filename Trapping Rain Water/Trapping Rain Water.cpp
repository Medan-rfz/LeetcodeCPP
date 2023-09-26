#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int get_deep(vector<int>::iterator begin, vector<int>::iterator end)
    {
        auto height = min(*begin, *end);
        int res = 0;
        begin++;
        while (begin < end)
        {
            res += height - *begin;
            begin++;
        }
        return res;
    }

    static int trap(vector<int>& height)
    {
        auto left = height.begin();
        auto right = height.end()-1;
        auto leftMax = height.begin();
        auto rightMax = height.end() - 1;
        int res = 0;

        while (left < right)
        {
            if (*left <= *right)
            {
                left++;
                leftMax = (*left > *leftMax) ? left : leftMax;
                res += *leftMax - *left;
            }
            else
            {
                right--;
                rightMax = (*right > *rightMax) ? right : rightMax;
                res += *rightMax - *right;
            }
        }
        return res;
    }
};

int main()
{
    //auto dataset = vector<int>{ 0 };
    //auto dataset = vector<int>{ 0,4 };
    auto dataset = vector<int>{ 4,2,0,3,2,5 };
    //auto dataset = vector<int>{ 0,1,0,2,1,0,1,3,2,1,2,1 };

    auto res = Solution::trap(dataset);

    return 0;
}

