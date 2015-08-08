#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19

int val[30];
char str[maxn];
int sum[maxn];
map<LL, int> G[30];
/*
1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
xabcab
2

1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
aaa
2
*/
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int ans = 0;
	for (int i = 0; i < 26; i++) scanf("%d", &val[i]);
	scanf("%s", str+1);
	int n = strlen(str+1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + val[str[i]-'a'];
	for (int i = 1; i <= n; i++)
	{
		int idx = str[i]-'a';
		if (G[idx].find(sum[i-1])!=G[idx].end())
			ans += G[idx][sum[i-1]];
		G[idx][sum[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}
