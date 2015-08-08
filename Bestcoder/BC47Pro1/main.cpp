#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1005;
typedef long long LL;
int nums[maxn];
LL dp[maxn], dp2[maxn];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T, n,i,val, isoneblock;
    LL res, sum1, sum2,sum3;

    //LL dp[n],dp2[n];
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&val);
        for(i=0;i<n;++i) scanf("%d",&nums[i]);
        if(n==1) { printf("%d\n",val); continue; }
        //dp=buf+1, dp[n]=0, dp2=dp+n+1;
        dp[0]=max(0, num[0]);
        for(int i=1;i<n;i++) {
            dp[i]=max(0,dp[i-1]+nums[i]);
        }
        dp2[n]=0;
        for(int i=n-1;i>=0;i--) {
            dp2[i]=max(0,dp2[i+1]+nums[i]);
        }
        bool isoneblock=1;
        for(int i=0;i<n;++i) {
            if(dp[i]==0 || dp2[i]==0) { isoneblock=0; break;}
        }
        if(isoneblock) res=max(dp[0],dp2[0])+val-*min_element(nums,nums+n);
        else{
            int res=val;
            for(int i=0;i<n;++i) {
                res=max(res,max(val,nums[i])+dp[i-1]+dp2[i+1]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
