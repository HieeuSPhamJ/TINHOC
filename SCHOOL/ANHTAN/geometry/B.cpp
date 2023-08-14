#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
// #define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <double> ls;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back(sqrt(a * a + b * b));
    }
    sort(all(ls));
    int cnt = 0;
    for (auto i: ls){
        cnt++;
        if (cnt >= k){
            cout << fixed << " " << setprecision(6) << i << endl;
            break;
        }
    }
    return 0;
}