#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int pre[maxN];
int a[maxN];
int seg[maxN * 4];

int sum(int l, int r){
    return pre[r] - pre[l - 1];
}

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] += val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1,t2);
}

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
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = k; i <= n; i++){
        int temp = sum(i - k + 1, i);
        update(1,1,n,i,temp);
    }
    // for (int i = 1; i <= n; i++){
    //     cout << get(1,1,n,i,i) << " ";
    // }
    // cout << endl;
    int ans = 1e18;
    for (int i = k; i <= n; i++){
        // cout << "Index: " << i << endl;
        int p1 = sum(i - k + 1, i);

        int p21 = 0;
        if (1 <= i - k){
            p21 = get(1,1, n, 1, i - k);
        }

        int p22 = 0;
        if (i + k <= n){
            p22 = get(1,1, n, i + k, n);
        }

        // cout << 1 << "-" << i - k << endl;
        // cout << i - k + 1 << "-" << i << endl;
        // cout << i + k << "-" << n << endl;

        int p2 = max(p21, p22);
        // cout << i << endl;
        // cout << p1 << " " << p21 << " " << p22 << endl;
        // if (p1 >= p2){
            // cout << "#" << endl;
            ans = min(ans, p2);
        // }
        // cout << endl;
    }

    cout << ans;

    return 0;
}