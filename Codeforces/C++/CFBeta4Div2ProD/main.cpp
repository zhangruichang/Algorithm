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

struct Node
{
    int w, h;
    int in;
    bool operator<(Node n) const
    {
        if(w!=n.w) return w<n.w;
        else return h<n.h;
    }
};
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, w, h, w1, h1;
    cin>>n>>w>>h;
    int dp[n+1];
    vector<Node> data;
    for(int i=0;i<n;i++)
    {
        cin>>w1>>h1;
        if(w1>w && h1>h)
            data.push_back({w1,h1,i+1});
    }
    sort(data.begin(), data.end());
    n=data.size();
    dp[0]=0;
    int maxi=0, maxdp=dp[0];
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            if(!j || (data[j-1].w<data[i-1].w && data[j-1].h<data[i-1].h))
                dp[i]=max(dp[i], dp[j]+1);
        }
        if(dp[i]>maxdp) maxdp=dp[i], maxi=i;
    }
    vector<int> ans;
    for(int i=maxi;i>0;)
    {
        ans.push_back(data[i-1].in);
        int j;
        for(j=0;j<i;j++)
        {
            if(dp[i]==dp[j]+1 && (!j || (data[j-1].w<data[i-1].w && data[j-1].h<data[i-1].h)))
                break;
        }
        i=j;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto e: ans) cout<<e<<" ";
    cout<<endl;
	return 0;
}
