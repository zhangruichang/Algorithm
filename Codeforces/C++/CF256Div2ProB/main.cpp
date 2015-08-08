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
    while(cin>>s)
    {
        cin>>t;
        int sn=s.size(), tn=t.size();
        if(sn<tn) puts("need tree");
        else if(sn==tn)
        {
            sort(s.begin(), s.end());sort(t.begin(), t.end());
            puts(s==t?"array":"need tree");
        }
        else
        {
            int i, j;
            for(i=0,j=0;i<s.size() && j<t.size();)
            {
                if(s[i]==t[j]) i++, j++;
                else i++;
            }
            if(j==t.size()) puts("automaton");
            else
            {
                sort(s.begin(), s.end());sort(t.begin(), t.end());
                for(i=0,j=0;i<s.size() && j<t.size();)
                {
                    if(s[i]==t[j]) i++, j++;
                    else i++;
                }
                if(j==t.size()) puts("both");
                else puts("need tree");
            }
        }
    }

	return 0;
}
