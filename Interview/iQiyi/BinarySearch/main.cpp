/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
#include "BinarySearch.h"
#include "Strstr_Permutation.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

int GCD(int m, int n){
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;

int main()
{
  Binary_Search BS;
  vector<int> v={0, 1, 100};
  int x= 101;
  cout<<BS.FindElementCountinSortedArray(v, x)<<endl;
  string str="abas", pat="cbdg";
  Strstr_Permutation strstr;
  cout<<strstr.strstr_permutation(str, pat)<<endl;

  return 0;
}
