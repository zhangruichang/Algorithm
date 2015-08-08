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
int a[maxn], index[maxn], n;
struct query
{
    int t, l, c;
} data[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int m, n;
    while(cin>>m)
    {
        for(int i=0;i<m;i++)
        {
            cin>>data[i].t;
            if(data[i].t==1) cin>>data[i].l;
            else cin>>data[i].l>>data[i].c;
        }
        cin>>n;
        for(int i=0;i<n;i++) cin>>index[i],index[i]--;
        int ai=0;
        for(int i=0;i<m;i++)
        {
            if(data[i].t==1)
                a[ai++]=data[i].l;
            else
            {
                for(int ci=0;ci<data[i].c;ci++)
                {
                    for(int li=0;li<data[i].l;li++)
                        a[ai++]=a[li];
                }
            }
        }
        for(int i=0;i<n;i++) cout<<a[index[i]]<<" ";
    }
	return 0;
}
