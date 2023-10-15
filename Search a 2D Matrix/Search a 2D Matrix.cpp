#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	static bool searchMatrix_1(vector<vector<int>>& matrix, int target)
	{
		int begin = 0, end = matrix.size() * matrix.back().size() - 1;
		int pivot = 0;

		while (begin <= end)
		{
			pivot = begin + (end - begin) / 2;
			int row = pivot / matrix.back().size();
			int col = pivot % matrix.back().size();

			if (matrix[row][col] > target)
				end = pivot - 1;
			else if (matrix[row][col] < target)
				begin = pivot + 1;
			else return true;
		}

		return false;
	}

	static bool searchMatrix_2(vector<vector<int>>& matrix, int target)
	{
		int begin = 0, end = matrix.size() - 1;
		int pivot = 0;
		int targetRow = 0;

		while (begin <= end)
		{
			pivot = begin + (end - begin) / 2;

			if (matrix[pivot][0] < target)
			{
				begin = pivot + 1;
				targetRow = pivot;
			}
			else if (matrix[pivot][0] > target)
				end = pivot - 1;
			else return true;
		}

		begin = 0;
		end = matrix.back().size()-1;
		while (begin <= end)
		{
			pivot = begin + (end - begin) / 2;

			if (matrix[targetRow][pivot] < target)
				begin = pivot + 1;
			else if (matrix[targetRow][pivot] > target)
				end = pivot - 1;
			else return true;
		}

		return false;
	}
};

int main()
{
	vector<vector<int>> dataset{
		vector<int> {1,3,5,7},
		vector<int> {10,11,16,20},
		vector<int> {23,30,34,60}
	};

	auto res = Solution::searchMatrix_2(dataset, 3);

	return 0;
}
