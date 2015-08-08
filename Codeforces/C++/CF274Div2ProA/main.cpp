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
    int a, b, c, maxx;
    while(cin>>a>>b>>c)
    {
        int maxx=a*b*c;
        maxx=max(maxx, a+b+c);
        maxx=max(maxx, a+b*c);
        maxx=max(maxx, a*b+c);
        maxx=max(maxx, (a+b)*c);
        maxx=max(maxx, a*(b+c));
        cout<<maxx<<endl;
        //maxx=max(maxn, a+b*c);
    }
	return 0;
}
