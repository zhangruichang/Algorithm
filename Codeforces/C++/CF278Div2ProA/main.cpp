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

bool has8(int x)
{
    if(x<0) x=-x;
    while(x>0)
    {
        if(x%10==8) return 1;
        x/=10;
    }
    return 0;
}
int main()
{
    int a ,ans;
    while(cin>>a)
    {
        int i;
        for(i=1;i<=16;i++)
        {
            ans=a+i;
            if(has8(ans)) break;
        }
        cout<<i<<endl;
    }
	return 0;
}
