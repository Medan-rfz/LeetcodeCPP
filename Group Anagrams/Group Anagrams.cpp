#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution 
{
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> map;
            
        for (int i = 0; i < strs.size(); i++)
        {
            auto sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            map[sortedString].push_back(strs[i]);
        }

        vector<vector<string>> result;
        result.reserve(map.size());

        for (auto v : map) 
            result.push_back(v.second);

        return result;
    }
};

int main()
{
    vector<string> dataset { "eat", "tea", "tan", "ate", "nat", "bat" };

    auto res = Solution::groupAnagrams(dataset);

    return 0;
}


