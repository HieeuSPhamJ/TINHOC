#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define price fi
#define num se
// #define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxN = 6010;
const int mod = 1e9 + 7;

ii a[maxN];

bool cmp(ii x, ii y){
    return x.price < x.price;
}
int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i].num >> a[i].price;
    }

    sort(a + 1,a + 1 + n,cmp);
    for (int i = 0; i <= a[1].num and i * a[1].price <= s; i++){
        dp[1][i * a[1].price] = 1;
    }
    for (int i = 2; i <= n; i++){
        // cout << "Index: " << i << endl;
        for (int start = 0; start < a[i].price; start++){
            // deque <int> lists;
            // lists.push_back(start);
            for (int sum = dp[i - 1][start], size = 1, last = start; last <= s;){
                // for (auto x: lists){
                //     cout << x << " ";
                // }
                // cout << endl;
                dp[i][last] = add(dp[i][last], sum);
                last = add(last,a[i].price);
                // lists.push_back(last);
                sum = add(sum, dp[i - 1][last]);
                size++;
                while (size > a[i].num + 1){
                    size--;
                    sum = subtr(sum,dp[i - 1][last - (a[i].num + 1) * a[i].price]);
                }
            }
            // cout << endl;
        }

        // for (int money = 0; money <= s; money++){
        //     cout << "DP: " << i << " " << money << endl;
        //     for (int take = 0; take <= a[i].num and take * a[i].price <= money; take++){
        //         cout << take << " " << money - take * a[i].price << endl;
        //         (dp[i][money] += dp[i - 1][money - take * a[i].price]) %= mod;
        //     }
        // }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for (int j = 1; j <= s; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][s];
    return 0;
}