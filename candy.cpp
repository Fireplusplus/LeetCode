/*
 * There are N children standing in a line. Each child is assigned a 
 * rating value.
 * You are giving candies to these children subjected to the following 
 * requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors. 
 * What is the minimum candies you must give?
 */

/*
 * 遍历两边，首先每个人得一块糖，第一遍从左到右，若当前点比前一个点高就比前者多一块。
 * 这样保证了在一个方向上满足了要求。第二遍从右往左，若左右两点，左侧高于右侧，但
 * 左侧的糖果数不多于右侧，则左侧糖果数等于右侧糖果数+1，这就保证了另一个方向上满足要求。
 * 最后将各个位置的糖果数累加起来就可以了。
 */

bool lessmark(int e1, int e2)
{
	return e1 < e2;
}


class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		int size = ratings.size();	
		int i;
        int *p = new int[size];
        sum = 0;
        
        p[0] = 1;
        for (i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i - 1])
                p[i] = p[i - 1] + 1;
            else
                p[i] = 1; 
        }
        
        for (i = size - 2; i > -1; i--)
        {
            if (ratings[i] > ratings[i + 1] && p[i] <= p[i + 1])
				p[i] = p[i + 1] + 1;
        }
        
        for (i = 0; i < size; i++)
            sum += p[i];
        return sum;
	}
public:
	int sum;
};

