#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static int findMin(vector<int>& nums)
    {
        int pivot = 0;
        int begin = 0, end = nums.size() - 1;

        while (begin <= end)
        {
            pivot = begin + (end - begin) / 2;
            if (pivot != begin && nums[pivot] < nums[pivot - 1])
                break;
            else if (nums[begin] > nums[pivot])
                end = pivot - 1;
            else if (nums[end] < nums[pivot])
                begin = pivot + 1;
            else 
                return nums[begin];
        }

        return nums[pivot];
    }
};

int main()
{
    vector<int> dataset{ 3,4,5,1,2 };
    //vector<int> dataset{ 4,5,6,7,-10,0,1,2 };
    //vector<int> dataset{ 11,13,15,17 };
    //vector<int> dataset{ 1 };
    //vector<int> dataset{ 2,1 };

    auto res = Solution::findMin(dataset);

    return 0;
}

