#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5 * 1e3 + 10;
const int inf = 1e18;

int n;
int a[maxN];
int dp[maxN];
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
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}

void update(int i, int v){
    update(1,1,n,i,v);
}

int get(int l, int r){
    return get(1,1,n,l,r);
}


void nenso(){
    set <int> temp;
    for (int i = 1; i <= n; i++){
        temp.insert(a[i]);
    }
    int cnt = 1;
    map <int,int> conv;
    for (auto i: temp){
        conv[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
        // cout << a[i] << " ";
    }
    // cout << endl;
}

void print(){
    cout << "======" << endl;
    for (int i = 1; i <= n; i++){
        int x = get(i,i);
        if (x == inf){
            cout << "x ";
            continue;
        }
        cout << x << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        nenso();
        int ans = 0;

        for (int i = 1; i <= n; i++){ 
            for (int j = 1; j < 4 * maxN; j++){
                seg[j] = inf;
            }
            for (int j = 0; j <= n; j++){
                dp[j] = 0;
            }

            set <int> s;
            update(a[i],i);
            s.insert(a[i]);

            // cout << "With: " << i << endl;
            int last = inf;
            for (int j = i + 1; j <= n; j++){
                // print();
                int res = dp[j - 1];
                if (s.lower_bound(a[j]) != s.end()){
                    // cout << "-change-" << endl;
                    int t = get(a[j],n);
                    t = min(t,last);
                    // cout << a[j] << endl;
                    // cout << t <<  " " << (j - 1) - t + 1 << " " << dp[t - 1] << endl;
                    res = (j - 1) - t + 1;
                    res += dp[t - 1];
                    last = min(last,t);
                }

                s.insert(a[j]);
                update(a[j], j);
                dp[j] = res;

                ans += res;
                // cout << "[" << i <<"," << j << "] = " << res << endl;
            }     
        }

        cout << ans << endl;
    }
    return 0;
}