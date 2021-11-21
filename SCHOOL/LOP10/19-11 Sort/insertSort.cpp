#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100000];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=2;i<=n;i++){
        for (int j=i;j>=1;j--){
            if (a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
        }
        for (int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    for (int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}