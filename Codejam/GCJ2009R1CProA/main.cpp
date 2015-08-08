/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int Index(char c)
{
    return ((c<='9' && c>='0') ? (c-'0') : (c-'a'+10));
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-small-practice.in" , "r" , stdin);
    freopen ("A-small-practice.out" , "w" , stdout);
#endif

    int t;string str;
    cin>>t;
    unordered_map<char, int> mp;
    for(int ti=1;ti<=t;ti++)
    {
        mp.clear();
        cin>>str;int n=str.size();
        vector<int> num;
        int dig=0;
        for(int i=0;i<n;i++)
        {
            if(!i) num.push_back(1), mp[str[i]]=1;
            else if(mp.find(str[i])==mp.end())
            {
                num.push_back(dig);
                mp[str[i]]=dig++;
                if(dig==1) dig=2;
            }
            else
            {
                num.push_back(mp[str[i]]);
            }
        }
        if(mp.size()==1) dig=2;
        //for(auto e: num) cout<<e<<" ";
        reverse(num.begin(), num.end());LL wei=1, sum=0;
        for(int i=0;i<num.size();i++)
        {
            sum+=num[i]*wei;wei*=dig;
            //cout<<sum<<endl;
        }
        printf("Case #%d: %I64d\n", ti, sum);
    }
	return 0;
}
