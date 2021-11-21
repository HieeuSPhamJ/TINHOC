#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1000];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=i;j++){
            if (a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}