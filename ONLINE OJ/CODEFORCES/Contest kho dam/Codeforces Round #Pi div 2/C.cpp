#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int a[maxN];

map <int, int> cnt[4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        if (a[i] % k == 0){
            cnt[3][a[i]] += cnt[2][a[i] / k];
            cnt[2][a[i]] += cnt[1][a[i] / k];
        }
        cnt[1][a[i]]++;
    }

    int ans = 0;

    // for (int x = 1; x <= 3; x++){
    //     for (int i = 1; i <= n; i++){
    //         cout << cnt[x][i] << " ";
    //     }
    //     cout << endl;
    // }

    for (auto i: cnt[3]){
        ans += i.se;
    }
    
    cout << ans;
    return 0;
}