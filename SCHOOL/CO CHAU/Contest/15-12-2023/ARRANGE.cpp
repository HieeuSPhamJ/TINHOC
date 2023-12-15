#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n;
int a[maxN];

namespace sub1{
    void solve(int sum){
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] > sum){
                res += a[i] - sum;
                a[i+1] += (a[i] - sum);
            }
            else if (a[i] < sum){
                res += sum - a[i];
                a[i+1] -= (sum - a[i]);
            }
        }
        cout << res << endl;
    }
}

namespace sub2{
    void solve(int lo, int hi){
        int res = 0;

        
    }
}

/*
5 4 3 2 1
3 3 6 5
2
3
3

1
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("ARRANGE.inp", "r")) {
        freopen("ARRANGE.inp", "r", stdin);
        freopen("ARRANGE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int lo = sum / n;
    int hi = lo + (sum % n != 0);

    if (hi == lo){
        sub1::solve(lo);
    }
    else{
        sub2::solve(lo, hi);
    }

    return 0;
}