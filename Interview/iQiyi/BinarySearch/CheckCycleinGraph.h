#ifndef CHECKCYCLEINGRAPH_H_INCLUDED
#define CHECKCYCLEINGRAPH_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

class Topo{
public:
  //time: O(n+e), space: O(n)
  bool CheckCycleinGraph_adjlist(){
    //int n=v[0].size();
    int indeg[n];
    fill_n(indeg, n, 0);
    for(int i=0;i<n;i++){
      for(auto e:edge[i]){
        indeg[e]++;
      }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
      if(!indeg[i]) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
      auto cur=q.front();q.pop();
      cnt++;
      for(auto e: edge[cur]){
        if(!(--indeg[e])) q.push(e);
      }
    }
    return cnt==n;
  }
  //time: O(n^2), space: O(n)
  bool CheckCycleinGraph_mat(){
    //int n=v[0].size();
    int indeg[n];
    fill_n(indeg, n, 0);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        indeg[j]+=mat[i][j];
      }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
      if(!indeg[i]) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
      auto cur=q.front();q.pop();
      cnt++;
      for(auto e: mat[cur]){
        if(!(--indeg[e])) q.push(e);
      }
    }
    return cnt==n;
  }
};


#endif // CHECKCYCLEINGRAPH_H_INCLUDED
