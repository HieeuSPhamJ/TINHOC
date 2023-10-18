#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];
int pre[40][maxN];
int pre0[40][maxN];

int LOG2(int x){
    if (x == 0){
        return -1;
    }
    return log2(x);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int la = 0;
        for (int j = 0; j <= 32; j++){
            pre[i][j] = pre[i - 1][j];
            pre0[i][j] = pre0[i - 1][j];
            if (a[i] & (1ll << j)){
                la = j;
            }
        }
        pre[i][la]++;
        if (a[i] == 0){
            continue;
        }
        la = LOG2(a[i]) + 1;
        // cout << i << ' ' << la << endl;
        pre0[i][la]++;
    }

    int test;
    cin >> test;
    while(test--){
        int l, r, x;
        cin >> l >> r >> x;
        int res = 0;
        // cout << l << " " << r << " " << x << endl;
        for (int j = 32; j >= 0; j--){
            if (x & (1ll << j)){
                break;
            }
            // cout << j << " " << pre[r][j] - pre[l - 1][j] << endl;
            res += pre[r][j] - pre[l - 1][j];
        }
        for (int j = LOG2(x); j >= 0; j--){
            res += pre0[r][j] - pre0[l - 1][j];
        }
        cout << res << endl;
    }
    return 0;
}

/*
101 => 001 | 100
100 => 000 | 100
011 => 111 | 000 
010 => 110 | 000
001 => 101 | 000

100

101 => 111 | 000
100 => 110 | 000
011 => 001 | 010 
010 => 000 | 010

010

*/