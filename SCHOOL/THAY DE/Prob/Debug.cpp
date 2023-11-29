#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

const int base1 = 2;
const int base2 = 2;

int n, m;
int a[310][310];
int hash1[310][310];
int hash2[310][310];
int po1[310];
int po2[310];
int prefix[310][310];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}


void init(){
    po1[0] = 1;
    po2[0] = 1;
    for (int i = 1; i <= max(n,m); i++){
        po1[i] = po1[i - 1] * base1;
        po2[i] = po2[i - 1] * base2;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            hash1[i][j] = mul(hash1[i - 1][j],base1) + mul(hash1[i][j - 1], base2);
            hash1[i][j] = subtr(hash1[i][j], mul(hash1[i - 1][j - 1], base1 * base2));
            hash1[i][j] = add(hash1[i][j], a[i][j]);
        }
    }

    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            hash2[i][j] = mul(hash2[i + 1][j],base1) + mul(hash2[i][j + 1], base2);
            hash2[i][j] = subtr(hash2[i][j], mul(hash2[i + 1][j + 1], base1 * base2));
            hash2[i][j] = add(hash2[i][j], a[i][j]);
        }
    }
}

int gethash1(ii a, ii b){
    a.fi--;
    a.se--;
    int p1 = po1[abs(b.fi - a.fi)];
    int p2 = po2[abs(b.se - a.se)];
    // cout << p1 << " " << p2 << endl;
    // cout << a.fi << " " << a.se << " " << b.fi << " " << b.se << endl;
    int hash = hash1[b.fi][b.se];
    // cout << hash << endl;
    hash = subtr(hash, mul(hash1[b.fi][a.se], p2));
    // cout << hash << " " << mul(hash1[b.fi][a.se], p1) << endl;
    hash = subtr(hash, mul(hash1[a.fi][b.se], p1));
    // cout << hash << " " << mul(hash1[a.fi][b.se], p2) << endl;
    hash = add(hash, mul(hash1[a.fi][b.se], mul(hash1[a.fi][a.se],mul(p1,p2))));
    return hash;
}

int gethash2(ii b, ii a){
    a.fi++;
    a.se++;
    int p1 = po1[abs(b.fi - a.fi)];
    int p2 = po2[abs(b.se - a.se)];
    cout << p1 << " " << p2 << endl;
    cout << a.fi << " " << a.se << " " << b.fi << " " << b.se << endl;
    int hash = hash2[b.fi][b.se];
    cout << hash << endl;
    hash = subtr(hash, mul(hash2[b.fi][a.se], p1));
    cout << hash << " " << mul(hash2[b.fi][a.se], p1) << endl;
    hash = subtr(hash, mul(hash2[a.fi][b.se], p2));
    cout << hash << " " << mul(hash2[a.fi][b.se], p2) << endl;
    hash = add(hash, mul(hash2[a.fi][b.se], mul(hash2[a.fi][a.se],mul(p1,p2))));
    return hash;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            a[i][j] = (x == '1') + 1;
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][i - 1] + (x == '1');
        }
    }

    init();

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << hash1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << hash2[i][j] << " ";
        }
        cout << endl;
    }

    cout << gethash1({3,1}, {5,3}) << " " << gethash2({3,1}, {5,3}) << endl;
    // cout << gethash1({1,1}, {3,3}) << " " << gethash2({1,1}, {3,3}) << endl;

    int ans = -1;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         for (int k = max(1ll,ans - 1); i + k <= n and j + k <= m; k++){
    //             ii p = {i,j};
    //             ii q = {i + k, j + k};
    //             int sum = prefix[q.fi][q.se] - prefix[p.fi][q.se] - prefix[q.fi][p.se] + prefix[p.fi][p.se];
    //             int area = abs(q.fi - p.fi) * abs(q.se - p.se);
    //             if (sum != area and gethash1(p,q) == gethash2(p,q)){
    //                 ans = max(ans, k + 1);
    //             }
    //         }
    //     }
    // }
    cout << ans << endl;

    return 0;
}

/*
1458 - 99 * 8 - 163 * 8 - 11 * 8 * 8
*/