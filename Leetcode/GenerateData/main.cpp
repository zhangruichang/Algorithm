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
void generatestr(){
  for(int i=0;i<=100;i++){
    cout<<"\"";
    for(int j=0;j<i;j++){
      int ch=rand()%26+'a';
      putchar(ch);
    }
    puts("\"");
  }
}

void adddouble(){
  string str;
  srand (time(NULL));
  while(cin>>str){
    double x=rand()%40/7.0000;
    cout<<str<<endl;
    printf("%.6f\n", x);
  }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("ClosestBST.txt" , "r" , stdin);
    freopen ("ClosestBSTin.txt" , "w" , stdout);
#endif
  adddouble();


	return 0;
}
