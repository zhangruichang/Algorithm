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
const int maxn = 5e5;
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
struct Node
{
    int i, j;
};
//bool vis[maxn][maxn];
LL lessmid(LL mid, LL n, LL m)
{
    LL sum=0;
    for(LL i=1;i<=n;i++)
        sum+=min(m, mid/i);
    return sum;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    LL n ,m, k;
    while(cin>>n>>m>>k)
    {
        LL low=1, high=n*m, mid;
        while(low<high)
        {
            mid=(low+high)>>1;
            if(low==high) break;
            if(lessmid(mid, n, m)<k) low=mid+1;
            else high=mid;
        }
        cout<<low<<endl;
    }

	return 0;
}
