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

int a[maxn], b[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, m, k;
    while(cin>>n>>m>>k)
    {
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++) scanf("%d", &a[i]), hash[a[i]]=i;
        for(int i=0;i<m;i++) scanf("%d", &b[i]);
        ULL c=0;
        for(int i=0;i<m;i++)
        {
            int index=hash[b[i]];
            c+=ULL(index/k+1);
            if(index==0) continue;
            hash[a[index]]=index-1;
            hash[a[index-1]]=index;
            swap(a[index-1], a[index]);
        }
        cout<<c<<endl;
    }
	return 0;
}
