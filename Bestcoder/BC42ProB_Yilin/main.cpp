#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#define REP(I,A,B) for (register int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for (register int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define RLL(X) scanf("%I64d",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

const int MAXN =1e5+5;

struct node
{
  int h;
  int num;
}t[MAXN]={0},q[MAXN]={0};

int ans[MAXN]={0};
int n,m;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void open()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}

void init()
{
  REP(i,1,n)
  {
    t[i].h=read();
    t[i].num=i;
  }
  REP(i,1,m)
    q[i].h=read(),
    q[i].num=i;
}

bool cmp (node a,node b)
{
  if (a.h!=b.h)
    return a.h<b.h;
  else
    return a.num<b.num;
}

void work()
{
  int now=1;
  t[n+1].h=0;
  REP(i,1,m)
  {
    while (t[now].h<q[i].h && now<=n)
      now++;
    if (q[i].h==t[now].h)
    {
      ans[q[i].num]=t[now].num;
      now++;
    }
    else
      ans[q[i].num]=-1;
  }
  REP(i,1,m)
    printf("%d\n",ans[i]);
}

int main()
{
  open();
  while (~RI(n) && ~RI(m))
  {
    init();
    sort(t+1,t+1+n,cmp);
    sort(q+1,q+1+m,cmp);
    work();
  }
  close();
  return 0;
}
