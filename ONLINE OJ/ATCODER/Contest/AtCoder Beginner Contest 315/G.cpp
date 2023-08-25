#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;
    map <int,vector <ii>> cnt;

    for (int i = 1; i <= n; i++){
        int ai = a * i;
        cnt[ai % b].push_back({ai + b, ai + n * b});
    }
    for (auto i: cnt){
        sort(all(i.se));
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int cj = x - c * i;
        if (cj <= 0){
            continue;
        }
        auto &vec = cnt[(x - (c * i) % b + b) % b];
        if (vec.empty()){
            continue;
        }     
        // cout << "With: " << cj << " " << (x - ((c * i) % b) + b) % b << " " << i << ": " << endl;
        // for (auto x: vec){
        //     cout << x.fi << " " << x.se << endl;
        // } 
        // cout << endl;
        int l = 0;   
        int r = (int)vec.size() - 1;
        int R = -1;
        int L = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (vec[mid].fi <= cj){
                l = mid + 1;
                R = mid;
            }
            else{
                r = mid - 1;
            }
        }
        l = 0;
        r = (int)vec.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (cj <= vec[mid].se){
                r = mid - 1;
                L = mid;
            }
            else{
                l = mid + 1;
            }
        }
        // cout << L << " " << R << endl;
        if (L > R or L == -1 or R == -1){
            continue;
        }
        // cout << "RES: " << (R - L + 1) << endl;
        res += (R - L + 1);
    }
    cout << res << endl;
    return 0;
}

/*
4 4 1

*/