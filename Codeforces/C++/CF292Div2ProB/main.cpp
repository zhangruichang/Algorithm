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

bool G[maxn], B[maxn];
int GCD(int n, int m)
{
    if(!n) return m;
    return GCD(m%n, n);
}
int LCM(int n, int m)
{
    int gcd=GCD(n,m);
    return n*m/gcd;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, m;
    while(cin>>n>>m)
    {
        memset(B, 0 ,sizeof B);memset(G, 0 ,sizeof G); int b,g,x,y;
        cin>>b; for(int i=0;i<b;i++) cin>>x, B[x]=1;
        cin>>g; for(int i=0;i<g;i++) cin>>y, G[y]=1;
        int lcm=LCM(n, m);
        for(int i=0;i<2*lcm;i++)
        {
            int bi=i%n, gi=i%m;
            if(B[bi] || G[gi]) G[gi]=1,B[bi]=1;
        }
        int i;
        for(i=0;i<n+m;i++)
        {
            if(i<n)
            {
                if(!B[i]) break;
            }
            else
            {
                if(!G[i-n]) break;
            }
        }
        puts(i<n+m ? "No" : "Yes");
    }
	return 0;
}
