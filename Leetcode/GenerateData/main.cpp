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

int a[maxn], n, t, m;

void generaten_k(){
  srand (time(NULL));
  for(int len=0;len<=100;){
      int k=rand()%20+1;
      if(k==1 && len>1) continue;
      cout<<"[";
      for(int i=0;i<len;i++){
          if(i) cout<<",";
          cout<<"[";
          for(int j=0;j<k;j++){
              if(j) cout<<",";
              cout<<rand()%20+1;
          }
          cout<<"]";
      }
      cout<<"]"<<endl;;
      len++;
  }
}

void generatetwointeger(){
  srand (time(NULL));
  for(int n=0;n<=7;n++) for(int k=0;k<=7;k++){
    cout<<n<<endl<<k<<endl;
  }
}

int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    freopen ("FencePaint.txt" , "w" , stdout);
#endif
  generatetwointeger();


	return 0;
}
