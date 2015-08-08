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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
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
string s, t;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>s>>t)
    {
        int n=s.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+') sum++;
            else sum--;
        }
        int jia=0, jian=0, wen=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]=='+') jia++;
            else if(t[i]=='-') jian++;
            else wen++;
        }
        int cur=jia-jian, x;
        if((sum-cur+wen)%2==0 && (sum-cur+wen)>=0 &&(sum-cur+wen)/2<=wen)
        {
            //cout<<sum<<" "<<cur<<" "<<wen<<endl;
            x=(sum-cur+wen)/2;
            double ans=1;
            LL fenzi=1, fenmu=1;
            for(int i=x;i>=1;i--)
            {
                fenzi*=(LL)(wen-(x-i));fenmu*=(LL)i;
            }
            //cout<<f<<" "<<cur<<" "<<wen<<endl;
            ans=double(fenzi)/fenmu*pow(0.5, wen);
            //cout<<fenzi<<" "<<fenmu<<" "<<wen<<" "<<ans<<endl;
            printf("%.9f\n", ans);
        }
        else cout<<"0.000000000"<<endl;
    }

	return 0;
}
