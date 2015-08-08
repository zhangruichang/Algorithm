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
/*
2 6//n m, [0, 5*10^5]
2
4 5
3
*/

//brute force method, should first try to write pseudecode, to decide the time, as not clear about thinking method time
//for loop can optimize as some limitation for inequality
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, m;
    while(cin>>n>>m)
    {
        int maxt=0;
        for(int y=min(n/2, m);y>=0;y--)
        {
            //if(y>m) continue;
            int remain=n-2*y;
            int x=min(remain, (m-y)/2);
            maxt=max(maxt, x+y);
        }
        cout<<maxt<<endl;
    }
	return 0;
}
