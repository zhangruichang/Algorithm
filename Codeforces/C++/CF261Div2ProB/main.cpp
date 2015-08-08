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
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fi first
#define se second
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
LL a[maxn];
pair<LL, LL> v[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    LL n;
    while(cin>>n)
    {
        for(LL i=0;i<n;i++) cin>>a[i];
        LL maxdif=*max_element(a, a+n)-*min_element(a, a+n);
        //for(int i=0;i<n;i++) v[i]={a[i], i};
        sort(a, a+n);LL ans=0;
        for(LL i=0;i<n && a[i]+maxdif<=a[n-1];i++)
        {
            LL low=lower_bound(a+i+1, a+n, a[i]+maxdif)-(a+i), high=upper_bound(a+i+1, a+n, a[i]+maxdif)-(a+i);
            //cout<<low<<" "<<high<<endl;
            ans+=high-low;
        }
        cout<<maxdif<<" "<<ans<<endl;
    }

	return 0;
}
