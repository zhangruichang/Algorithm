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

string str[8];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>str[0])
    {
        for(int i=1;i<8;i++) cin>>str[i];
        int wscore=0, bscore=0;
        for(int i=0;i<8;i++) for(int j=0;j<8;j++)
        {
            if(str[i][j]=='Q') wscore+=9;
            else if(str[i][j]=='q') bscore+=9;
            else if(str[i][j]=='R') wscore+=5;
            else if(str[i][j]=='r') bscore+=5;
            else if(str[i][j]=='B') wscore+=3;
            else if(str[i][j]=='b') bscore+=3;
            else if(str[i][j]=='N') wscore+=3;
            else if(str[i][j]=='n') bscore+=3;
            else if(str[i][j]=='P') wscore+=1;
            else if(str[i][j]=='p') bscore+=1;
        }
        if(wscore>bscore) cout<<"White"<<endl;
        else if(wscore<bscore) cout<<"Black"<<endl;
        else cout<<"Draw"<<endl;
    }

	return 0;
}
