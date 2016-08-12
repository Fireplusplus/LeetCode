/* 
 * 经过多次强攻之后，赫柏带领的军团不仅没能击败鲁卡斯，反而被鲁卡斯打得七零八落，赫柏终于体会到了高阶天之驱逐者的强大实力。
 * 不过，赫柏最终还是找到了鲁卡斯的致命弱点，他发现鲁卡斯喜欢收集上古卷轴，因为上古卷轴能够让鲁卡斯获得神秘之力。
 * 卢卡斯决定使用上古卷轴将卢卡斯引诱到绝域之门，利用绝域之门的力量消灭卢卡斯。
 * 赫柏注意到卢卡斯喜欢收集不同的卷轴，如果总是捡到相同的上古卷轴，它的兴趣就会逐渐降低。
 * 赫柏现在拥有N种不同的卷轴，每种卷轴有Ai个。现在他要将这N个卷轴分散在鲁卡斯领地到绝域之门的路上，
＊每一种排列方式都有一个吸引值Charm，吸引值越高，鲁卡斯被引诱到绝域之门的概率越高。
　* Charm=Sum of all D(i)，其中D(i)=k-i，i为该排列中卷轴i的下标，k为位于i后面且和i是同一种卷轴的卷轴下标。
 *现在所有的卷轴以<卷轴名称 数量>的格式给出，你需要输出所有卷轴的排列顺序，使得吸引值最大，如果有多种排列方式满足条件，输出按照名字排列字典序最小的一个。
＊输入描述:
＊多组测试数据，请处理到文件结束。
＊对于每组测试数据：
＊第一行：一个整数N，代表有N种卷轴。
＊第二行：N种卷轴的描述。
＊保证：0<=N<=50;
＊卷轴名称为长度1~10的字母，每种卷轴的数量为1~800之间的一个整数。
＊输出描述:
＊输出所有卷轴的一个排列。
＊／
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<algorithm>
#include <string>

#define N 55

using namespace std;

struct PP{
	string s;
	int count;
}A[N];

bool cmp(PP a, PP b){
	return a.s < b.s;
}

int n;
string ans;
string l, r, mid;

void ini()
{
	ans = l = r = mid = "";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> A[i].s >> A[i].count;
	}
}

void solve(){
	sort(A, A + n, cmp);
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i].count > 1)
		{
			l += A[i].s + ' ';
			r += A[i].s + ' ';
			A[i].count -= 2;
		}
	}
	for (i = 0; i < n; i++){
		while (A[i].count >= 1)
		{
			mid += A[i].s + ' ';
			A[i].count--;
		}
	}
	ans = l + mid + r;
	if (ans.size() >= 1)
	{
		ans.pop_back();
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		ini();
		solve();
		cout << ans << endl;
	}
	return 0;
}
