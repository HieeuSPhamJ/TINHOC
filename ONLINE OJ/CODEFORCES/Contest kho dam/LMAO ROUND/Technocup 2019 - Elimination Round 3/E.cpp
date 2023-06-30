#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 110;

int a[maxN];
int dp[maxN][maxN * maxN];
unordered_map <int,int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        cnt[a[i]]++;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        for (int j = i - 1; j >= 0; j--){
            for (int s = sum - a[i]; s >= 0; s--){
                dp[j + 1][s + a[i]] += dp[j][s];
                if (dp[j + 1][s + a[i]]){
                    // cout << j + 1 << ' ' << s + a[i] << " " << dp[j + 1][s + a[i]] << endl;
                }
            }
        }
    }
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        for (int s = 0; s <= sum; s++){
            if (dp[i][s] == 1){
                ls.push_back({i,s});
                cout << i << ' ' << s << endl;
            }
        }
    }
    int res = 0;
    int rs = 0;
    for (auto ss: ls){
        int k = ss.fi;
        int s = ss.se;
        for (int i = 1; i <= n; i++){
            if (s % a[i] == 0 and cnt[a[i]] * a[i] >= s){
                // cout << k << " " << s << " " << a[i] << endl;
                if (res < k){
                    res = k;            
                    rs = s;
                }
            }
        }
    }

    if (cnt.size() == 2){
        cout << n << endl;
    }
    else{
        cout << res << endl;
    }

    return 0;
}