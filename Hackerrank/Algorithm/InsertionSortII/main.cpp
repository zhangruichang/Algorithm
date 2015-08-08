#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
void insertionSort(int n, int *  a) {
    for(int i=1;i<n;i++)
    {
        int j=i;
        int x=a[j];
        for(j=i-1;j>=0 && a[j]>x;j--)
            a[j+1]=a[j];
        a[j+1]=x;
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
    }
}
int main(void) {

    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]);
    }

   insertionSort(_ar_size, _ar);

   return 0;
}
