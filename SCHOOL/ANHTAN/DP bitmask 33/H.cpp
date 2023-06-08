#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 4e5 + 10;

int n;
int a[maxN];
int nn = 0;

void nenso(){
    map <int,int> s;
    for (int i = 1; i <= n; i++){
        s[a[i]]++;
    }
    for (auto &i: s){
        i.se = nn;
        nn++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = s[a[i]];
        // cout << a[i] << " ";
    }
    // cout << endl;
}

vector <int> sto[maxN];
vector <int> maskWith[maxN];
int dp[1 << 20];
int cost[1 << 20][21];
int c[21][21];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    
    for (int i = 1; i <= n; i++){
        sto[a[i]].push_back(i);
    }

    // cout << nn << endl;

    for (int i = 0; i < nn; i++){
        for (int j = 0; j < nn; j++){
            if (i == j){
                continue;
            }
            for (auto x: sto[i]){
                c[i][j] += (lower_bound(all(sto[j]), x) - sto[j].begin());
            }
            // cout << i << ' ' << j << " " << c[i][j] << endl;
        }
    }

    for (int mask = 0; mask < (1 << nn); mask++){
        maskWith[__builtin_popcount(mask)].push_back(mask);
        dp[mask] = 1e18;
        for (int i = 0; i < nn; i++){
            if (mask & (1 << i)){
                continue;
            }
            for (int j = 0; j < nn; j++){
                if (mask & (1 << j) or i == j){
                    continue;
                }
                cost[mask][i] += c[i][j];   
            } 
        } 
    }
    dp[0] = 0;
    for (int i = 0; i < nn; i++){
        for (auto mask: maskWith[i]){
            int curr = dp[mask];
            for (int t = 0; t < nn; t++){
                if (mask & (1 << t)){
                    continue;
                }
                int nmask = mask | (1 << t);
                dp[nmask] = min(dp[nmask], curr + cost[mask][t]);
            }   
            // cout << bitset<3>(mask) << " " << dp[mask] << endl;
        }
    }
    cout << dp[(1 << nn) - 1];
    return 0;
}