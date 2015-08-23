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
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
string ans, str, cur;
int n;
bool isP(string s)
{
    int n=s.size();
    for(int i=0, j=n-1;i<j;i++, j--)
    {
        if(s[i]!=s[j]) return 0;
    }
    return 1;
}
void dfs(int i)
{
    if(i>=n)
    {
        if(cur>ans && isP(cur)) ans=cur;
        return ;
    }
    dfs(i+1);
    cur.push_back(str[i]);
    dfs(i+1);
    cur.pop_back();
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>str)
    {
        n=str.size();
        cur.clear(), ans.clear();
        dfs(0);
        cout<<ans<<endl;
    }
	return 0;
}
