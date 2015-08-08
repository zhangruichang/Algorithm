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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

ULL dp[2010][2010];

ULL f(int a, int b)
{
    if(dp[a][b]) return dp[a][b];
    if(a<=b) return 0;
    if(!b && a) return 1;
    return dp[a][b]= a==b+1 ? (f(a, b-1)) : (f(a-1, b) + f(a, b-1)-1);
}

int t, a, b;
char ch;
int main()
{
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>a>>ch>>b;
        //cout<<a<<" "<<b<<endl;
        cout<<"Case #"<<ti<<": "<<endl;
        cout<<f(a, b)%1000000007<<endl;
    }
	return 0;
}
