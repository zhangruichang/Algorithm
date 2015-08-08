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
string MaxAns(int m, int s)
{
    string maxans(m, '0');
    int remain=s;
    for(int i=0;i<m;i++)
    {
        maxans[i]=min(remain, 9)+'0';
        remain-=(maxans[i]-'0');
    }
    if(remain) return "-1";
    return maxans;
}
string MinAns(int m, int s)
{
    string minans=MaxAns(m, s);
    if(minans=="-1") return "-1";
    reverse(minans.begin(), minans.end());
    if(minans[0]!='0') return minans;
    minans=MaxAns(m, s-1);
    if(minans=="-1") return "-1";
    reverse(minans.begin(), minans.end());
    minans[0]='1';
    return minans;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int m ,s;

    while(cin>>m>>s)
    {
        if(!s && m>=2) cout<<"-1 -1"<<endl;
        else if(!s && m==1) cout<<"0 0"<<endl;
        else
            cout<<MinAns(m, s)<<" "<<MaxAns(m, s)<<endl;
    }
	return 0;
}
