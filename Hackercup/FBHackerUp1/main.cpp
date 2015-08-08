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

int prime[maxn];
//bool isnotprime[maxn];
int primei=0;
void GetPrime()
{
    //memset(isnotprime, 0, sizeof(isnotprime));
    //prime[2]=1, prime[3]=1;
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])
        {
            for(int j=i;j<=maxn;j+=i)
            {
                prime[j]++;
            }
        }
    }
    //for(int i=2;i<1e7;i++) if(!isnotprime[i]) prime[primei++]=i;
}



int main()
{
    //freopen("homework.txt","r",stdin);
    //freopen("homework_out.txt","w",stdout);
    int t, a, b ,k;
    cin>>t;
    GetPrime();
    for(int ti=1;ti<=t;ti++)
    {
        cin>>a>>b>>k;
        int cnt=0;
        for(int i=a;i<=b;i++)
            if(prime[i]==k) cnt++;
        cout<<"Case "<<"#"<<ti<<": "<<cnt<<endl;;
    }
	return 0;
}
