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

/*
1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
xabcab

2

1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
aaa

2
*/
LL sum[maxn];
int a[30];
//any non-empty subarray sum can be got by prefixsum[i]-prefixsum[j], 0<=j<i<=n, and if prefixsumi==prefixsumj, sum is zero
//map is hash, can define hash array, string speciality is that it has limited chars (26 here, lowercase)
//for zero sum array, and head and tail char is equal, query ch[i], sum[i-1], but still this char, as head and tail should equal,
//then ch[i], sum[i] count++
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>a[0])
    {
        unordered_map<LL, int> G[30];

        for(int i=1;i<26;i++) cin>>a[i];
        string str; cin>>str;
        sum[0]=0;
        for(int i=0;i<str.size();i++) sum[i+1]=sum[i]+a[str[i]-'a'];
        LL ans=0;
        for(int i=0;i<str.size();i++)
        {
            int id=str[i]-'a';
            if(G[id].find(sum[i])!=G[id].end())
                ans+=G[id][sum[i]];
            G[id][sum[i+1]]++;
        }
        cout<<ans<<endl;
    }

	return 0;
}
