#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    static vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> freqs;
        priority_queue<pair<int, int>> queue;

        for (auto x : nums)
            freqs[x]++;

        for (auto x : freqs)
            queue.push({x.second, x.first});

        for (int i = 0; i < k; i++)
        {
            res.push_back(queue.top().second);
            queue.pop();
        }

        return res;
    }
};

int main()
{
    vector<int> dataset {1, 1, 1, 2, 2, 3};
    //vector<int> dataset {1, 1};

    auto res = Solution::topKFrequent(dataset, 2);

    return 0;
}


