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
//#include <unordered_set>
//#include <unordered_map>
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
void BuildTrie()
{
    root.cnt=0;
    for(int i=0;i<26;i++) root.ch[i]=NULL;
    int n;
    cin>>n;
    string str;//cin>>str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        Node* p=&root;
        for(int j=0;j<str.size();j++)
        {
            int chi=str[j]-'a';
            if(!(p->ch[chi]))
                p->ch[chi]=new Node(), p=p->ch[chi], p->cnt=1;
            else
                p=p->ch[chi], p->cnt++;
        }
    }
}
void Query()
{
    int m;
    cin>>m;
    string str;
    for(int i=0;i<m;i++)
    {
        cin>>str;
        Node*p=&root;
        int j;
        for(j=0;j<str.size();j++)
        {
            int chi=str[j]-'a';
            if(!(p->ch[chi])) break;
            p=p->ch[chi];
        }
        if(j==str.size()) cout<<p->cnt<<endl;
        else cout<<"0"<<endl;
    }
}
int main()
{
    BuildTrie();
    Query();
	return 0;
}
