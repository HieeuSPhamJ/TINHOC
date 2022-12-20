#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxMOD = 2 * 1e3 + 10;

int n, mod;
int bit[maxMOD];
int a[(int)1e6 + 10];

void update(int i, int v){
    i++;
    while(i <= n){
        bit[i] = max(bit[i], v);
        i += (i & (-i));
    }
}

int get(int i){
    int res = 0;
    i++;
    while(i){
        res = max(res, bit[i]);
        i -= (i & (-i));
    }
    return res;
}

void sub12(){
    a[1] = 1 % mod;
    a[2] = 1 % mod;
    for (int i = 3; i <= n; i++){
        a[i] = (a[i - 1] + a[i - 2]) % mod;
        
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        // cout << a[i] << " ";
        int t = get(a[i]) + 1;
        ans = max(t,ans);
        update(a[i],t);
    }
    // cout << endl;
    cout << ans << endl;
}

void sub34(){
}

signed main(){
    //freopen("LISFIBO.inp", "r", stdin);
    //freopen("LISFIBO.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> mod;
    if (n <= 1e6){
        sub12();
    }    
    else{
        sub34();
    }
    return 0;
}