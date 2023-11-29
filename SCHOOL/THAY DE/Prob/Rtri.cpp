#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int countX[maxN];
int countY[maxN];

signed main(){
    freopen("Rtri.INP", "r", stdin);
    freopen("Rtri.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    vector <ii> lists;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({a,b});
        countX[a]++;
        countY[b]++;
    }



    for (auto i: lists){
        int a = i.fi;
        int b = i.se;
        ans += (countX[a] - 1) * (countY[b] - 1);
        // cout << a << ":" << (countX[a] - 1) << " " << b << ":" << (countY[b] - 1) << endl;
    }
    cout << ans;
    return 0;
}