#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[100][100];

void solve1(){
    int n, g;
    cin >> n >> g;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
           cin >> a[i][j];
            a[i][j] = (a[i][j] < g);
        }
    }
    
}

void solve2(){

}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    if (t == 1){
        solve1();
    }
    else{
        solve2();
    }
    return 0;
}