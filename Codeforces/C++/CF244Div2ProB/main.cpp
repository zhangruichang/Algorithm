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
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
int a[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, t,c;
    while(cin>>n>>t>>c)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        int len=0;int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=t)
            {
                len++;
            }
            else
            {
                if(len-c+1>0)
                    ans+=len-c+1;
                len=0;
            }
        }
        if(len-c+1>0) ans+=len-c+1;
        cout<<ans<<endl;
    }
	return 0;
}
