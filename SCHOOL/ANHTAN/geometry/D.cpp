#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
ii a[maxN];

int len(ii a, ii b){
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se  - b.se) * (a.se - b.se); 
}

bool check(int l, int r){
    for (int i = l; i <= r; i++){
        for (int j = i - 1; j >= l; j--){
            if (len(a[i], a[j]) > k){
                return 0;
            }
        }
    }
    return 1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    k *= k;
    int ans = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        int l = 1;
        int r = i - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (check(mid, i)){
                r = mid - 1;
                ans = max(ans, i - mid + 1);
            }
            else{
                l = mid + 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}