#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
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
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -1e18;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1, t2);
}

int a[maxN];
int dp[maxN];
int pre[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        update(1,1,n,i,-1e18);
    }
    dp[1] = a[1];

    multiset <ii> s;
    update(1,1,n,1,dp[0] - pre[1]);
    s.insert({1 + a[1], 1});
    int res = 0;
    for (int i = 2; i <= n; i++){
        while(s.size() and (*s.begin()).fi < i){
            int t = (*s.begin()).se;
            s.erase(s.begin());
            update(1,1,n,t,-1e18);
        }
        if (s.empty()){
            break;
        }
        cout << "With: " << i << endl;
        for (auto i: s){
            cout << i.se << endl;
        }
        dp[i] = get(1,1,n,1,n) + pre[i];
        update(1,1,n,i,dp[i - 1] - pre[i]);
        s.insert({i + a[i], i});
        res = max(res,dp[i]);
    }

    cout <<res << endl;


    return 0;
}