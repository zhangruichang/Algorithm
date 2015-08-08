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


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
*/
    int n ,t;
    while(cin>>n>>t)
    {
        int a[n];
        for(int i=1;i<=n-1;i++) cin>>a[i];
        int cur;
        for(cur=1;cur<n;)
        {
            if(cur<t) cur=cur+a[cur];
            else break;
        }
        puts(cur==t ? "YES": "NO");
    }
	return 0;
}
