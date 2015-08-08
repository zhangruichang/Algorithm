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
    int c1, c2;
    while(cin>>c1)
    {
        unordered_map<int, int> hash;
        hash[c1]++;
        for(int i=1;i<=5;i++) cin>>c2, hash[c2]++;
        //cin>>c2>>c3>>c4>>c5>>c6;
        int cnt=0, leg; bool ele=0;
        for(auto e: hash)
        {
            if(e.second>=4) cnt++, leg=e.first;
            else if(e.second>=2) ele=1;
        }
        if(cnt!=1) cout<<"Alien"<<endl;
        else
        {
            vector<int> ans;
            for(auto e: hash)
            {
                if(e.second<4) ans.push_back(e.first);
            }
            if(ans.size()==0) cout<<"Elephant"<<endl;
            else if(ans.size()==1)
            {
                //if(leg!=ans[0]) cout<<"Bear"<<endl;
                puts(ele ? "Elephant" : "Bear");//<<endl;
            }
            else
            {
                cout<<"Bear"<<endl;
            }
        }
    }
	return 0;
}
