#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector <int>
#define fi first
#define se second
#define ii pair<int , int>
#define FOR(i , a , b) for(int i = a ;i <= b ; i += 1)
#define FORD(i , a , b) for(int i = a ;i >= b ; i -= 1)
#define REP(i , a) for(int i = 0 ;i < a ; i += 1)

const int oo = 1e18 + 7;
const int MOD = 1e9 + 7;

int n , m;
int a[2005];
int F[2005];
int G[2005][2005];

int sol(int n , int k){
    if(k == 1) return F[n] * n;
    if(G[n][k] != -1) return G[n][k];
    int Min = oo;
    FORD(i , n , k){
        Min = min(Min , sol(i - 1 , k - 1) + (F[n] - F[i - 1]) * (n - i + 1));
    }
    G[n][k] = Min;
    return Min;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("AQUARIUM.inp" , "r" , stdin);
    freopen("AQUARIUM.out" , "w" , stdout);
    cin >> n >> m;
    FOR(i , 1 , n){
        FOR(j , 1 ,m ) G[i][j] = -1;
    }
    FOR(i , 1 , n) cin >> a[i];
    sort(a + 1 , a + 1 + n);
    FOR(i , 1 , n) F[i] = F[i - 1] + a[i];
    if(n == m) return cout << F[n] , 0;
    if(m == 2){
        int ans = oo;
        FOR(i , 2 , n - 1) ans = min(ans , F[i] * i + (F[n] - F[i]) * (n - i));
        return cout << ans , 0;
    }
    int ans = oo;
    FORD(i , n , m){
        ans = min(ans , sol(i - 1, m - 1) + (F[n] - F[i - 1]) * (n - i + 1));
    }
    cout << ans;
    return 0;
}
