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
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
int n, m, k, x, y;
bool A[maxn][maxn];
int main()
{
    while(cin>>n>>m>>k)
    {
        int ans=0; bool ok=0;
        memset(A, 0, sizeof A);
        for(int l=1;l<=k;l++)
        {
            cin>>x>>y;
            if(ok) continue;
            A[x][y]=1;
            //leftup: x-1 y-1 ; x-1, y ; x, y-1; x, y
            for(int i=x-1;i<=x;i++) for(int j=y-1;j<=y;j++)
            {
                if(i+1<=n && j+1<=m && i>=1 && j>=1 && A[i][j] && A[i][j+1] && A[i+1][j] && A[i+1][j+1])
                    ans=l, ok=1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
