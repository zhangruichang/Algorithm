#include <cstdio>
#include <cmath>
using namespace std;

int Jie(int n){
    if(n<=1) return 1;
    return n*Jie(n-1);
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n;scanf("%d", &n);
    while(n--){
        double x;
        scanf("%lf", &x);
        printf("%.3f\n", x-pow(x, 3)/Jie(3)+pow(x, 5)/Jie(5)-pow(x, 7)/Jie(7)+pow(x, 9)/Jie(9));
        printf("%.3f\n", 1-pow(x, 2)/Jie(2)+pow(x, 4)/Jie(4)-pow(x, 6)/Jie(6)+pow(x, 8)/Jie(8));
    }
	return 0;
}
