#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iomanip>
#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Max(a,b) (((a) > (b)) ? (a) : (b))
#define read freopen("Din.txt","r",stdin)  
#define write freopen("out.txt","w",stdout)
using namespace std;
int n,k;
vector<string> Ans;
void ZRC(string x, int a, int b)
{
	if(a+b==2*n) Ans.push_back(x);
	else
	{
		if(a<n)
			ZRC(x+"(",a+1,b);
		if(b<a)
			ZRC(x+")",a,b+1);
	}
}

int main()
{
	read;
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		Ans.clear();
		scanf("%d%d",&n,&k);
		//n=3;
		ZRC("",0,0);
		cout<<"Case #"<<i<<": ";
		if(k-1<Ans.size())
			cout<<Ans[k-1]<<endl;
		else
			cout<<"Doesn't Exist!"<<endl;
		/*
		for(int i=0;i<Ans.size();i++)
			cout<<Ans[i]<<" ";
		cout<<endl;*/
	}
	return 0;
}