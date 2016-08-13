/*
 * Write an efficient algorithm that searches for a value in an m × n 
 * matrix. This matrix has the following properties:
 * • Integers in each row are sorted from left to right.
 * • The first integer of each row is greater than the last integer 
 * of the previous row.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool searchMatrix(const vector<vector<int> >& matrix, int target)
	{
		if (matrix.empty())
			return false;

		const size_t row = matrix.size();
		const size_t col = matrix.front().size();
		
		int left = 0;
		int right = row * col;
		while (left < right)
		{
			int mid = ((right - left) >> 1) + left;
			int value = matrix[mid / col][mid / col];
		
			if (value == target)
				return true;
			else if (value < target)
				left = mid + 1;
			else
				right = mid;
		}
		
		return false;
	}
};

int main()
{
	vector<int> row1;
	row1.push_back(1);
	row1.push_back(2);
	row1.push_back(3);

	vector<int> row2;
	row2.push_back(4);
	row2.push_back(5);
	row2.push_back(6);
	
	vector<int> row3;
	row3.push_back(7);
	row3.push_back(8);
	row3.push_back(9);

	vector<vector<int> > v;
	v.push_back(row1);
	v.push_back(row2);
	v.push_back(row3);
	
	Solution s;
	if (s.searchMatrix(v, 10))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
