#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
#include <set>

using namespace std;

class Solution
{
public:
    static int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int res = 0;
        vector<pair<int, float>> tmp;

        tmp.reserve(position.size());
        for (int i = 0; i < position.size(); i++)
        {
            float time = (float)(target - position[i]) / (float)speed[i];
            tmp.push_back({ position[i], time });
        }
        
        sort(tmp.begin(), tmp.end(), std::greater<>());

        float prevTime = 0.0f;
        for (auto x : tmp)
        {
            if (prevTime < x.second)
            {
                prevTime = x.second;
                res++;
            }
        }

        return res;
    }
};

int main()
{
    tuple<int, vector<int>, vector<int>> dataset{ 12, vector<int> {10,8,0,5,3}, vector<int> {2,4,1,1,3} };
    //tuple<int, vector<int>, vector<int>> dataset{ 100, vector<int> {0,2,4}, vector<int> {4,2,1} };

    auto res = Solution::carFleet(get<0>(dataset), get<1>(dataset), get<2>(dataset));

    return 0;
}
