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
int a[maxn], b[maxn], c[maxn];

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);sort(a, a+n);
        for(int i=0;i<n-1;i++) scanf("%d", &b[i]);sort(b, b+n-1);
        int i;
        for(i=0;i<n-1;i++) if(a[i]!=b[i]) break;
        if(i<n-1) cout<<a[i]<<endl;
        else cout<<a[n-1]<<endl;

        for(int i=0;i<n-2;i++) scanf("%d", &c[i]);sort(c, c+n-2);
        for(i=0;i<n-2;i++) if(b[i]!=c[i]) break;
        if(i<n-2) cout<<b[i]<<endl;
        else cout<<b[n-2]<<endl;
    }


	return 0;
}
