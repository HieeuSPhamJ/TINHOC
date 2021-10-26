#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
    if ((n[0]-'0'+n[2]-'0')/2==n[1]-'0') cout<<"yes";
    else cout<<"no";
    return 0;
}