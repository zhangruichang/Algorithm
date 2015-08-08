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
    int n, m;
    while(cin>>n>>m)
    {
        unordered_map<string,string> hash;
        string str1, str2;
        for(int i=0;i<m;i++) cin>>str1>>str2,hash[str1]=str2;
        string ans;
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            string sec=hash[str];
            if(str.size()<=sec.size()) ans+=str+" ";
            else ans+=sec+" ";
        }
        ans.pop_back();
        cout<<ans<<endl;
    }
	return 0;
}
