#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS, mapT;
        int size = s.length();

        if (size != t.length()) return false;

        for (int i = 0; i < size; i++)
        {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        for (auto& it : mapS) 
            if (mapT[it.first] != it.second) return false;

        return true;
    }
};


int main()
{
        
    
}


