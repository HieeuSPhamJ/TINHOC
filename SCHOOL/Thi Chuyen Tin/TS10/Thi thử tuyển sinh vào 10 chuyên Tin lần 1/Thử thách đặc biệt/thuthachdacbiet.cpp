#include<bits/stdc++.h>
using namespace std;



int main (){
    int n,s=0;
    int a[100010];
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        s+=a[i];
    }
    cout<<s/n;


return 0;
}