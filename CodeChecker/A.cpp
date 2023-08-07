#include<bits/stdc++.h>
using namespace std;
const int N = 1<<20 + 1;
int n,m,a[N],ans[N];
bool f[21][21][N];
map <int,int> mp;
main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n >>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
        mp[a[i]]++;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=i;j++){
            for (int k=0;k<=1<<m;k++){
                int x = f[i-1][j-1][k^(1<<(i-1))];
                if (j == 1) x = mp[k^(1<<(i-1))]&&1;
                f[i][j][k] = f[i-1][j][k]||x;
                if (f[i][j][k]) ans[k] = j;
            }
        }
    }
    for (int i=1;i<=n;i++) cout <<ans[a[i]] <<" ";
}