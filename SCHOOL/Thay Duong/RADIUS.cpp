#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int X[maxN];
int Y[maxN];

int calLen(double a, double b){
    int x = a * a + b * b;
    int s = sqrt(x);
    int sq = s;
    for (int i = max(0ll, s - 5); i <= s + 5; i++){
        if (i * i >= x){
            sq = i;
            break;
        }
    }
    return ceil(sq);
}

signed main(){
    freopen("RADIUS.INP", "r", stdin);
    freopen("RADIUS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;

        vector <ii> lists;

        for (int i = 1; i <= n; i++){
            cin >> X[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> Y[i];
        }

        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            lists.push_back({calLen(X[i], Y[i]), inp});
        }

        sort(lists.rbegin(), lists.rend());
        int r = 0;
        int sum = 0;
        // for (auto i: lists){
        //     cout << i.fi << " " << i.se << endl;
        // }
        while(!lists.empty() and (sum < m or r >= lists.back().fi)){
            sum += lists.back().se;
            r = lists.back().fi;
            lists.pop_back();
        }
        if (sum < m){
            cout << -1 << endl;
            continue;
        }
        cout << r << endl;
    }

    return 0;
}