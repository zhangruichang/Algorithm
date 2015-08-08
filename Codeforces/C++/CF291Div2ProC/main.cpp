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
struct Node
{
    bool isWord;
    Node* child[3];
    Node():isWord(0)
    {
        for(int i=0;i<3;i++) child[i]=NULL;
    }
};

inline void Trie(const string& str, Node*root)
{
    Node* p=root;
    for(int i=0;i<str.size();i++)
    {
        int index=str[i]-'a';
        if(!p->child[index]) p->child[index]=new Node();
        p=p->child[index];
    }
    p->isWord=1;
}
inline void FreeTrie(Node* root)
{
    if(!root) return ;
    for(int i=0;i<3;i++) if(root->child[i])FreeTrie(root->child[i]);
    delete[] root;
}
/*
inline bool Query(string str)
{
    Node* p=&root;bool difcnt=0;
    for(int i=0;i<str.size();i++)
    {
        int index=str[i]-'a';
        if(!p->child[index])
        {
            int j;
            for(j=0;j<3;j++) if(p->child[j]) break;
            if(j==3) return 0;
            p=p->child[j];
            if(!difcnt)difcnt=1;
            else return 0;
        }
        else p=p->child[index];
    }
    return p->isWord;
}*/
bool dfs(int i, const string& str, Node* r, int difcnt)
{
    if(difcnt>=2) return 0;
    if(i==str.size()) return r->isWord && difcnt==1;
    Node* p=r;
    int index=str[i]-'a';
    for(int k=0;k<3;k++)
    {
        if(k==index)
        {
            if(p->child[k])
            {
                if(dfs(i+1, str, p->child[k], difcnt)) return 1;
            }
        }
        else
        {
            if(p->child[k])
            {
                if(dfs(i+1, str, p->child[k], difcnt+1)) return 1;
            }
        }
    }
    return 0;
    //else return dfs(i+1, str, p->child[index], difcnt);
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, m;
    string str;
    while(cin>>n>>m)
    {
        Node *root=new Node();
        //for(int i=0;i<3;i++) root.child[i]=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            Trie(str, root);
        }
        for(int i=0;i<m;i++)
        {
            //string str;
            cin>>str;
            puts(dfs(0, str, root, 0)?"YES":"NO");
        }
        FreeTrie(root);
    }
	return 0;
}
