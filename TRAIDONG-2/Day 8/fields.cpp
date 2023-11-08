#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, b;
int a[maxN];
int pre[maxN];

int cal(int l, int mid, int r){
    int mv = pre[mid] - pre[mid - 1];
    int ler = r - mid + 1;
    int lel = mid - l + 1;
    return (pre[r] - pre[mid - 1]) - mv * ler + mv * lel - (pre[mid] - pre[l - 1]);
}

int check(int L, int R){
    int l = L;
    int r = R;
    int res = 1e18; 
    // return cal(1,1,1);
    while(l <= r){
        int mid = (l + r) / 2;
        int t1 = cal(L, mid, R);
        res = min(res,t1);
        if (mid != R){
            int t2 = cal(L, mid + 1, R);
            res = min(res,t2);
            if(t1 < t2){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            r = mid - 1;
        }
    }
    return res;
} 

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("fields.inp", "r")) {
        freopen("fields.inp", "r", stdin);
        freopen("fields.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> n >> b >> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int l = i;
        int r = n;
        int tres = 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (check(i, mid) <= b){
                l = mid + 1;
                tres = mid - i + 1;
            }
            else{
                r = mid - 1;
            }
        }
        // cout << i << " " << tres << endl;
        res = max(res,tres);
    }
    // cout << check(3,5) << endl;
    cout << res << endl;

    return 0;
}