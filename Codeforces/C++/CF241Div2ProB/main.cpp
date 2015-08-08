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
const int maxn = 5e4 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
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
int a[maxn][6], n;int t[maxn][6];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int m;
    while(cin>>m>>n)
    {
        for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d", &a[i][j]);
        //t[0]=0;
        //for(int j=1;j<n;j++) t[j]=t[j-1]+a[0][j];
        for(int i=1;i<=m;i++)
        {
            //t[0]+=a[i][0];
            for(int j=1;j<=n;j++)
            {
                if(t[i-1][j-1]+a[i][j-1]>t[i-1][j]) t[i][j]=t[i-1][j]+a[i][j];
                else t[i][j]=t[i][j-1]+a[i][j];
            }
            //cout<<t[i][n]<<" ";
        }
        //cout<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++) cout<<t[i][j]<<" ";
            cout<<endl;
        }
    }
	return 0;
}
