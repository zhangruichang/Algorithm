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
const int maxn = 1e2 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19


unordered_map<string,int> StrIndex;
int color[maxn];//0 not visit, 1 color1, 2 color2
vector<int> Edge[maxn];
int n, m;

bool dfs(int cur, int c)
{
    if(color[cur]) return 1;
    color[cur]=c;
    for(auto i : Edge[cur]){
        if(color[cur]==color[i] || (!color[i] &&!dfs(i,3-c))) return 0;
    }
    return 1;
}
/*
void dfs1(int cur, int c, int cnt){
    color[cur]=c;
    if(cnt==n){
        int cnt1=0;
        for(int i=1;i<=n;i++){
            if(color[i]==1) cnt1++;
        }
        ans=max(cnt1, n-cnt1);
        return ;
    }
    for(auto i: Edge[cur]){
        if(color[cur]==color[i]) continue;
        dfs1(i, 3-c, cnt+1);
    }
}
*/
string str1, str2;
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-small-practice-2.in" , "r" , stdin);
    freopen ("A-small-practice-2.out" , "w" , stdout);
#endif

    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        StrIndex.clear();
        n=0;
        memset(color,0,sizeof color);
        for(int i=0;i<maxn;i++) Edge[i].clear();

        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>str1>>str2;
            if(StrIndex.find(str1)==StrIndex.end()) StrIndex[str1]=n++;
            if(StrIndex.find(str2)==StrIndex.end()) StrIndex[str2]=n++;
            Edge[StrIndex[str1]].push_back(StrIndex[str2]);
            Edge[StrIndex[str2]].push_back(StrIndex[str1]);
        }

        printf("Case #%d: ", ti);
        bool ok=1;
        for(int i=0;i<n;i++){
            if(!dfs(0, 1)) {ok=0; break;}
        }
        puts(ok?"YES":"NO");
    }
	return 0;
}
