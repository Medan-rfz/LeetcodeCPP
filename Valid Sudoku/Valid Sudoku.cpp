#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isValidSudoku(vector<vector<char>>& board)
    {
        const int size = 9;
        bool lines[size][size] = { false };
        bool columns[size][size] = { false };
        bool areas[size][size] = { false };

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == '.') continue;

                int nbr = board[i][j] - '0' - 1;
                int area = 3 * (i / 3) + j / 3;
                if (lines[i][nbr] || columns[j][nbr] || areas[area][nbr]) return false;

                lines[i][nbr] = true;
                columns[j][nbr] = true;
                areas[area][nbr] = true;                
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> dataset
    { 
        vector<char> { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        vector<char> { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        vector<char> { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        vector<char> { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        vector<char> { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        vector<char> { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        vector<char> { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        vector<char> { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        vector<char> { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    auto res = Solution::isValidSudoku(dataset);

    return 0;
}


