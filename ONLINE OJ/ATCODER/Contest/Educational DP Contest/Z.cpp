#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int inf = 1e18;

struct line{
    int a, b;
    line(){
        a = 0;
        b = inf;
    }
    line(int _a,int _b){
        a = _a;
        b = _b;
    }
    int operator ()(int x){
        return a * x + b;
    }
};

void print(line x, char en = endl){
    cout << x.a << " " << x.b << en;
}
 

const int maxN = 1e6 + 10;

int dp[maxN];
int h[maxN];
unordered_map <int,line> seg;
// line seg[maxN * 4];

void update(int id, int l, int r, line cur){
    if (r - l == 1){
        if (seg[id](l) > cur(l)){
            seg[id] = cur;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (seg[id].a > cur.a){
        swap(seg[id], cur);
    }
    if (cur(mid) < seg[id](mid)){
        update(2 * id + 1, mid, r, seg[id]);
        seg[id] = cur;
    }
    else{
        update(2 * id, l, mid, cur);
    }
}

void update(line x){
    // cout << "add: " << x.a << " " << x.b << endl;
    // cout << x.a << "x + " << x.b << endl;
    update(1, 1, 1e6, x);
}

int get(int id, int l, int r, int x){
    int mid = (l + r) / 2;
    int res = seg[id](x);
    if (r - l == 1){
        return res;
    }
    if (x < mid){
        return min(res, get(2 * id, l, mid, x));
    }
    return min(res, get(2 * id + 1, mid, r, x));
}

int get(int x){
    int t = get(1, 1, 1e6 + 1, x);
    // cout << x << ": " << t << endl;
    return t;
}


signed main(){
    // freopen("./1_28", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }

    dp[1] = 0;
    update(line(-2 * h[1],dp[1] + h[1] * h[1]));
    // update(line(-4,20));
    // update(line(-4,20));
    // cout << get(5) << endl;
    for (int i = 2; i <= n; i++){
        dp[i] = get(h[i]) + k + h[i] * h[i];
        update(line(-2 * h[i],dp[i] + h[i] * h[i]));
    }
    // cout << seg.size() << endl;
    cout << dp[n];

    return 0;
}

/*
-1000000 * 1000000 + 250000000000 
*/