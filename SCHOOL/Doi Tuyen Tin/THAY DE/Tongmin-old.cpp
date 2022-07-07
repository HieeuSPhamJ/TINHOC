#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int inf = 1e9;
const int maxN = 1e6 + 10;

int a[maxN];
int seg[maxN * 4];

void build(int i, int l, int r) {
    if (l == r) {
        seg[i] = a[l] - a[l - 1];
        return;
    }

    int mid = (l + r) / 2; // 
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

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

    seg[i] = min(seg[2 * i + 1], seg[2 * i]);
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return inf;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        return min(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}



signed main(){
    // freopen("Tongmin.INP", "r", stdin);
    // freopen("Tongmin.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort (a + 1, a + 1 + n);
    a[0] = inf;
    // for (int i = 1; i <= n; i++){
    //     // cout << a[i] << ' ';
    //     update(1,1,n,i,abs(a[i] - a[i - 1]));
    // }
    build(1,1,n);
    // cout << endl;

    int ans = inf;
    
    k = n - k;

    for (int i = 1; i + k - 1 <= n; i++){
        // cout << i << " " << i + k -1 << endl;
        // cout << abs(a[i] - a[i + k - 1]) << endl;
        // cout << get(1,1,n, i + 1, i + k -1) << endl;
        ans = min(ans, abs(a[i] - a[i + k - 1]) + get(1,1,n, i + 1, i + k -1) );
    }
    cout << ans;

    return 0;
}