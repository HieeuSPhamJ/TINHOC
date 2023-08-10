#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a, b;

ii cal(int n, int m){
    int l = 1;
    int r = n;
    int res = 1e18;
    int bonus = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if (mid / m + mid >= n){
            r = mid - 1;
            res = mid * a;
            bonus = mid / m + mid - n;
        }
        else{
            l = mid + 1;
        }
    }
    return {res,bonus};
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> a >> b;
        cin >> n >> m;
        if (a <= b){
            cout << cal(n,m).fi << endl;
        }
        else{
            int ans = n * b;;
            if (m * a < (m + 1) * b){
                int bonus = n / (m + 1);
                ans = bonus * m * a;
                bonus = n % (m + 1);
                ans += min(a * bonus, b * bonus);
            }
            cout << ans << endl;
        }
    }
    return 0;
}

/*
8 + 80
*/