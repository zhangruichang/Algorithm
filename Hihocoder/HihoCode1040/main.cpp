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
#include<sstream>
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
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
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
    return !m ? n : GCD(n%m, m);
}


int n, t, m;

int x1[4], y11[4], x2[4], y2[4];
map<pii, int> mymap;

int main()
{
    cin>>t;
    while(t--)
    {
        mymap.clear();
        bool ok=1;
        for(int i=0;i<4;i++)
        {
            cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
            if( x1[i] == x2[i] && y11[i] == y2[i])
                ok=0;//check line is a point, two point cross
            mymap[{x1[i], y11[i]}]++;//
            mymap[{x2[i], y2[i]}]++;//get differenct point num, must be 4
        }

        if(mymap.size()!=4)
            ok=0;
        for(auto e: mymap)
        {
            if(e.se!=2) {
                    ok=0;
            }//each point times is 2
            int i;
            int curx=e.fi.fi, cury=e.fi.se, X1, Y1, X2, Y2;
            for(i=0;i<4;i++)
            {
                if(x1[i]==curx && y11[i] == cury)//find one point in 8 point of input
                {
                    //X1=x1[i], y11=y11[i];
                    X1=x2[i], Y1=y2[i];//then get another point of this line
                    break;
                } else if( x2[i] == curx && y2[i] == cury)
                {
                    //X1=x2[i], Y1=y2[i];
                    X1=x1[i], Y1=y11[i];
                    break;
                }
            }
            i++;
            for(;i<4;i++)
            {
                if(x1[i]==curx && y11[i] == cury)//find one point
                {
                    //X1=x1[i], y11=y11[i];
                    X2=x2[i], Y2=y2[i];
                    break;
                } else if( x2[i] == curx && y2[i] == cury)
                {
                    //X1=x2[i], y11=y2[i];
                    X2=x1[i], Y2=y11[i];
                    break;
                }
            }
            int deltax1=X1-curx, deltay1=Y1-cury;//pan chuizhi, buyong pingxing
            int deltax2=X2-curx, deltay2=Y2-cury;
            if(deltay1 * deltay2 + deltax1 * deltax2) {
                    ok=0;
            }
        }
        puts(ok?"YES" : "NO");
    }
	return 0;
}
