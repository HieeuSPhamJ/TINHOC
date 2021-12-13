#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++){
        if (abs(a[i]-a[i-1])>1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}