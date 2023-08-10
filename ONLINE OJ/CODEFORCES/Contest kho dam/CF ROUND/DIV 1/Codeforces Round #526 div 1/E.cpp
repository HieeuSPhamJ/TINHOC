/*
2:40 24/6/2023
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define X fi.fi
#define Y fi.se
#define V se
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int dp[maxN];

struct line{
    int a,b;
    line(int _a, int _b){
        a = _a;
        b = _b;
    }
    int cal(int x){
        return a * x + b;
    }
};

struct CVH{
    vector <line> ls;
    int check(line l1, line l2, line l3){
        if (1.0 * (l1.b - l3.b) / (l3.a - l1.a)  <= 1.0 * (l1.b - l2.b) / (l2.a - l1.a)){
            return 1;
        }
        return 0;
    }
    void add(line x){
        while(ls.size() >= 2 and check(ls[ls.size() - 2], ls.back(), x)){
            ls.pop_back();
        }
        ls.push_back(x);
    }
    int last = 0;
    int cal(int x){
        int l = last;
        int r = ls.size() - 1;
        int res = 0;
        // cout << "cnp" << endl;
        while(l <= r){
            int mid = (l + r) / 2;
            int now = ls[mid].cal(x);
            res = max(res, now);
            last = mid;
            // cout << l << ' ' << r << " " << mid << " " << now << " " << endl;
            // if (mid != 0){
            //     cout << ls[mid - 1].cal(x) << " ";
            // }
            // else{
            //     cout << -1 << " ";
            // }
            // if (mid != ls.size() - 1){
            //     cout << ls[mid + 1].cal(x) << endl;
            // }
            // else{
            //     cout << -1 << endl;
            // }
            if (mid != 0 and now < ls[mid - 1].cal(x)){
                // cout << "-" << endl;
                r = mid - 1;
            }
            else if (mid + 1 != ls.size() and now < ls[mid + 1].cal(x)){
                // cout << "+" << endl;
                l = mid + 1;
            }
            else{
                break;
            }
        }
        // cout << "ecnp" << endl;
        return res;
    }
} cvh;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <pair<ii,int>> ls;
    for (int i = 1; i <= n; i++){
        int x, y, v;
        cin >> x >> y >> v;
        ls.push_back({{x,y}, v});
    }
    sort(all(ls));
    int res = 0;
    // for (int i = 0; i < n; i++){
    //     dp[i] = ls[i].X * ls[i].Y - ls[i].V;
    //     for (int j = i - 1; j >= 0; j--){
    //         dp[i] = max(dp[i], dp[j] - ls[j].X * ls[i].Y + ls[i].X * ls[i].Y - ls[i].V);
    //     }
    //     res = max(res, dp[i]);
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    
    for (int i = 0; i < n; i++){
        // cout << "With: " << i << endl;
        dp[i] = ls[i].X * ls[i].Y - ls[i].V;
        int in = cvh.cal(-ls[i].Y);
        // cout << in << " " << ls[i].X * ls[i].Y - ls[i].V << endl;
        dp[i] = max(dp[i], in + ls[i].X * ls[i].Y - ls[i].V);
        // cout << "+ " << ls[i].X << " " << dp[i] << endl;
        cvh.add(line(ls[i].X,dp[i]));
        res = max(res, dp[i]);
        // cout << dp[i] << endl;
        // if (i == 2){
        //     break;
        // }
    }
    // for (int i = 0; i < n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << res << endl;
    return 0;
}