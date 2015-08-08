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
const int MOD=1e9+7;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
char dna[maxn];

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n;
    while(cin>>n)
    {
        scanf("%s", dna);
        int A=0, G=0, T=0, C=0, maxt=0;
        for(int i=0;i<n;i++)
        {
            switch(dna[i])
            {
            case 'A':
                A++;break;
            case 'T':
                T++;break;
            case 'C':
                C++;break;
            case 'G':
                G++;break;
            }
        }
        maxt=max(max(T,G), max(A, C));
        int cnt=0;
        if(maxt==A) cnt++;
        if(maxt==T) cnt++;
        if(maxt==G) cnt++;
        if(maxt==C) cnt++;
        LL ans=1;
        for(int i=0;i<n;i++)
            ans=(ans*cnt)%MOD;
        cout<<ans<<endl;
    }

	return 0;
}
