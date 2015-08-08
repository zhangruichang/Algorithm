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
//#include <unordered_set>
//#include <unordered_map>
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
LL a[maxn];
LL prefix[maxn];
map<LL, LL> hash;
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
int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif

    int t, n, k;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        hash.clear();
        n=getint();k=getint();
        for(int i=0;i<n;i++) a[i]=getint();
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        LL sum=0;
        if((n&1)==0)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(i&1) sum-=a[i];
                else sum+=a[i];
                prefix[i]=sum;
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(i&1) sum-=a[i];
                else sum+=a[i];
                prefix[i]=sum;
            }
        }
        //for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
        //cout<<endl;
        prefix[n]=0;
        for(int i=0;i<n;i++) hash[prefix[i]]=i;
        hash[0]=n;
        int i;
        for(i=0;i<n;i++)
        {
            if(i&1)
            {
                if(hash.find(prefix[i]+k)!=hash.end() && hash[prefix[i]+k]>i)
                {
                    //cout<<i<<" "<<k<<" "<<prefix[i]<<endl;
                    break;
                }

            }
            else
            {
                if(hash.find(prefix[i]-k)!=hash.end() && hash[prefix[i]-k]>i)
                {
                    //cout<<i<<" "<<k<<" "<<prefix[i]<<endl;
                    break;
                }
            }
        }
L1:     printf("Case #%d: ", ti);
        puts(i<n?"Yes.":"No.");
    }

	return 0;
}
