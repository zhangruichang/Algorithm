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

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, cur;
    while(cin>>n)
    {
        int cur=n;vector<int> ans={cur};
        //if(cur==1) {cout<<1<<endl;continue;}
        //if(ans[])
        for(int i=2;i<=n;i++)
        {
            while(cur%i==0)
                cur/=i,ans.push_back(cur);;
            //if(cur==1) {ans.push_back(1);break;}
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
        cout<<endl;
    }
	return 0;
}
