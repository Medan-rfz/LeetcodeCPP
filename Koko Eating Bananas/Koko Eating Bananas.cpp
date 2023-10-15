#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static int minEatingSpeed(vector<int>& piles, int h)
    {
        int N = piles.size();
        int low = 1, high = 0;
        int res, pivot;
        long int hours;

        for (auto x : piles)
            high = max(high, x);

        res = high;
        
        while (low <= high)
        {
            pivot = low + (high - low) / 2;
            hours = 0;

            for (auto x : piles)
                hours += ceil((float)x / pivot);

            if (hours <= h)
            {
                res = min(res, pivot);
                high = pivot - 1;
            }
            else
            {
                low = pivot + 1;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> dataset{ 3,6,7,11};
    //vector<int> dataset{ 5 };

    auto res = Solution::minEatingSpeed(dataset, 8);

    return 0;
}

