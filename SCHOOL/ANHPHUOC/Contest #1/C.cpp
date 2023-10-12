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

int seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i]+=val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
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
    return max(t1, t2);
}

int n;
int a[maxN];

int cal(){
    for (int i = 1; i <= 4 * n; i++){
        seg[i] = 0;
    }   
    for (int i = 1; i <= n; i++){
        int dp = get(1,1,n,1,a[i]);
        // cout << dp + 1 << " ";
        update(1,1,n,a[i],dp + 1);
    }
    // cout << endl;
    reverse(a + 1, a + 1 + n);
    // cout << get(1,1,n,1,n) << endl;
    return n - get(1,1,n,1,n);
}

void nenso(){
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(a[i]);
    }
    int cnt = 0;
    map <int,int> cv;
    for(auto i: s){
        cnt++;
        cv[i] = cnt;
    }
    for (int i = 1; i <= n; i++){
        a[i] = cv[a[i]];
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    cout << cal();
    return 0;
}