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

int MOD=1000000007;

int main()
{
    int len;
    string str;
    while(cin>>len>>str)
    {
        int sum=(1ULL<<len)-2, n=len--;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='7') sum+=(1ULL<<len);
            len--;
            sum%=MOD;
        }
        cout<<sum+1<<endl;
    }
	return 0;
}
