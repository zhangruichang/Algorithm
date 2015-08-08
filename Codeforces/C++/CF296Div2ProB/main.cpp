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
const int maxn = 2e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define fi first
#define se second
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
int n;
int mp[26][26];
int ump[26][26];
char s[maxn], t[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n)
    {
        scanf("%s", s);getchar();
        scanf("%s", t);
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) mp[i][j]=ump[i][j]=-1;
        int cnt=0, sii2=-1, sjj2=-1, sii1=-1, sjj1=-1;
        bool one=0, two=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i]) continue;
            cnt++;
            int si=s[i]-'a', ti=t[i]-'a';
            for(int j=0;j<26;j++)
            {
                if(ump[si][j]==-1) continue;
                if(j==ti)
                {
                    two=1, sii2=i, sjj2=ump[si][j];}
                else one=1, sii1=i, sjj1=ump[si][j];
            }
            for(int j=0;j<26;j++)
            {
                if(mp[ti][j]==-1) continue;
                if(j==si)
                {
                    two=1, sii2=i, sjj2=mp[ti][j];
                }
                else
                    one=1, sii1=i, sjj1=mp[ti][j];
            }
            //if(one) sjj=likejj;
            mp[si][ti]=i;
            ump[ti][si]=i;;
        }

  L1:   if(!two && !one) cout<<cnt<<endl<<"-1 -1"<<endl;
        else if(two) cout<<cnt-2<<endl<<sii2+1<<" "<<sjj2+1<<endl;
        else cout<<cnt-1<<endl<<sii1+1<<" "<<sjj1+1<<endl;
    }
	return 0;
}
