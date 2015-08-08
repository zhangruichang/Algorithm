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
#include<iostream>
#include <sstream>
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
typedef vector<int> vi;
#define fi first
#define se second
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

int a[maxn], n, t, m;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

    string s, e;
    while(cin>>s>>e){
    int rs=s[1]-'0', cs=s[0]-'a', re=e[1]-'0', ce=e[0]-'a';
    if(re>=rs && ce>=cs)
    {
        if(re-rs < ce-cs)
        {
            int dif=ce-cs-(re-rs);
            cout<<re-rs+dif<<endl;
            for(int i=0;i<re-rs;i++)
                cout<<"RU"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"R"<<endl;
        }
        else
        {
            int dif=(re-rs)-(ce-cs);
            cout<<ce-cs+dif<<endl;
            for(int i=0;i<ce-cs;i++)
                cout<<"RU"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"U"<<endl;
        }
    }
    else if(re<rs && ce<cs)
    {
        if(rs-re < cs-ce)
        {
            int dif=cs-ce-(rs-re);
            cout<<rs-re+dif<<endl;
            for(int i=0;i<rs-re;i++)
                cout<<"LD"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"L"<<endl;
        }
        else
        {
            int dif=(rs-re)-(cs-ce);
            cout<<cs-ce+dif<<endl;
            for(int i=0;i<cs-ce;i++)
                cout<<"LD"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"D"<<endl;
        }
    }
    else if(re>=rs && ce<cs)
    {
        if(re-rs < cs-ce)
        {
            int dif=cs-ce-(re-rs);
            cout<<re-rs+dif<<endl;
            for(int i=0;i<re-rs;i++)
                cout<<"LU"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"L"<<endl;
        }
        else
        {
            int dif=(re-rs)-(cs-ce);
            cout<<cs-ce+dif<<endl;
            for(int i=0;i<cs-ce;i++)
                cout<<"LU"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"U"<<endl;
        }
    }
    else
    {
        if(rs-re < ce-cs)
        {
            int dif=ce-cs-(rs-re);
            cout<<rs-re+dif<<endl;
            for(int i=0;i<rs-re;i++)
                cout<<"RD"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"R"<<endl;
        }
        else
        {
            int dif=(rs-re)-(ce-cs);
            cout<<ce-cs+dif<<endl;
            for(int i=0;i<ce-cs;i++)
                cout<<"RD"<<endl;
            for(int i=0;i<dif;i++)
                cout<<"D"<<endl;
        }
    }}
	return 0;
}

/*
int main() {
    Init() ;
    for ( int i = 1 ; i <= 8 ; i ++ ) for ( int j = 1 ; j <= 8 ; j ++ ) {
        if ( i == tx ) d[i][j] = "R" ;

    }
}*/
