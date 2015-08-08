#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<memory>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const ULL maxn = 1e13+10;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

int c[10000000+10];
void init()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!c[i])
        {
            for(int j=i;j<=maxn;j+=i) c[j]++;
        }
    }
}

void PrintPrimes_2i(int n)
{
    //int n=1000;
    bool* p=new bool[maxn];
    memset(p, 0 ,sizeof(p));
    p[1]=1;
    for(ULL i=2;i<=n/2ULL;i++)
    {
        if(!p[i])
        {
            for(ULL j=2*i;j<=n;j+=i) p[j]=1;
        }
    }
    //for(int i=1;i<=n;i++) if(!p[i]) cout<<i<<" ";
    cout<<endl;
    delete[] p;
}

//bool P[maxn];
void PrintPrimes_ii(int n)
{
    bool* P=new bool[maxn];
    memset(P, 0 ,sizeof(P));
    P[1]=1;
    for(ULL i=2;i*i<=n;i++)
    {
        if(!P[i])
        {
            for(ULL j=i*i;j<=n;j+=i) P[j]=1;
        }
    }
    //for(int i=1;i<=n;i++) if(!P[i]) cout<<i<<" ";
    cout<<endl;
    delete[] P;
}

void solve()
{
    int a, b, k;
    cin>>a>>b>>k;
    int ans=0;
    for(int i=a;i<=b;i++) if(c[i]==k) ans++;
    cout<<ans<<endl;
}

int main()
{
    //int n=maxn;
    time_t start=clock();
    PrintPrimes_2i(maxn);
    time_t end=clock();
    cout<<"2*i: "<<end-start<<endl;
    start=clock();
    PrintPrimes_ii(maxn);
    end=clock();
    cout<<"i*i: "<<end-start<<endl;
    /*freopen("homework.txt", "r",stdin);
    freopen("homework_out.txt", "w",stdout);

    init();
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cout<<"Case #"<<ti<<": ";
        solve();
    }*/
	return 0;
}
