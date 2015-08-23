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
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
int lowerbit(int x)
{
    return x&(-x);
}
pair<int, int> SingleNumII(int a[], int n)//in: 1 2 3 3 4 4 out: 1 2
{
    int xora=0;
    for(int i=0;i<n;i++)
        xora^=a[i];
    int la=lowerbit(xora);
    int xora1=0;
    for(int i=0;i<n;i++)
    {
        if(lowerbit(a[i])==la)
            xora1^=a[i];
    }
    return {xora1, xora1^xora};
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int a[]={0,1,2,3,0,3,4,4, 5, 7, 7, 5}, n=sizeof(a)/sizeof(int);
    auto ans=SingleNumII(a, n);
    cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
