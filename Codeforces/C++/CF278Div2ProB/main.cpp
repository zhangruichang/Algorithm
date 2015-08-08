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
int a[maxn], n;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        if(!n) cout<<"YES\n"<<"1\n1\n3\n3\n";
        else if(n==4)
        {
            sort(a, a+n);
            puts(((a[1]+a[2])/2.0 == (a[0]+a[1]+a[2]+a[3])/4.0 && (a[0]+a[1]+a[2]+a[3])/4.0 == (a[3]-a[0])) ?
                 "YES":"NO");
        }
        else if(n==3)
        {
            sort(a, a+3);
            int x0=a[0]+a[1]-a[2];
            if((x0+a[2])/2.0 == a[2]-x0) {cout<<"YES\n"<<x0<<'\n';continue;}
            x0=a[0]+a[2]-a[1];
            if((a[0]+a[2])/2.0 == a[2]-a[0]) {cout<<"YES\n"<<x0<<'\n';continue;}
            x0=a[1]+a[2]-a[0];
            if((a[1]+a[2])/2.0 == x0-a[0]) {cout<<"YES\n"<<x0<<'\n';continue;}
            puts("NO");
        }
        else if(n==1)
        {
            cout<<"YES\n"<<2*a[0]<<'\n'<<2*a[0]<<'\n'<<3*a[0]<<endl;
        }
        else if(n==2)
        {
            int x=min(a[0], a[1]), y=max(a[0], a[1]);
            if(3*x<y) puts("NO");
            else cout<<"YES\n"<<4*x-y<<endl<<3*x<<endl;
        }
    }
	return 0;
}
