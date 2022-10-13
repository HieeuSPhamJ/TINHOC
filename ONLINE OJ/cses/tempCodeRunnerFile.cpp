#include<bits/stdc++.h>

#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'

using namespace std;

const int maxN = 10010;

vector <ii> listNode;
vector <ii> listConvexHull;


double calArea(ii a, ii b){
    return (1.0 * (a.se + b.se) * (a.fi - b.fi)) / 2;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <ii> inp;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        listConvexHull.push_back({x,y});
    }


    double ans = 0;

    int len = listConvexHull.size();
    for (int i = 0; i < len; i++){
        ii a = listConvexHull[i % len];
        ii b = listConvexHull[(i + 1) % len];
        // cout << a.fi << " " << a.se << " | " << b.fi << " " << b.se << endl;
        double area = calArea(a, b);
        // cout << area << endl;
        ans += area;

    }
    cout << ans << endl;
    return 0;
}
