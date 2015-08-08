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

int GCD(int m, int n)
{
    if(!n) return m;
    return GCD(n, m%n);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif

    int n;
    while(cin>>n)
    {
        int x0, y0;
        cin>>x0>>y0;
        map<pair<int, int>, int> K;
        for(int i=0;i<n;i++)
        {
            int x1, y1;cin>>x1>>y1;
            int u=x1-x0, v=y1-y0;
            int w=GCD(u,v);u/=w, v/=w;
            K[{u,v}]++;
        }
        cout<<K.size()<<endl;
    }

	return 0;
}
