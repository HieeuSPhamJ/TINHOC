#include<bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    while(test--){
        int n,m;
        for (int i=1;i<=n;i++){
            for (int e=1;e<=m;e++){
                cin>>a[i][e];
            }
        }
        cout<<endl;
    }


}