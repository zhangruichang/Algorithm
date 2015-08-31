#include<iostream>
#include <string>
using namespace std;


void rev(string& s, int st, int en){
    for(int i=st, j=en; i<j ;i++, j--){
        swap(s[i], s[j]);
    }
}

void reversestring(string& s){
    int n=s.size();
    rev(s, 0, n-1);
    for(int i=0, start=0; i<n;i++){
        if(s[i]==' '){
            rev(s, start, i-1);
            start=i+1;
        }
    }
}


int main(){
    string s="I am Zhang Ruichang";
    reversestring(s);
    cout<<s<<endl;
}