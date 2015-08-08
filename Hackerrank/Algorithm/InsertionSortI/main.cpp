#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  a)
{
    int i, n=a.size(), x=a.back();
    for(i=n-2;i>=0 && a[i]>x;i--)
    {
        a[i+1]=a[i];
        for(auto e: a) cout<<e<<" ";
        cout<<endl;
    }
    a[i+1]=x;
    for(auto e: a) cout<<e<<" ";
    cout<<endl;
}
int main(void)
{
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++)
    {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);

    return 0;
}
