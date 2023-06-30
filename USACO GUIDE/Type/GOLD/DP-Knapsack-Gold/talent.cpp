#include<bits/stdc++.h>
#define ii pair <int,int>
#define talent first
#define weight second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxW = 2e6 + 10;

int dp[maxW];

vector <ii> ls;

ii max(ii a, ii b){
    if (a.talent * b.weight < b.talent * a.weight){
        return b;
    }
    return a;
}

/*
a.talent / a.weight > b.talent / b.weight
a
*/

signed main(){
    // freopen("talent.in", "r", stdin);
    // freopen("talent.out", "W", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, W;
    cin >> n >> W;
    ii res = {0,1};

    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if (a >= W){
            res = max(res, {b,a});
        }
        ls.push_back({b,a});
    }
    sort(all(ls));
    for (auto i: ls){
        for (int w = 1e6 + W; w >= 0; w--){
            dp[w + i.weight] = max(dp[w + i.weight], dp[w] + i.talent);
        }
    }
    for (int w = W; w < maxW; w++){
        res = max(res, {dp[w],w});
    }
    // cout << res.talent << " " << res.weight << endl;
    cout << (int)( 1000 * ((double) res.talent / res.weight)) << endl;
    return 0;
}