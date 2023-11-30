#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cnt[33];
int temp[33];

void solve(int x){
    for (int i = 0; i <= 32; i++){
        temp[i] = cnt[i];
    }
    int res = 0;
    while (x > 0){
        int id = log2(x);
        x = x - (1 << id);
        int ok = 1;
        while (ok > 0 and id >= 0){
            int lmao = min(ok, temp[id]);
            res += lmao;
            ok -= lmao;
            temp[id] -= lmao;
            id--;
            ok <<= 1;
        }
        if (ok > 0){
            cout << -1 << endl;
            return;
        }
    }

    cout << res << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int test;
    cin >> test;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[(int)log2(x)]++;
    }
    while(test--){
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}