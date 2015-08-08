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
typedef pair<int, int> pii;
pii a[maxn], b[maxn];
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
        int x;
        for(int i=0;i<n;i++) cin>>x, a[i]={x, i};
        sort(a, a+n);
        int cnt=0;bool three=0;
        int twopos1=-1, twopos2=-1, threepos=-1, i;
        for(i=1;i<n;i++)
        {
            if(a[i].first==a[i-1].first)
            {
                cnt++;
                if(i-2>=0 && a[i-1].first==a[i-2].first)
                    {three=1;threepos=i-2;break;}
                else
                {
                    if(twopos1==-1) twopos1=i-1;
                    else if(twopos2==-1) twopos2=i-1;
                }
                if(cnt>=2) break;
            }
        }
        if(i==n) cout<<"NO"<<endl;
        else
        {
            if(three)
            {
                puts("YES");
                for(int i=0;i<n;i++) cout<<a[i].second+1<<" ";
                cout<<endl;
                for(int i=0;i<n;i++) b[i]=a[i];
                swap(b[threepos], b[threepos+1]);
                for(int i=0;i<n;i++) cout<<b[i].second+1<<" ";
                cout<<endl;
                swap(b[threepos+1], b[threepos+2]);
                for(int i=0;i<n;i++) cout<<b[i].second+1<<" ";
                cout<<endl;
            }
            else if(cnt>=2)
            {
                puts("YES");
                for(int i=0;i<n;i++) cout<<a[i].second+1<<" ";
                cout<<endl;
                for(int i=0;i<n;i++) b[i]=a[i];
                swap(b[twopos1], b[twopos1+1]);
                for(int i=0;i<n;i++) cout<<b[i].second+1<<" ";
                cout<<endl;
                swap(b[twopos2], b[twopos2+1]);
                for(int i=0;i<n;i++) cout<<b[i].second+1<<" ";
                cout<<endl;
            }
        }
    }

	return 0;
}
