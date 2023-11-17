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

vector <double> ls;
vector <double> res;

bool check(double k){
    res.clear();
    double la = ls.front();
    res.push_back(la);
    for (auto i: ls){
        if (i <= la + 2 * k){
            continue;
        }
        else{
            la = i;
            res.push_back(i);
        }   
    }

    return res.size() <= 3;
}

signed main(){
    freopen("stations.INP", "r", stdin);
    freopen("stations.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        double x;
        cin >> x;
        ls.push_back(x);
    }

    sort(all(ls));

    double l = 0;
    double r = 1e9;
    double ans = -1;
    while(r - l >= 0.0000001){
        double mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
            ans = mid;
        }
        else{
            l = mid;
        }
    }
    // cout << check(0.1) << endl;
    cout << fixed << setprecision(6) << ans << endl;
    check(ans);
    for (auto i: res){
        cout << fixed << setprecision(6) << i + ans << " ";
    }
    while(res.size() < 3){
        cout << 1e9 << " ";
        res.push_back(1e9);
    }
    return 0;
}