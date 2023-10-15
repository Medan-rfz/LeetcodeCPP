#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    static int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        for (auto c : tokens)
        {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                auto op2 = s.top();
                s.pop();
                auto op1 = s.top();
                s.pop();

                if (c == "+") s.push(op1 + op2);
                else if (c == "-") s.push(op1 - op2);
                else if (c == "*") s.push(op1 * op2);
                else if (c == "/") s.push(op1 / op2);
            }
            else s.push(atoi(c.c_str()));
        }
        return s.top();
    }

    static int evalPN(string token)
    {
        vector<string> number;
        int res = token[1] == '*' ? 1 : 0;
        auto it = token.begin();

        number.push_back("");
        while (it < token.end())
        {
            if (it != token.begin() && *it == '(')
            {
                auto newStr = string(it, token.end());
                if (token[1] == '+') res += evalPN(newStr);
                else if (token[1] == '-') res -= evalPN(newStr);
                else if (token[1] == '*') res *= evalPN(newStr);
                while (it < token.end() && *it != ')') it++;
            }
            else if (*it >= '0' && *it <= '9')
            {
                number[number.size() - 1] += *it;
            }
            else if (*it == ' ')
            {
                number.push_back("");
            }
            else if (*it == ')')
            {
                for (auto x : number)
                {
                    if (x != "")
                    {
                        if (token[1] == '+') res += atoi(x.c_str());
                        else if (token[1] == '-') res -= atoi(x.c_str());
                        else if (token[1] == '*') res *= atoi(x.c_str());
                    }
                }
                number.clear();
                number.push_back("");
                break;
            }
            it++;
        }
        return res;
    }
};

int main()
{
    //vector<string> dataset{ "2","1","+","3","*" };
    //vector<string> dataset { "4","13","5","/","+" };

    //string dataset = "(+3 4 (*1 2))";
    string dataset = "(*(+3 6) (*1 2 3))";

    //auto res = Solution::evalRPN(dataset);
    auto res = Solution::evalPN(dataset);

    return 0;
}

