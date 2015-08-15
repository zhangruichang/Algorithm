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
#include<sstream>
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
int a[maxn], n, t, m;

struct Node{
  int x;
  Node* left, *right;
  Node(int x_): x(x_), left(NULL), right(NULL){}
};

bool success;

Node* f(vector<int> pre, int pres, int pree, vector<int> post, int posts, int poste){
  if(pree>pres || poste>posts) return NULL;
  int i, val=pre[pres+1];
  for(i=posts;i<=poste-1;i++){
    if(post[i]==val) break;
  }
  if(i==poste-1){
    success=false;
    return NULL;
  }
  int leftlen=i-posts+1;
  Node* root=new Node(pre[pres]);
  root->left=f(pre, pres+1, pres+1+leftlen-1, post, posts, i);
  root->right=f(pre, pres+leftlen+1, pree, post, i+1, poste);
  return root;
}

Node* Build(vector<int> pre, vector<int> post){
  if(pre.size()!=post.size() || pre.empty() ||post.empty()) return NULL;
  int n=pre.size();
  success=true;
  Node* root=f(pre, 0, n-1, post, 0, n-1);
  if(success) return root;
  else return NULL;
}

int f1(vector<int> pre, int pres, int pree, vector<int> post, int posts, int poste){
  if(pree>pres || poste>posts) return 1;
  int i, val=pre[pres+1];
  for(i=posts;i<=poste-1;i++){
    if(post[i]==val) break;
  }
  /*
  if(i==poste-1){
    success=false;
    return 0;
  }*/
  int leftlen=i-posts+1;
  //Node* root=new Node(pre[pres]);
  int leftcnt=f1(pre, pres+1, pres+1+leftlen-1, post, posts, i);
  int rightcnt=f1(pre, pres+leftlen+1, pree, post, i+1, poste);
  return leftcnt*rightcnt;
}

int Count(vector<int> pre, vector<int> post)
{
  return f1(pre, 0, n-1, post, 0, n-1);
}


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

	return 0;
}
