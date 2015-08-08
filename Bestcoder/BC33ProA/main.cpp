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
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
char DigToCh(int num)
{
    if(num<=9) return char(num+'0');
    else return char(num-10+'a');
}

int ChToDig(char c)
{
    if(c<='9' && c>='0') return (c-'0');
    else return c-'a'+10;
}
char str[100][201];
int Len[100];
/*
void RemoveLeadZero(char*str, int &n)
{
    int i;
    for(i=0;i<n;i++)
        if(str[i]!='0') break;
    if(i==n)
    {
        str[0]='0', str[1]='\0',n=1;
        return ;
    }
    int save=0;
    for(;i<n;i++) str[save++]=str[i];
    str[save]='\0';
    n=save;
}*/
void RemoveBehindZero(char* str, int &n)
{
    int i;
    for(i=n-1;i>=0;i--) if(str[i]!='0') break;
    if(i<0)
    {
        str[0]='0', str[1]='\0', n=1;
        return ;
    }
    str[i+1]='\0';
    n=i+1;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, b;
    while(cin>>n>>b)
    {
        for(int i=0;i<n;i++) scanf("%s", str[i]), getchar();
        //for(int i=0;i<n;i++) cout<<str[i]<<endl;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            int len=strlen(str[i]);
            //RemoveLeadZero(str[i], len);
            reverse(str[i], str[i]+len);
            Len[i]=len;
            maxlen=max(maxlen,len);// (int)str[i].size());
        }
        char ans[maxn];int ansi=0;
        for(int i=0;i<maxlen;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(i<Len[j]) sum+=ChToDig(str[j][i]);
            }
            sum%=b;
            ans[ansi++]=DigToCh(sum);
            //ans.push_back();
        }
        ans[ansi]='\0';
        int len=ansi;
        RemoveBehindZero(ans, len);
        reverse(ans, ans+len);
        cout<<ans<<endl;
    }
	return 0;
}
