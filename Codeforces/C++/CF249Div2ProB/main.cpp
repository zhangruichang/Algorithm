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
    string str;int k;
    while(cin>>str>>k)
    {
        int n=str.size();
        //for(auto &e: str) e-='0';
        for(int i=0;i<n && k>0;i++)
        {
            int maxpos=0;
            for(int j=1;j<=k;j++)
            {
                if(i+j<n && str[i+j]>str[i] && str[i+j]>str[i+maxpos])
                    maxpos=j;
            }
            for(int j=i+maxpos;j<n && j>=i+1;j--) swap(str[j-1], str[j]);
            k-=maxpos;
        }
        //for(auto &e: str) e+='0';
        cout<<str<<endl;
    }
	return 0;
}
