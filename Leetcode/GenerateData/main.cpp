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

vector<string> split(string s, char split){
  vector<string> ans;
  int start=0, n=s.size();
  for(int i=0;i<s.size();i++){
    if(s[i]==split){
      if(i!=start)
        ans.push_back(s.substr(start, i-start));
      start=i+1;
    }
  }
  if(n!=start)
    ans.push_back(s.substr(start, n-start));
  return ans;
}

void adddouble_k(){
  string str;
  srand (time(NULL));
  while(cin>>str){
    double x=rand()%40/7.0000;
    cout<<str<<endl;
    printf("%.6f\n", x);
    string cur=str.substr(1, str.size()-2);
    auto strlist=split(cur, ',');
    int cnt=0;
    for(auto e: strlist){
      if(e!="null") cnt++;
    }
    if(!cnt) cout<<0<<endl;
    else cout<<rand()%cnt+1<<endl;
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

void generate_matrix(){
  srand (time(NULL));
  for(int len=0;len<=100;len++){
      cout<<"[";
      int n=rand()%20+1;
      if(!len) n=0;
      for(int i=0;i<len;i++){
          if(i) cout<<",";
          cout<<"[";
          for(int j=0;j<n;j++){
              if(j) cout<<",";
              int x=rand()%3, y;
              if(x==0) y=-1;
              else if(x==1) y=0;
              else y=INT_MAX;
              cout<<y;
          }
          cout<<"]";
      }
      cout<<"]"<<endl;;
  }
}

void generate_vectorstring(){
  srand(time(NULL));
  for(int len=0;len<=100;len++){
    cout<<"[";
    int n=rand()%20+1;
    for(int i=0;i<n;i++){
      if(i) cout<<",";
      cout<<"\"";
      int len=rand()%10+1;
      for(int j=0;j<len;j++){
        cout<<char(rand()%26+'a');
      }
      cout<<"\"";
    }
    cout<<"]\n";
  }
}
int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("ClosestBST.txt" , "r" , stdin);
    freopen ("decodeDict.txt" , "w" , stdout);
#endif
  generate_vectorstring();


	return 0;
}
