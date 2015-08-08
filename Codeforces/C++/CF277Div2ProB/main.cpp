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
int a[maxn], b[maxn];

int main()
{
    int n, m;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>m;
        for(int i=0;i<m;i++) cin>>b[i];
        sort(a, a+n);sort(b, b+m);
        int i=0, j=0, cnt=0;
        while(i<n && j<m)
        {
            if(abs(a[i]-b[j])<=1) cnt++, i++, j++;
            else if(a[i]>b[j]) j++;
            else i++;
        }
        cout<<cnt<<endl;
    }
	return 0;
}
