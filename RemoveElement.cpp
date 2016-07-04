/* 
 * Given an array and a value,remove all instances of that value inplaceand return the new length. 
 * The order of elements can be changed. It doesn¡¯t matter what you leave beyond the new length 
 */
#include <iostream>

using namespace std;

class Solution
{
public: 
	int removeElement(int A[], int n, int elem)
	{  
		int index = 0;

		for (int i = 0; i < n; ++i)
		{
			if (A[i] != elem)
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};

int main()
{
	int arr[] = {1, 2, 2, 1, 1};
	Solution s;
	int ret = s.removeElement(arr, 5, 1);

	for (int i = 0; i < ret; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}