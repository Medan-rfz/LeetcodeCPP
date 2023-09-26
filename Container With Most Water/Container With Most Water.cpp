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
    static int maxArea(vector<int>& height) 
    {
        vector<int>::iterator pa = height.begin();
        vector<int>::iterator pb = height.end() - 1;
        int res = 0;

        while (pb > pa)
        {
            int S = min(*pa, *pb) * (pb - pa);
            res = max(S, res);
            if (*pa >= *pb) pb--;
            else pa++;
        }

        return res;
    }
};

int main()
{
    //auto dataset = vector<int>{ 0 };
    //auto dataset = vector<int>{ 0,4 };
    auto dataset = vector<int>{ 1,8,6,2,5,4,8,3,7 };

    auto res = Solution::maxArea(dataset);

    return 0;
}

