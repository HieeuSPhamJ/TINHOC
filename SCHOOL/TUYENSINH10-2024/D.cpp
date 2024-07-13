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

const int maxX = 1442249;

int sum(int n){
    return n * (n + 1) * (2 * n + 1) / 6;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("bai4.inp", "r")) {
        freopen("bai4.inp", "r", stdin);
        freopen("bai4.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int left = 1;
        int right = maxX;
        int res = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (sum(mid) <= x){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout << res << " ";
    }

    return 0;
}