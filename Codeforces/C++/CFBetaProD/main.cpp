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
#include "LCS.h"
#include "PalindromePairs.h"
#include "InversePairCnt.h"
#include "Regular.h"
using namespace std;

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
    Node operator=(Node n)
    {
        w=n.w;h=n.h;
        in=n.in;
        return *this;
    }
};

Node data[maxn];

/*
isMatch("aa","a")    false
isMatch("aa","aa")    true
isMatch("aaa","aa")    false
isMatch("aa",  "a*")    true
isMatch("aa",  ".*")    true
isMatch("ab",  ".*")   true
isMatch("aab",  "c*a*b")   true
"aa" "a**"
*/

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    Regular r;
    char s[100], p[100];
    while(scanf("%s%s", s, p))
        cout<<r.ReExp_Two(s, p)<<endl;
    /*
    vector<int> v={1,4,5,3,6,3,3};
    InversePairCnt ipc;
    cout<<ipc.InversePairCnt1(v)<<endl;
    //for(auto i: v) cout<<i<<" ";*/
    /*
    int n,W,H;
    LCS lcs;
    vector<int> v={1,2,5,6,9};
    auto ans=lcs.LCS_Solution(v);
    for(auto i: ans)
    {
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }*/
    /*
    PalindromePairs pp;
    vector<string> v={"ab", "ba"};
    auto ans=pp.PalindromePairs1(v);
    for(auto i: ans) cout<<i.first<<" "<<i.second<<endl;
    */
    /*
    while(cin>>n>>W>>H)
    {
        for(int i=0;i<n;i++) cin>>data[i].w>>data[i].h, data[i].in=i+1;
        sort(data, data+n);
        int i;for(i=0;i<n;i++) if(data[i].w>W && data[i].h>H) break;
        if(i==n)
        {
            cout<<"0\n";continue;
        }
        vector<int> ans={data[i].in};
        int save=i;
        for(int j=i+1;j<n;j++)
        {
            if(data[j].h>data[save].h && data[j].w>data[save].w) data[++save]=data[j], ans.push_back(data[j].in);
        }
        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }*/

	return 0;
}
