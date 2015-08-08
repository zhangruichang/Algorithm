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

void matrixsidling(vector<vector<int>> A)
{
    int m=A.size(), n=A[0].size();
    int i=0, j=n-1;
    for(int ii=1;ii<=m+n-1;ii++)
    {
        for(int k=0;i+k<m && j+k<n;k++)
            cout<<A[i+k][j+k]<<" ";
        cout<<endl;
        if(j>=1) j--;
        else if(i<m-1) i++;
    }
}

void MatrixSidingN(int n)
{
    for(int i=1;i<=2*n-1;i++)
    {
        if(i<n)
        {
            for(int j=1;j<=i;j++)
                cout<<n+1-i+(j-1)*(n+1)<<" ";
            cout<<endl;
        }
        else
        {
            for(int j=1;j<=(2*n-i);j++)
                cout<<1+(i-n)*n+(j-1)*(n+1)<<" ";
            cout<<endl;
        }
    }
}
struct x
{
    long english;
    short* cost[7];
    struct x*next, *last;
};
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //short a='\077';
    //cout<<sizeof(struct x);
    //cout<<d[0].a+d[1].b-d[1].a;
    //vector<vector<int>> A={{1,2,3},{4,5,6},{7,8,9}};
    //matrixsidling(A);
	int n=2;
	MatrixSidingN(n);
	return 0;
}
