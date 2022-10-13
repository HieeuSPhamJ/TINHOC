#include<bits/stdc++.h>

#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'

using namespace std;

const int maxN = 10010;

vector <ii> listConvexHull;


int calArea(ii a, ii b){
    return a.fi * b.se - b.fi * a.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        listConvexHull.push_back({x,y});
    }


    int ans = 0;

    int len = listConvexHull.size();
    for (int i = 0; i < len; i++){
        ii a = listConvexHull[i % len];
        ii b = listConvexHull[(i + 1) % len];
        int area = calArea(a, b);
        // cout << area << endl;
        ans += area;

    }
    cout << abs(ans) << endl;
    return 0;
}
