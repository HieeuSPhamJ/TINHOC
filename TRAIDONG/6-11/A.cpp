#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
int a[maxN];
int LEFT[maxN];
int RIGHT[maxN];
int seg[4 * maxN];

void reset(){
    for (int i = 0; i < 4 * maxN; i++){
        seg[i] = 0;
    }
}
void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        (seg[i] += val) %= mod;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    (seg[i] = (seg[2 * i] + seg[2 * i + 1])) %= mod;
}
int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return ((t1 + t2)) % mod;
}
void nenso(){
    set <int> suckmyset;
    for (int i = 1; i <= n; i++){
        suckmyset.insert(a[i]);
    }
    map <int,int> suckmymap;
    int cnt = 1;
    for (auto i: suckmyset){
        suckmymap[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = suckmymap[a[i]];
    }
}


signed main(){
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    reset();
    for (int i = 1; i <= n; i++){
        update(1,1,n,a[i],1);
        LEFT[i] = get(1,1,n,1,a[i] - 1);
        update(1,1,n,a[i],LEFT[i]);
        // cout << LEFT[i] << " ";
    }
    // cout << endl;
    reset();
    for (int i = n; i >= 1; i--){
        update(1,1,n,a[i],1);
        RIGHT[i] = get(1,1,n,1,a[i] - 1);
        update(1,1,n,a[i],RIGHT[i]);
        // cout << RIGHT[i] << " ";
    }
    // cout << endl;

    int ans = 1;

    for (int i = 1; i <= n; i++){
        (ans += ((LEFT[i] + 1) * (RIGHT[i] + 1)) % mod) %= mod;
    }

    cout << ans;

    return 0;
}