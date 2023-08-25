#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> productExceptSelf(vector<int>& nums)
    {
        auto size = nums.size();
        vector<int> res(size, 1);

        int prevTmp = 1;
        int postTmp = 1;

        for (int i = 0; i < size; i++)
        {
            res[i] *= prevTmp;
            res[size - i - 1] *= postTmp;

            prevTmp *= nums[i];
            postTmp *= nums[size - i - 1];
        }

        return res;
    }
};

int main()
{
    vector<int> dataset {1, 2, 3, 4};
    //vector<int> dataset {-1, 1, 0, -3, 3};
    //vector<int> dataset { 4, 3, 2, 1, 2 };

    auto res = Solution::productExceptSelf(dataset);

    return 0;
}


