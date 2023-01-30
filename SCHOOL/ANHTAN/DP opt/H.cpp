#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, k;
int a[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    deque <int> d;
    d.push_back(0);
    for (int i = 1; i <= n + 1; ++i) {
        while (d.size() and d.front() < i - k){
            d.pop_front();
        }
        dp[i] = dp[d.front()] + a[i];
        while (d.size() and dp[d.back()] >= dp[i]){
            d.pop_back();
        }
        d.push_back(i);
    }
    cout << sum - dp[n + 1] << endl;
    return 0;
}