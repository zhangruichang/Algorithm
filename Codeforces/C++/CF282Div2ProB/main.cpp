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


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    LL a, b;
    while(cin>>a>>b)
    {
        if(a==b)
        {
            cout<<"infinity"<<endl;
            continue;
        }
        int ans=0;
        for(LL i=1;i*i<=a-b;i++)
        {
            if((a-b)%i==0)
            {
                if(i>=b+1 && i*i==a-b) ans++;
                else
                {
                    if(i>=b+1) ans++;
                    if((a-b)/i>=b+1) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
