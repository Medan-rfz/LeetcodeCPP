#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isPalindrome(string s)
    {
        auto front = s.begin();
        auto back = s.end() - 1;

        while(front < back)
        {
            while (front < back && !isLetterOrNumber(*front)) front++;
            while (front < back && !isLetterOrNumber(*back)) back--;

            if (tolower(*front) != (char)tolower(*back)) return false;

            //cout << *back << endl;
            front++;
            back--;
        }

        return true;
    }

private:
    static inline bool isLetterOrNumber(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
};

int main()
{
    //string dataset = "A man, a plan, a canal: Panama";
    //string dataset = "race a car";
    string dataset = ".,";
    //string dataset = " ";

    auto res = Solution::isPalindrome(dataset);

    return 0;
}


