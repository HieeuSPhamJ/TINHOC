#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
    int length=n.length()+1;
    int maxChar=0;
    while(length--){
        maxChar=max(maxChar,n[length]-'0');
    }
    cout<<maxChar;
    return 0; 
}