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
	int t = 0, flag = 1;
	char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		t = t * 10 + c - '0';
		c = getchar();
	}
	return t*flag;
}
void U(string& s)
{
    for(int i=0;i<s.size();i++) s[i]=toupper(s[i]);
}
string str[maxn];
vector<pair<string, string>> v;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int m ,n;
    string str1, str2;
    while(cin>>m)
    {
        unordered_map<string, string> hash;
        unordered_map<string, pair<int, bool>> hashlen;
        v.clear();
        for(int i=0;i<m;i++) cin>>str[i], U(str[i]);
        cin>>n;
        for(int i=0;i<n;i++) cin>>str1>>str2, U(str1), U(str2), v.push_back({str1,str2}), hash[str1]=str2;
        for(int i=0;i<n;i++)
        {
           vector<string> tmpv;string tmp=v[i].s;int minlen=v[i].s.size();
           while(hash.find(tmp)!=hash.end())
           {
               minlen=min(minlen,(int)tmp.size());
               tmp=hash[tmp];
           }
           bool trans=0;
           if(minlen!=v[i].s.size()) trans=1;
           hashlen[v[i].f]={minlen, trans};
        }
        int mint=0, minttlen=0;
        for(int i=0;i<v.size();i++)
        {
            mint+=hashlen[v[i].f].s;
            minttlen+=hashlen[v[i].f].f;
        }

        cout<<mint<<" "<<minttlen<<endl;
    }

	return 0;
}
