#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int pre[4][maxN];

signed main(){
    freopen("TRIANGLE.INP", "r", stdin);
    freopen("TRIANGLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        char c;
        int x;
        cin >> c >> x;
        if (c == 'r'){
            ls.push_back({1,x});
            pre[1][x]++;
        }
        else if (c == 'g'){
            ls.push_back({2,x});
            pre[2][x]++;
        }
        else if (c == 'b'){
            ls.push_back({3,x});
            pre[3][x]++;
        }
    }

    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 2e5; j++){
            pre[i][j] += pre[i][j - 1];
        }
    }

    int res = 0;
    
    for (int i = 0; i < ls.size(); i++){
        for (int j = i + 1; j < ls.size(); j++){
            if (ls[i].fi == ls[j].fi){
                continue;
            }
            int sum = ls[i].se + ls[j].se;
            int c = 6 - ls[i].fi - ls[j].fi;
            // for (auto k: ls){
            //     if (c == k.fi and k.se < sum and k.se + min(ls[i].se,ls[j].se) >= max(ls[i].se,ls[j].se)){
            //         cout << ls[i].se << " " << ls[j].se << " " << k.se << endl;
            //     }
            // }
            // cout << ls[i].se << " " << ls[j].se << " " << c << ": " << pre[c][sum - 1] << endl;
            res += pre[c][sum - 1] - pre[c][max(ls[i].se,ls[j].se) - min(ls[i].se,ls[j].se)];
        }
    }

    cout << res / 3;

    return 0;
}
/*
5 10
6 10
12

10 10 12
10 12 10
10 12 6
10 6 12
10 12 10
10 12 5
10 5 12
12 5 10
12 6 10
11
*/