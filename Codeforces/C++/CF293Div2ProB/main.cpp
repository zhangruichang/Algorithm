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

bool v[maxn];
int c1a[26], c1A[26], c2a[26], c2A[26];
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
        memset(v, 0, sizeof v);memset(c1a, 0, sizeof c1a);memset(c1A, 0, sizeof c1A);
        memset(c2a, 0, sizeof c2a);memset(c2A, 0, sizeof c2A);
        /*for(int i=0;i<str1.size();i++)
        {
            if(str1[i]<='z')
                c1a[str1[i]-'a']++;
            else c1A[str1[i]-'A']++;
        }*/
        for(int i=0;i<str2.size();i++)
        {
            if(str2[i]>='a')
                c2a[str2[i]-'a']++;
            else c2A[str2[i]-'A']++;
        }
        int Y=0, W=0;

        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]>='a')
            {
                if(c2a[str1[i]-'a']>0)
                {
                    Y++,c2a[str1[i]-'a']--, v[i]=1;
                }
            }
            else
            {
                if(c2A[str1[i]-'A']>0)
                {
                    Y++,c2A[str1[i]-'A']--, v[i]=1;
                }
            }
        }
        for(int i=0;i<str1.size();i++)
        {
            if(v[i]) continue;
            if(str1[i]>='a')
            {
                if(c2A[str1[i]-'a']>0)
                {W++,c2A[str1[i]-'a']--;}
            }
            else
            {
                if(c2a[str1[i]-'A']>0)
                {W++,c2a[str1[i]-'A']--;}
            }
        }
        cout<<Y<<" "<<W<<endl;
    }

	return 0;
}
