#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static int search(vector<int>& nums, int target)
    {
        int begin = 0, end = nums.size() - 1;
        int pivot;

        while (begin <= end)
        {
            pivot = begin + (end - begin) / 2;
            if (nums[pivot] == target) return pivot;

            if (nums[pivot] >= nums[begin])
            {
                if (nums[begin] <= target && nums[pivot] >= target)
                    end = pivot - 1;
                else
                    begin = pivot + 1;
            }
            else
            {
                if (nums[end] >= target && nums[pivot] <= target)
                    begin = pivot + 1;
                else
                    end = pivot - 1;
            }
        }

        return -1;
    }
};

int main()
{
    //vector<int> dataset{ 3,4,5,6,7,0,1,2 };
    //vector<int> dataset{ 4,5,6,7,8,1,2,3 };
    vector<int> dataset{ 3,1 };

    auto res = Solution::search(dataset, 1);

    return 0;
}
