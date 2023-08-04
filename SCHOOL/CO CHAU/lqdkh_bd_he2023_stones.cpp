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

int a[maxN];
int sum[3][maxN];

signed main(){
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[1][i] = sum[1][i - 1] + a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        sum[2][i] = sum[2][i - 1] + a[i];
    }

    int test;
    cin >> test;
    while(test--){
        int t, l, r;
        cin >> t >> l >> r;
        cout << sum[t][r] - sum[t][l - 1] << endl;
    }
    return 0;
}

/*
1 2 3 4 5 6
6 4 2 7 2 7
2 2 4 6 7 7

*/