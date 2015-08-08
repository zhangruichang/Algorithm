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
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

int n, m;
int main()
{
    while(cin>>n>>m)
    {

    string A[n];
    for(int i=0;i<n;i++)
    {
        if(i&1)
        {
            A[i].assign(m, '.');
            if((i/2)&1) A[i][0]='#';
            else A[i][m-1]='#';
        }
        else
        {
            A[i].assign(m, '#');
        }
        cout<<A[i]<<endl;
    }
    }
	return 0;
}
