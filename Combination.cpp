/* 
 * Given two integers n and k, return all possible combinations of k 
 * numbers out of 1 ... n. 
 */

class Solution 
{
public:
	vector<vector<int>> combine(int n, int k) 
	{
		vector<int> solution;  
		vector<vector<int>> result;  
		getCombine(n,k,1,solution,result);  
    		return result; 
	}

	void getCombine(  
                int n,  
                int k,  
                int level,  
                vector<int> &solution,  
                vector<vector<int>> &result)
	{  
    		if(solution.size() == k)
		{  
    			result.push_back(solution);  
    			return;  
    		}  
	   	for(int i = level; i<=n; i++)
		{  
			solution.push_back(i);  
			getCombine(n,k,i+1,solution,result);  
			solution.pop_back();  
		}  
	}   
};
