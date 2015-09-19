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
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-'){
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n){
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;

class Solution {
public:
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
  int stoi(string s){
    int num=0;
    for(auto e: s){
      num=num*10+e-'0';
    }
    return num;
  }
  int calculate(string s) {
    if(s=="") return 0;
    s='#'+s+'#';
    stack<char> oprst;
    stack<int> numst;
    for(int i=0;i<s.size();i++){
      if(s[i]==' ') continue;
      if(isdigit(s[i])){
        int start=i;
        while(i<s.size() && isdigit(s[i])) i++;
        numst.push(stoi(s.substr(start, i-start)));
        i--;
      }else{
        if(!oprst.empty() && higher(oprst.top(), s[i])){
          while(!oprst.empty() && higher(oprst.top(), s[i])){
            int num2=numst.top();numst.pop();
            int num1=numst.top();numst.pop();
            char op1=oprst.top();oprst.pop();
            numst.push(calc(num1, op1, num2));
          }
          oprst.push(s[i]);
        }else if(!oprst.empty() && oprst.top()=='#' && s[i] == '#'){
          break;
        }else{
          oprst.push(s[i]);
        }
      }
    }
    return numst.top();
  }
  bool higher(char op1, char op2){
    if(op1=='#') return 0;
    if(op1=='*' || op1=='/') return 1;
    if(op1=='+' || op1=='-') return op2=='#' || op2=='+' || op2=='-';
  }

  int calc(int num1, char op1, int num2){
    if(op1=='+') return num1+num2;
    else if(op1=='-') return num1-num2;
    else if(op1=='*') return num1*num2;
    else return num1/num2;
  }
} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  string s=" 3+5 / 2 ";
  cout<<S.calculate(s)<<endl;
	return 0;
}
