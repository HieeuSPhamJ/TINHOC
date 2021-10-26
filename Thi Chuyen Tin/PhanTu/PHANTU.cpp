#include<bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int k=1;
    int ans=0;
    for (int i=1;i<=n and k<=m;i++){
        while (a[i]>b[k]) k++;
        if (a[i]==b[k]) ans++;
    }
    cout<<ans;
return 0;
}
