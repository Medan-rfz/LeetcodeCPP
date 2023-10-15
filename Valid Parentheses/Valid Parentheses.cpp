#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    static bool isValid(string s) 
    {
        if (s.size() % 2 != 0) return false;

        stack<char> st;

        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else if (!st.empty() && c == ']' && st.top() == '[')
                st.pop();
            else if (!st.empty() && c == '}' && st.top() == '{')
                st.pop();
            else return false;
        }

        if (st.size() == 0)
            return true;
        else return false;
    }
};

int main()
{
    auto dataset = "){";
    //auto dataset = "()[]{}";
    //auto dataset = "(]";
    //auto dataset = "()";

    auto res = Solution::isValid(dataset);

    return 0;
}

