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
const int maxn = 1e7 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

int P[maxn];

void F(int n)//Print primes in [1..n]
{
    memset(P, 0, sizeof(P));
    //fill(P, P+maxn, 1);
    for(int i=2;i<=n;i++)
    {
        if(!P[i])
        {
            for(int j=2*i;j<=n;j+=i)
                P[j]++;
        }
    }
    //for(int i=2;i<=n;i++) if(!P[i]) cout<<i<<" ";
}

int main()
{
    freopen("homework.txt", "r",stdin);
    freopen("homework_out.txt", "w",stdout);
    int a, b, k, t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>a>>b>>k;
        F(b);
        int cnt=0;
        //if(k==1) k--;
        for(int i=a;i<=b;i++) if((k==1 && (!P[i] || P[i]==1)) || (k!=1 && P[i]==k)) cnt++;
        cout<<"Case #"<<ti<<": "<<cnt<<endl;
    }
	return 0;
}
