#include<bits/stdc++.h>
#pragma GCC optimization ("O2")
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e7 + 10;

int a[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, x, A, B, M;
    cin >> n >> k >> x >> A >> B >> M;
    a[1] = x;
    for (int i = 2; i <= n; i++){
        a[i] = (a[i - 1] * A + B) % M;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    dp[0] = 0;
    deque <int> segment;
    segment.push_back(0);
    for (int i = 1; i <= n + 1; i++){
        dp[i] = dp[segment.front()] + a[i];
        while(!segment.empty() and dp[segment.back()] >= dp[i]){
            segment.pop_back();
        }
        segment.push_back(i);
        if (segment.front() + k <= i){
            segment.pop_front();
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n + 1];
    return 0;
}