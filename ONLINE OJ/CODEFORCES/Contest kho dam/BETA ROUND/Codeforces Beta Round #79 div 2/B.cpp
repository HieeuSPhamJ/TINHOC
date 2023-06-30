#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;
const int mod = 1000000007;

int n, m;
vector <ii> ls;
int seg[maxN * 4];

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
    seg[i] = (seg[2 * i] + seg[2 * i + 1]) % mod;
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
    return (t1 + t2) % mod;
}

void nenso(){
    set <int> s;
    for (auto i: ls){
        s.insert(i.fi);
        s.insert(i.se);
    }

    map <int,int> cnv;
    int cnt = 0;
    for (auto i: s){
        cnt++;
        cnv[i] = cnt;
    }

    for (auto &i: ls){
        i.fi = cnv[i.fi];
        i.se = cnv[i.se];
    }
    if (cnv[m] == 0 or cnv[0] == 0){
        cout << 0;
        exit(0);
    }
    m = cnv[m];
}

bool cmp(ii a, ii b){
    return a.se < b.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    bool ok = 0;    
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
        if (b == m){
            ok = 1;
        }
    }

    nenso();
    sort(all(ls), cmp);

    update(1,1,m,1,1);

    for (auto i: ls){
        // cout << i.fi << ' ' << i.se << endl;
        int l = i.fi;
        int r = i.se;
        int pre = get(1,1,m,l,r - 1);
        // cout << l << ' ' << r << " " << pre << endl;
        update(1,1,m,r,pre);
    }

    // cout << m << endl;

    cout << get(1,1,m,m,m) << endl;


    return 0;
}