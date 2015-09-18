#ifndef STRSTR_PERMUTATION_H_INCLUDED
#define STRSTR_PERMUTATION_H_INCLUDED
/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
class Strstr_Permutation{
public:
  bool strstr_permutation(string str, string pat){
    int pat_cnt[128], str_cnt[128];
    fill_n(pat_cnt, 128, 0);
    fill_n(str_cnt, 128, 0);
    for(auto e: pat) pat_cnt[e]++;
    int m=str.size(), n=pat.size();
    if(m<n) return 0;
    for(int i=0;i<n;i++){
      str_cnt[str[i]]++;
    }
    bool is_match=1;
    for(int i=0;i<128;i++){
      if(str_cnt[i]!=pat_cnt[i]){
        is_match=0;
        break;
      }
    }
    if(is_match) return 1;
    for(int e=n;e<m;e++){
      str_cnt[str[e-n]]--;
      str_cnt[str[e]]++;
      bool is_match=1;
      for(int i=0;i<128;i++){
        if(str_cnt[i]!=pat_cnt[i]){
          is_match=0;
          break;
        }
      }
      if(is_match) return 1;
    }
    return 0;
  }
};

#endif // STRSTR_PERMUTATION_H_INCLUDED
