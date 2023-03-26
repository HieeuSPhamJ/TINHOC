#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int n, k;
int a[maxN];
double pre[maxN];
bool check(double lmao){
    // cout << "With: " << lmao << endl;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + 1.0 * a[i] - lmao;

        // cout << fixed << setprecision(4) << 1.0 * a[i] - lmao << " ";
    }
    // cout << endl;
    double sto = 1e18;
    for (int i = 1; i <= n; i++){
        if (i >= k){
            sto = min(sto, pre[i - k]);
            // cout << pre[i] - *s.begin() << endl;
            if (pre[i] - sto >= 0){
                return 1;
            }
        }
    }
    return 0;
}

signed main(){
    freopen("rate.INP", "r", stdin);
    freopen("rate.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    double left = 0;
    double right = 1e18;
    while(left <= right){
        double mid = (left + right) / 2;
        if (check(mid)){
            left = mid;
        }
        else{
            right = mid;
        }
        if (abs(right - left) <= 0.0000001){
            break;
        }
    }

    cout << fixed << setprecision(6) << left << endl;

    return 0;
}