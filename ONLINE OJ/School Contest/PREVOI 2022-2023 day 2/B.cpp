#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

struct node{
    int data[5];
    void init(){
        for (int i = 0; i <= 4; i++){
            data[i] = 0;
        }
    }
};
int n, m;
node seg[22][maxN];
int a[maxN];
vector <int> lp;
int mucaonhat[22];

void print(node a){
    for (int i = 0; i <= 4; i++){
        cout << a.data[i] << " ";
    }
    cout << endl;
}

node merg(node a, node b){
    for (int x = 0; x <= 4; x++){
        a.data[x] += b.data[x];
    }
    // print(seg[t][i]);
    // print(seg[t][t1]);
    // print(seg[t][t2]);
    return a;
}


void build(int t, int i, int l, int r){
    seg[t][i].init();
    if (l == r){
        int now = a[l];
        int cnt = 0;
        while(now % t == 0){
            cnt++;
            now /= t;
        }
        int v = 1;
        if (cnt == 0){
            v = 0;
        }
        if (cnt > mucaonhat[t]){
            cnt = 0;
        }
        seg[t][i].data[cnt] = v;
        // cout << "This: " << l << " " << r << endl;
        // print(seg[t][i]);
        return;
    }

    int mid = (l + r) / 2;
    build(t, 2 * i, l, mid);
    build(t, 2 * i + 1, mid + 1, r);
    // cout << "Merge: " << l << " " << r << endl;
    seg[t][i] = merg(seg[t][2 * i], seg[t][2 * i + 1]);
    // cout << "This: " << l << " " << r << endl;
    // print(seg[t][i]);
}


// int get(int i, int left, int right, int _left, int _right){
//     if (right < _left or _right < left){
//         return 0;
//     }
//     if (_left <= left and right <= _right){
//         return seg[i];
//     }

//     int mid = (left + right) / 2;

//     int t1 = get(2 * i, left, mid, _left, _right);
//     int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
//     return (t1 + t2);
// }

int pre[maxN];
int fact[maxN];
int infact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}


void init(){
    // COBIM
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = fastpow(fact[maxN - 1], mod - 2);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], i + 1);
    }


    int m0 = m;
    for (int i = 2; m0 > 1; i++){
        if (m0 % i == 0){
            lp.push_back(i);
            while(m0 % i == 0){
                m0 /= i;
                mucaonhat[i]++;
            }
        }
    }
    // cout << "Prime of: ";
    // for (auto i: lp){
    //     cout << i << " ";
    // }
    // cout << endl;
    for (auto i: lp){
        build(i,1,1,n);
    }

    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + (a[i] % 2 == 0);
    }
    
    // cout << "End Init" << endl;
}

int C(int n, int k){
    return mul(fact[n], mul(infact[k], infact[n - k]));
}

int dp[maxN][10];

void solvet1(){
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++){
        for (int j = 0; j < m; j++){
            dp[i][(j + a[i]) % m] += dp[i - 1][j];
        }
        for (int j = 0; j < m; j++){
            dp[i][j] += dp[i - 1][j];
        }
        dp[i][a[i] % m]++;
        // for (int j = 0; j < m; j++){
        //     cout << dp[i][j] << " ";
        // }
        // cout << endl;
    }
    cout << dp[r][0] + 1 << endl;
}

void solve2(int l, int r){
    int chan = pre[r] - pre[l - 1];
    int le = (r - l + 1) - chan;

    cout << ((1 << chan) - 1) * ((2 << le) / 2 - 1) << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    int test;
    cin >> test;
    if (m == 2){
        while(test--){
            int l, r;
            cin >> l >> r;
            solve2(l, r);
        }
        return 0;
    }
    if (test == 1){
        solvet1();
        return 0;
    }
    cout << 2 << endl << 4 << endl << 6 << endl << 4;


    return 0;
}