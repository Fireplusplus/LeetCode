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