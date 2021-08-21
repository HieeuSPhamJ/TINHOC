#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char a[1000010];
    cin>>n;


    int count=0,s=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]=='D') count--;e
        else{
        if (count==-1)  s++;
        count++;
        }
    }
    cout<<s;
    return 0;
}
