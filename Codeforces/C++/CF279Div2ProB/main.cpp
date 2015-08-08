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
#define first f
#define second s
int table[maxn], p[maxn];
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
        for(int i=0;i<n;i++)
        {
            int x, y;
            cin>>x>>y,table[x]=y,p[x]++, p[y]--;
        }
        int i;
        for(i=0;;i++) if(p[i]==1) break;
        int odd=i, even=table[0];
        while(odd && even)
        {
            cout<<odd<<" "<<even<<" ";
            odd=table[odd];
            even=table[even];
        }
        if(odd) cout<<odd<<" ";
        cout<<endl;
    }

	return 0;
}
