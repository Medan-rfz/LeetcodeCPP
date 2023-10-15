#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    static vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        generate(n, 0, 0, res, "");
        return res;
    }

private:
    static void generate(int n, int open, int close, vector<string>& strings, string currStr)
    {
        if (open == n && close == n)
            strings.push_back(currStr);
        else
        {
            if (open < n)
                generate(n, open + 1, close, strings, currStr + '(');
            if(open > close)
                generate(n, open, close+1, strings, currStr + ')');
        }
    }
};

int main()
{
    auto res = Solution::generateParenthesis(3);


    for (auto x : res)
        cout << x << endl;

    return 0;
}

