#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;
const int maxANS=1e7+10;
int a[maxN];
int ans[maxANS];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        a[inp]++;
    }
    int count=1;
    for (int i=maxN;i>=1;i--){
        for (int e=1;e<=a[i];e++){
            ans[count]=i;
            count++;
            // cout<<ans[count-1]<<' ';
        }
        
    }
    for (int i=1;i<=m;i++){
        int inp;
        cin>>inp;
        cout<<ans[inp]<<' ';
    }
    return 0;
}