#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

class Solution
{
public:
    static vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        auto it = temperatures.begin();
        stack<vector<int>::iterator> s;
        vector<int> res(temperatures.size());

        while (it < temperatures.end())
        {
            while (!s.empty() && *s.top() < *it)
            {
                res[s.top() - temperatures.begin()] = it - s.top();
                s.pop();
            }
            s.push(it);
            it++;
        }
        return res;
    }
};

int main()
{
    vector<int> dataset{ 73,74,75,71,69,72,76,73 };
    //vector<int> dataset{ 55,38,53,81,61,93,97,32,43,78 };

    auto res = Solution::dailyTemperatures(dataset);

    return 0;
}
