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
bool v[maxn];
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
        queue<int> q;
        q.push(n);
        int cnt=0;
        memset(v, 0, sizeof(v));v[n]=1;
        while(!q.empty())
        {
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                auto cur=q.front();q.pop();
                if(cur==m) goto L1;
                if(!v[cur-1] && cur-1>=1) q.push(cur-1), v[cur-1]=1;
                if(!v[cur*2] && cur<m) q.push(cur*2), v[cur*2]=1;
            }
            cnt++;
        }
L1:     cout<<cnt<<endl;
    }
	return 0;
}
