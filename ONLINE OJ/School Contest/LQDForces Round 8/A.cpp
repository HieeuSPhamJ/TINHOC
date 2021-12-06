#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int e=1;e<=m;e++){
            int inp;
            cin>>inp;
            if (inp){
                cout<<1;
            }
            else cout<<' ';
            if (e<m){
                cout<<' ';
            }
        }
        if (i<n){
                cout<<"\n";
            }
        // cout<<endl;
    }

    return 0;
}