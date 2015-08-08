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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

struct Node
{
    int cnt;//suffix cnt
    Node* ch[26];
    Node()
    {
        cnt=0;
        for(int i=0;i<26;i++) ch[i]=NULL;
    }
};
Node root;
int BuildTrie()
{
    root.cnt=0;
    for(int i=0;i<26;i++) root.ch[i]=NULL;
    int n;
    cin>>n;
    //cin>>str;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        Node* p=&root;
        int x=0;
        for(int j=0;j<str.size();j++)
        {
            int chi=str[j]-'a';
            if(!(p->ch[chi]))
            {
                p->ch[chi]=new Node(), p=p->ch[chi], p->cnt=1;
                if(!x) x=j+1;//,cout<<"x "<<x<<endl;
            }
            else
                p=p->ch[chi], p->cnt++;
        }
        if(!x) x=str.size();
        cnt+=x;
    }
    return cnt;
}

int main()
{
    freopen("autocomplete.txt","r",stdin);
    freopen("autocomplete_out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cout<<"Case #"<<ti<<": "<<BuildTrie()<<endl;
    }
	return 0;
}
