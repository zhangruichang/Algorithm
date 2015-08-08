/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int n,  m;

int mp[26][26];
//unordered_map<char, vector< pair<char, int> > > um1, um2;
string s,t;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>n;
    cin>>s>>t;
    int cnt=0, p1, p2;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
            mp[s[i]-'a'][t[i]-'a']=i+1, cnt++;
    }
    bool flag=0;
    for(int i=0;i<26;i++) for(int j=0;j<26;j++)
    {
        if(i==j || !mp[i][j]) continue;
        if(mp[j][i])
        {
            //cnt-=2;
            p1=mp[i][j], p2=mp[j][i];
            cout<<cnt-2<<endl<<p1<<" "<<p2<<endl;
            return 0;
        }
        else
        {
            for(int k=0;k<26;k++)
            {
                if(mp[k][i])
                {
                    //cout<<cnt-1<<endl;
                    p1=mp[i][j], p2=mp[k][i];
                    flag=1;
                }
            }
        }
    }
    if(flag) cout<<cnt-1<<endl<<p1<<" "<<p2<<endl;
    else
    {
        cout<<cnt<<endl;
        puts("-1 -1");
    }
    return 0;
}
