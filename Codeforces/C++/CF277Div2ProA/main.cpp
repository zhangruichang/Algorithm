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

int a[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<n-1<<endl;
        for(int i=0;i<n-1;i++)
        {
            int minx=INT_MAX, minj=-1;
            for(int j=i;j<n;j++)
            {
                if(minx>a[j]) minx=a[j], minj=j;
            }
            swap(a[i], a[minj]);
            cout<<i<<" "<<minj<<endl;
        }
    }
	return 0;
}
