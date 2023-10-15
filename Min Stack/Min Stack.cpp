#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack 
{
private:
    deque<int> _c;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> _minQueue;

public:
    MinStack() { }

    void push(int val) 
    {
        if (_minQueue.empty() || _minQueue.top().first > val)
            _minQueue.push(make_pair(val, 1));
        else if (_minQueue.top().first == val)
        {
            auto temp = _minQueue.top();
            _minQueue.pop();
            temp.second++;
            _minQueue.push(temp);
        }

        _c.push_back(val);
    }

    void pop() 
    {   
        auto temp = _c.back();
        if (temp == _minQueue.top().first)
        {
            auto temp = _minQueue.top();
            _minQueue.pop();
            temp.second--;
            if (temp.second > 0) _minQueue.push(temp);
        }
        _c.pop_back();
    }

    int top() 
    {
        return _c.back();
    }

    int getMin() 
    {
        return _minQueue.top().first;
    }
};

int main()
{
    return 0;
}

