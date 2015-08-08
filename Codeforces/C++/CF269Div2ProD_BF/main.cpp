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
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int a[maxn], b[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, w;
    while(cin>>n>>w)
    {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        for(int i=0;i<w;i++) scanf("%d", &b[i]);
        int tmp=b[0];
        for(int i=0;i<w;i++) b[i]-=tmp;
        int i=0, j=0, k=0, base=a[0], cnt=0;
        while(i+k<n)
        {
            if(a[i+k]-base==b[j]) k++, j++;
            else i++, k=j=0, base=a[i];
            if(j==w)
            {
                cnt++;
                i++, k=j=0;
                base=a[i];
            }
        }
        cout<<cnt<<endl;
    }

	return 0;
}
