#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 1e18;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}
int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(1,1,n,i,i - a[i] + 1);
        // cout << i - a[i] << " ";
        a[i] += a[i - 1];
    }
    // cout << endl;

    int csum = k * (k + 1) / 2;
    int ans = 1e18;

    for (int i = k; i <= n; i++){
        if (get(1,1,n,i - k + 1, i) + k > i){
            // cout << i << " " << csum - (a[i] - a[i - k + 1 - 1]) << endl;
            ans = min(ans, csum - (a[i] - a[i - k + 1 - 1]));
        }
    }

    if (ans == inf){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;


    return 0;
}