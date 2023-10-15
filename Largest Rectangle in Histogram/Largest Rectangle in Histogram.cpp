#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
    static int largestRectangleArea(vector<int>& heights)
    {
        int res = 0;
        stack<pair<int, int>> stk;

        for (int i = 0; i < heights.size(); i++)
        {
            auto tmp = i;

            while (!stk.empty() && stk.top().second > heights[i])
            {
                int indx = stk.top().first;
                int sq = (i - indx) * stk.top().second;
                stk.pop();
                res = max(res, sq);
                tmp = indx;
            }

            stk.push({tmp, heights[i]});
        }

        while (!stk.empty())
        {
            int sq = (heights.size() - stk.top().first) * stk.top().second;
            stk.pop();
            res = max(res, sq);
        }

        return res;
    }
};

int main()
{
    vector<int> dataset { -1,0,3,5,9,12 };

    auto res = Solution::largestRectangleArea(dataset);

    return 0;
}
