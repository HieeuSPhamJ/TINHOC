#include<bits/stdc++.h>
using namespace std;

bool


int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int count=0;
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,count);
        if (check(a[i])){
            count++;
        }
        else{
            count=0;
        }
    }
    for (int i=1;i<=n;i++){
        ans=max(ans,count);
        if (check(a[i])){
            count++;
        }
        else{
            count=0;
        }
    }
    cout<<count;
    return 0;
}