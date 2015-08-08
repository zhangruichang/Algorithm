#ifndef INVERSEPAIRCNT_H
#define INVERSEPAIRCNT_H
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class InversePairCnt
{
    public:
        InversePairCnt();
        int InversePairCnt1(vector<int>& v)
        {
            int n=v.size();
            return mergesort(v, 0, n-1);
        }
        int mergesort(vector<int>& v, int low, int high)
        {
            if(low==high) return 0;
            int mid=(low+high)/2;
            int leftcnt=mergesort(v, low, mid), rightcnt=mergesort(v, mid+1, high);
            int i=mid, j=high, k=high-low;
            int cnt=0;
            vector<int> copy(high-low+1, 0);
            while(i>=low && j>=mid+1)
            {
                if(v[i]<=v[j])//== not cnt
                {
                    //if(v[i]==v[j]) cnt++;
                    copy[k--]=v[j--];
                }
                else
                    cnt+=j-mid, copy[k--]=v[i--];
            }
            if(i>=low)
                for(int ii=i;ii>=low;ii--) copy[k--]=v[ii];
            else if(j>=mid+1)
                for(int jj=j;jj>=mid+1;jj--) copy[k--]=v[jj];
            for(int i=low;i<=high;i++)
                v[i]=copy[i-low];
            //cout<<"left: "<<leftcnt<<"right: "<<rightcnt<<"cnt: "<<cnt<<endl;
            return leftcnt+rightcnt+cnt;
        }
        virtual ~InversePairCnt();
    protected:
    private:
};

#endif // INVERSEPAIRCNT_H
