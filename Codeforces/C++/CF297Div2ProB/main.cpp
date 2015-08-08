/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
const int maxn = 2e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int cnt[maxn],a[maxn] ,n, t, m;
char s[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //string str;
    while(scanf("%s", s+1)!=EOF)
    {
        unordered_map<int, int> mp;
        memset(cnt, 0, sizeof cnt);
        cin>>m;int len=strlen(s+1);
        for(int i=1;i<=m;i++) scanf("%d", &a[i]);
        for(int i=1;i<=m;i++) mp[a[i]]++;int last=0;
        for(int i=1;i<=len/2;i++)
        {
            int add=0;
            if(mp.find(i)!=mp.end()) add=mp[i];
            cnt[i]=last+add;
            last=cnt[i];
        }
        //for(int i=a[m]+1;i<=len/2;i++) cnt[i]=m;

        //for(int i=1;i<=len/2;i++) cout<<cnt[i]<<" ";
        //cout<<endl;
        for(int i=1;i<=len/2;i++)
        {
            if(cnt[i]&1) swap(s[i], s[len-i+1]);
        }
        printf("%s\n", s+1);
    }
	return 0;
}
