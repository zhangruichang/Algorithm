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
const int maxn = 1e6 + 10;
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
int a[5]={0,1,2,3,4}, n=5, maxh;
int g[5][5];
void per(int i)
{
    if(i==n)
    {
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        int cur=0;
        for(int s=0;s<n;s++)
        {
            //int ss=s;
            for(int ss=s;ss+1<n;ss+=2)
            {
                cur+=(g[a[ss]][a[ss+1]]+g[a[ss+1]][a[ss]]);
            }
        }
        maxh=max(maxh, cur);
        return ;
    }
    for(int j=i;j<n;j++)
    {
        swap(a[i], a[j]);
        per(i+1);
        swap(a[i], a[j]);
    }
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) cin>>g[i][j];
    maxh=0;
    per(0);
    cout<<maxh<<endl;
	return 0;
}
