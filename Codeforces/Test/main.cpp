#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0X6FFFFFFF;
const int MS = 1005;

struct node {
    int price;
    int cnt;
    //int d;
   bool operator < (const node &a) const {
        return price > a.price;
    }
};



node node1[MS];
node node2[MS];
char str[MS];
int n, s;
int p,q;

int flag1[MS];
int flag2[MS];
int c1,c2;


int main() {
    scanf("%d%d", &n, &s);
    c1 = c2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", str, &p, &q);
        if (str[0] == 'S') {
            node1[c1].price = p;
            node1[c1++].cnt = q;
           // node1[c1++].d = 0;
        }
        else {
            node2[c2].price = p;
            node2[c2++].cnt = q;
           // node2[c2++].d = 1;
        }
    }

   // printf("%d --- %d\n", c1, c2);
    memset(flag1,0,sizeof(flag1));
    memset(flag2,0,sizeof(flag2));
    int cc1 = 0;
    int cc2 = 0;

    for (int i = 0; i < c1 ; i++) {
        if (flag1[i] == 1)
            continue;
        node1[cc1] = node1[i];
        for (int j = i +1; j < c1; j++) {
            if (node1[i].price == node1[j].price) {
                node1[cc1].cnt += node1[j].cnt;
                flag1[j] = 1;
            }
        }
        cc1++;
    }
    sort(node1,node1 + cc1);
    if (cc1 < s) {
          for (int i = 0; i < cc1; i++)
             printf("S %d %d\n",node1[i].price,node1[i].cnt);
    }
    else {
        for (int i = 0; i < s; i++)
            printf("S %d %d\n",node1[i+cc1-s].price,node1[i+cc1-s].cnt);
    }
    for (int i = 0; i < c2 ; i++) {
        if (flag2[i])
            continue;
        node1[cc2] = node2[i];
        for (int j = i +1; j < c2; j++) {
            if (node2[i].price == node2[j].price) {
                node2[cc2].cnt += node2[j].cnt;
                flag2[j] = 1;
            }
        }
        cc2++;
    }
    sort(node2,node2 + cc2);
    if (cc2 < s) {
            for (int i = 0; i < cc2; i++)
                printf("B %d %d\n",node2[i].price,node2[i].cnt);
    }
    else {
        for (int i = 0; i < s; i++)
            printf("B %d %d\n",node2[i].price,node2[i].cnt);
    }
    return 0;
}
