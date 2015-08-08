#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn], presum[maxn], sufsum[maxn];
int t, n;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>t;
    while(t--)
    {
        cin>>n;for(int i=0;i<n;i++) cin>>a[i];
        //presum[0]=a[0];
        presum[0]=0;
        for(int i=1;i<=n;i++) presum[i]=presum[i-1]+a[i-1];
        sufsum[0]=0;
        //sufsum[n-1]=a[n-1];
        for(int i=n-1;i>=0;i--) sufsum[n-i]=sufsum[n-1-i]+a[i];
        bool ok=0;
        for(int i=0;i<n;i++)
        {
            if(n-1-i>n || n-1-i<0) continue;
            if(presum[i]==sufsum[n-1-i]) {ok=1;break;}
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}
