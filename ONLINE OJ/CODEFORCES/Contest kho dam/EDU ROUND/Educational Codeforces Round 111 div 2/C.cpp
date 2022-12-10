#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

int check(int l, int r){
    // cout << l << " " << r << endl;
    for (int i = l; i <= r - 2; i++){
        for (int j = i + 1; j <= r - 1; j++){
            for (int k = j + 1; k <= r; k++){
                // cout << i << " " << j << " " << k << endl;
                if (min(a[i], a[k]) <= a[j] and a[j] <= max(a[i], a[k])){
                    return 0;
                }
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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 0; i + j <= n and j <= 3; j++){
                if (check(i,i + j)){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}