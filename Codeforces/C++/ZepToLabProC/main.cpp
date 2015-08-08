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
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    LL w, hr , hb, wr, wb;
    while(cin>>w)
    {
        cin>>hr>>hb>>wr>>wb;
        //if(double(hr)/wr<double(hb)/wb)

        if(double(hr)/wr<double(hb)/wb) swap(hr, hb), swap(wr, wb);
        LL maxv=0;
        //int qw=sqrt(w)
        if(wr*wr>w)
        {
            for(LL i=0;i<=w/wr;i++)
            {
                maxv=max(maxv, i*hr+(w-i*wr)/wb*hb);
            }
        }
        else
        {
            for(LL i=0;i<=min(w/wb,wr);i++)
            {
                maxv=max(maxv, i*hb+(w-i*wb)/wr*hr);
            }
        }
        cout<<maxv<<endl;
    }
	return 0;
}
