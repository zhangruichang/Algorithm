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
int a[maxn], l[maxn], r[maxn], n, t, m;
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
        l[0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]) l[i]=l[i-1]+1;
            else l[i]=1;
        }
        r[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1]) r[i]=r[i+1]+1;
            else r[i]=1;
        }
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(i-1>=0 && i+1<n)
            {
                if(a[i-1]+1<a[i+1]) ans=max(ans, l[i-1]+r[i+1]+1);
                else
                    ans=max(ans, max(l[i-1]+1,r[i+1]+1));
            }
            else if(i-1>=0 && i+1>=n) ans=max(ans, l[i-1]+1);
            else if(i+1<n && i-1<0) ans=max(ans, r[i+1]+1);
        }
        cout<<ans<<endl;
    }
	return 0;
}
