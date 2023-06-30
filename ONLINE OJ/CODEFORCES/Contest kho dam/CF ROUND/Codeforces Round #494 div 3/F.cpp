#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 310;
const ii mod = {1e9 + 7, 1e9 + 9};
const ii base = {maxN, 30};
int a[maxN];
int cost[maxN];
ii ha[maxN];
ii po[maxN];

ii mul(ii a, ii b){
    return {((a.fi % mod.fi) * (b.fi % mod.fi)) % mod.fi, ((a.se % mod.se) * (b.se % mod.se)) % mod.se};
}

ii add(ii a, ii b){
    return {(a.fi + b.fi) % mod.fi, (a.se + b.se) % mod.se};
}

ii sub(ii a, ii b){
    return {(a.fi - b.fi + mod.fi) % mod.fi, (a.se - b.se + mod.se) % mod.se};
}

ii get(int i, int j){
    // cout << ha[j] << " " << ha[i - 1] << " " << po[j - i + 1] << endl;
    return sub(ha[j], mul(ha[i - 1], po[j - i + 1]));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<string,int> cnt;
    po[0] = {1,1};
    for (int i = 1, last = 0; i <= n; i++){
        string s;
        cin >> s;
        if (cnt[s] == 0){
            last++;
            cnt[s] = last;
        }
        cost[i] = cost[i - 1] + s.length();
        a[i] = cnt[s];
        po[i] = mul(po[i - 1], base);
        ha[i] = add(mul(ha[i - 1], base), {a[i], a[i]});
        // cout << po[i] << " ";
    }
    // cout << endl;
    // cout << get(1,1) << endl << get(5,5) << endl;
    int ans = cost[n] + n - 1;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int res = cost[n] + n - 1;
            ii nh = get(i,j);
            int len = (j - i + 1);
            int co = (cost[j] - cost[i - 1] + len) - (len + 1);
            int cnt = 1;
            res -= co;
            // cout << "With: " << i << " " << j << " " << res << endl;
            for (int k = j + 1, last = -1; k + len - 1 <= n; k++){
                // cout << nh << " " << get(k, k + len - 1) << endl;
                if (get(k, k + len - 1) == nh){
                    k = k + len - 1;
                    res -= co;
                    cnt++;
                    // cout << k - len + 1 << endl;
                }
            }
            if (cnt >= 2){
                if (ans > res){
                    // cout << i << ' ' << j << " " << res << " " << cost[j] - cost[i - 1] << endl;
                    for (int k = j + 1, last = -1; k + len - 1 <= n; k++){
                        if (get(k, k + len - 1) == nh){
                            k = k + len - 1;
                            // cout << k - len + 1 << " " << k << endl;
                        }
                    }
                }
                ans = min(ans, res);
            }
        }
    }

    // if (ans == 1000000000000000000){
    //     for (int i = 15 ; i <= n; i++){
    //         cout << a[i] << " ";
    //         if (i % 150 == 0){
    //             cout << endl;
    //         }
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 1011 12 13 1415 16 17 18 1920 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 4344 45
2 1 2 2 1 1 1 2 2 1 1  1  1  1 1  1  1  2  1 2  1  2  2  1  2  2  2  1  1  1  2  2  2  2  2  1  1  2  1  1  1  1  1 1  2 
1 2 3 4 5 5 6 7 8 9 10 11 12 6 13 14 14 15 6 16 17 18 19 20 21 22 23 17 24 25 26 27 28 29 26 30 10 31 32 33 34 20 9 14 35 
7 24
6 7 8 9 10 11 12 6 13 14 14 15 6 16 17 18 19 20
1 2 2 1 1  1  1  1 1  1  1  2  1 2  1  2  2  1
2 2 2 1 1  1  2  2 2  2  2  1  1 2  1  1  1  1

1 2 3 4 5 5 6 7 8 9 10 11 12 6 13 14 14 15 6 16 17 18 19 20 21 22 23 17 24 25 26 27 28 29 26 30 10 31 32 33 34 20 9 14 35
*/