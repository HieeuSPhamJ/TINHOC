#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 100010 + 10;
const int mod = 8 * 1e18;
int n, k;
int a[maxN];
int dp[maxN][10];
int seg[55][4 * maxN];

void init(){
    set <int> mySet;
    map <int, int> myMap;
    for (int i = 1; i <= n; i++){
        mySet.insert(a[i]);
    }

    int count = 1;

    for (auto i: mySet){
        myMap[i] = count;
        count++;
    }

    for (int i = 1; i <= n; i++){
        a[i] = myMap[a[i]];
    }
}

void update(int d, int index, int left, int right, int id, int value){
    // cout << id << " " << left << " " << right << endl;
    if (id < left or right < id){
        return;
    }
    if (left == right){
        (seg[d][index] += value) %= mod;
        return;
    }
    int mid = (left + right) / 2;
    update(d, index * 2, left, mid, id, value);
    update(d, index * 2 + 1, mid + 1, right, id, value);
    (seg[d][index] = (seg[d][index * 2] + seg[d][index * 2 + 1])) %= mod;
}

int get(int d, int index, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[d][index] % mod;
    }

    int mid = (left + right) / 2;

    int t1 = get(d, index * 2, left, mid, _left, _right);
    int t2 = get(d, index * 2 + 1, mid + 1, right, _left, _right);

    return (t1 + t2) % mod;
}   

void print(){
    for (int d = 1; d <= k; d++){
        cout << "DEM " << d << ": ";
        for (int i = 1; i <= n; i++){
            cout << get(d,1,1,n,i,i) << " ";
        }
        cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    init();
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        dp[a[i]][1]++;
        update(1,1,1,n,a[i],1);
        for (int j = 2; j <= min(k,i); j++){
            // cout << i << " " << a[i] << " " << j << endl;
            int temp = 0;
            temp = get(j - 1, 1, 1, n, 1, a[i] - 1);
            (dp[a[i]][j] += temp) %= mod;
            // cout << temp << " " << dp[a[i]][j] << endl;
            update(j,1,1,n,a[i],temp);
        }
    }

    // print();

    int ans = 0;

    for (int i = 1; i <= n; i++){
        (ans += dp[i][k]) %= mod;
    }

    cout << ans;

    return 0;
}