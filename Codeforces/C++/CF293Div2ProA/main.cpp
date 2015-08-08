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
    string str1, str2;
    while(cin>>str1>>str2)
    {
        int n=str1.size();
        int c=1;
        for(int i=n-1;i>=0;i--)
        {
            str1[i]+=c;
            if(str1[i]>'z') str1[i]='a',c=1;
            else c=0;
            if(!c) break;
        }
        if(str1!=str2) cout<<str1<<endl;
        else cout<<"No such string"<<endl;
    }

	return 0;
}
