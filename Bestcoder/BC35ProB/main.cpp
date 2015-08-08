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
const int maxn = 1e5 + 2;
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
int ind[maxn], n, t, m, k;
int ans[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m>>k)
    {
        bool**A=new bool*[maxn];
        for(int i=0;i<=maxn;i++) A[i]=new bool[maxn];
        memset(A, 0, sizeof(A));int u, v;
        for(int i=0;i<m;i++) cin>>u>>v, A[u][v]=1;
        for(int j=1;j<=n;j++)
        {
            int in=0;
            for(int i=1;i<=n;i++)
            {
                if(A[i][j]) in++;
            }
            ind[j]=in;
        }
        int ansi=0;

        {
            for(int i=n;i>=1 && k>0;i--)
            {
                if(ind[i]<=k)
                {
                    for(int j=1;j<=n;j++) A[j][i]=0;
                    ans[ansi++]=i;ind[i]=-1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            int j;
            for(j=1;j<=n;j++)
            {
                if(!ind[j]) break;
            }
            for(int j=1;j<=n;j++) A[j][i]=0;
            ans[ansi++]=j;
        }
        cout<<ans[0];
        for(int i=1;i<ansi;i++) cout<<" "<<ans[i];
        cout<<endl;
    }
	return 0;
}
