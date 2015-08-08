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


int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        int i;
        for(i=(n+1)/2;i<=n;i++)
        {
            if(i%m==0) break;
        }
        if(i<=n) cout<<i<<endl;
        else cout<<"-1"<<endl;
    }
	return 0;
}
