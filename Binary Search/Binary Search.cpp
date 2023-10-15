#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static int search(vector<int>& nums, int target)
    {
        int begin = 0, back = nums.size()-1, pivot;
    
        while (begin <= back)
        {
            pivot = begin + ((back - begin) / 2);
            if (nums[pivot] > target) 
                back = pivot - 1;
            else if (nums[pivot] < target) 
                begin = pivot + 1;
            else 
                return pivot;
        }

        return -1;
    }
};

int main()
{
    //vector<int> dataset{ -1,0,3,5,9,12 };
    vector<int> dataset{ 5 };

    auto res = Solution::search(dataset, 5);

    return 0;
}
