#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED
/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

class Binary_Search{
  public:
    int FindElementCountinSortedArray(vector<int> v, int x){
      return upperbound(v, x)-lowerbound(v,x);
    }

    int lowerbound(vector<int> v, int x){
      int n=v.size();
      int low = 0 , high = n;
      while(low<high){
        int mid=(low+high)/2;
        if(x <= v[mid]){
          high=mid;
        }else{
          low=mid+1;
        }
      }
      return low;
    }

    int upperbound(vector<int> v, int x){
      int n=v.size();
      int low = 0 , high = n;
      while(low<high){
        int mid=(low+high)/2;
        if(x < v[mid]){
          high=mid;
        }else{
          low=mid+1;
        }
      }
      return low;
    }
};

#endif // BINARYSEARCH_H_INCLUDED
