#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ii pair <int,int>
#define endl '\n'
#define all(x) x.begin() x.end()
using namespace std;

const int inf = 1e18;
const int ninf = -1e18;
const int maxN = 1e5 + 10;

int n, m, p, c;

int a[maxN];
int s[maxN];
int dp[maxN];
int dp2[maxN][5];

void solvem1(){

    int ans = ninf;
    int len = s[1];
    dp[0] = ninf;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if (i - len >= 0){
            int delta = (a[i] - a[i - len + 1]);
            dp[i] = max(dp[i], max(0ll,dp[i - len]) + p - delta * delta * c);
        }
//        cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
//    cout << endl;
    cout << ans << endl;
}

void solvem2(){
//    for (int i = 1; i <= n; i++){
//        cout << a[i] << " ";
//    }
//    cout << endl;

    int ans = ninf;
    dp2[0][0] = ninf;
    dp2[0][1] = ninf;
    dp2[0][2] = ninf;
    dp2[0][3] = ninf;
    for (int i = 1; i <= n; i++){
        for (int mask = 1; mask <= 2; mask++){
            dp2[i][mask] = dp2[i - 1][mask];
//            cout << "State: " << i << " " << bitset<2>(mask) << ": " << endl;
            for (int j = 1; j <= m; j++){
//                    cout << (mask & (1 << (j - 1))) << endl;
                if ((mask & (1 << (j - 1))) == 0){
                    continue;
                }
                int len = s[j];
                if (i - len < 0){
                    continue;
                }
//                cout << j << ":" << endl;
                set <int> premask;
                premask.insert(mask);

                for (auto pre: premask){
                    int delta = (a[i] - a[i - len + 1]);
                    int cost = max(0ll,dp2[i - len][pre]) + p - delta * delta * c;
//                    cout << bitset<2>(pre) << " " << cost << endl;
                    dp2[i][mask] = max(dp2[i][mask], cost);
                }
            }
        }
        dp2[i][3] = dp2[i - 1][3];

        int l1 = s[1];
        int l2 = s[2];
        int d1 = a[i] - a[i - l1 + 1];
        int d2 = a[i] - a[i - l2 + 1];
        int x1 = p - d1 * d1 * c;
        int x2 = p - d2 * d2 * c;
        int c1 = dp2[i - l1][2] + x1;
        int c2 = dp2[i - l2][1] + x2;
        if (i - l1 >= 0 and dp2[i - l1][2] != ninf){
//            cout << "add 1: " << i << " " << dp2[i - l1][2] << " " << x1 << endl;
            dp2[i][3] = max(dp2[i][3], c1);
        }
        if (i - l2 >= 0 and dp2[i - l2][1] != ninf){
//            cout << "add 2: " << i << " " << dp2[i - l2][1] << " " << x2 << endl;
            dp2[i][3] = max(dp2[i][3], c2);
        }

        if (i - l1 >= 0 and dp2[i - l1][3] != ninf){
//            cout << "add 1 to 3: " << i << endl;
            dp2[i][3] = max(dp2[i][3], dp2[i - l1][3] + x1);
        }
        if (i - l2 >= 0 and dp2[i - l2][3] != ninf){
//            cout << "add 2 to 3: " << i << endl;
            dp2[i][3] = max(dp2[i][3], dp2[i - l2][3] + x2);
        }

        if (dp2[i][3] != ninf){
            ans = max(ans, dp2[i][3]);
        }
    }
//    for (int mask = 1; mask < 4; mask++){
//        for (int i = 1; i <= n; i++){
//            int t = dp2[i][mask];
//            if (t == ninf){
//                cout << "i ";
//                continue;
//            }
//            cout << t << " ";
//        }
//        cout << endl;
//    }
    cout << ans << endl;
}

int ans = -1e18;

vector <ii> sto;

void backtrack(int id, int mask){

    if (mask == (1 << m) - 1){
        int res = 0;
//        cout << "===Check===" << endl;
        for(auto i: sto){
            int delta = a[i.fi + s[i.se] - 1] - a[i.fi];
            int cost = p - delta * delta * c;
            res += cost;
//            cout << i.fi << " " << i.fi + s[i.se] - 1 << endl;
//            cout << i.se << " " << delta << " " << cost << endl;
        }
//        cout << res << endl;
        ans = max(ans,res);
    }
    if (id >= n){
        return;
    }
    for (int i = 1; i <= m; i++){
        if (id + s[i] <= n){
            sto.push_back({id + 1, i});
            backtrack(id + s[i], mask | (1 << (i - 1)));
            sto.pop_back();
        }
    }
    backtrack(id + 1, mask);
}

signed main(){
//    freopen("input.inp", "r", stdin);
//    freopen("B.out", "w", stdout);
    // freopen("WHOME.INP", "r", stdin);
    // freopen("WHOME.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p >> c;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> s[i];
    }
    sort(a + 1, a + 1 + n);
    if (m == 1){
        solvem1();
        return 0;
    }
    if (m == 2){
        solvem2();
        return 0;
    }
    backtrack(0,0);
    cout << ans << endl;

    return 0;
}

/*
10 2 11 1
14 5 6 4 4 4 7 8 9 1
4 2

4 1 7 2
8 5 4 7
3
*/
