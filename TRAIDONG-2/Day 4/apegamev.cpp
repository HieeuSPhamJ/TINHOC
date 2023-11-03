#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
int a[maxN];
int res[maxN];

int seg[2][maxN * 4];

void update(int t, int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[t][i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(t,2 * i, left, mid, index, val);
    update(t,2 * i + 1, mid + 1, right, index, val);
    seg[t][i] = (seg[t][2 * i] + seg[t][2 * i + 1]);
}

int get(int t,int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[t][i];
    }

    int mid = (left + right) / 2;

    int t1 = get(t,2 * i, left, mid, _left, _right);
    int t2 = get(t,2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
}

void update(int t, int i, int v){
    update(t,1,1,n,i,v);
}

int get(int t, int l, int r){
    return get(t,1,1,n,l,r);
}

map<int,vector<int>> cv;

void nenso(){
    multiset <int> s;
    for (int i = 2; i <= n; i++){
        s.insert(a[i]);
    }
    int cnt = 1;
    for (auto i: s){
        cv[i].push_back(cnt);
        // cout << i << " " << cnt << endl;
        cnt++;
    }
}

int getl(int id, int l, int r, int v){
    if (seg[0][id] == v){
        return l;
    }
    if (l == r){
        return l;
    }
    if (seg[0][id] < v){
        return getl(2 * id, l, r, v - seg[0][id]);
    }
    return getl(2 * id + 1, (l + r) / 2 + 1, r, v);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    int ok = 1;
    for (int i = 2; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1){
            ok = 0;
        }
    }
    for (int i = 2; i <= n; i++){
        cin >> a[i];
    }

    nenso();
    vector <pair<ii,int>> ls;
    for (int i = 1; i <= test; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({{x,y}, i});
    }
    if (ok == 0){
        cout << 2131 << endl;
        return 0;
    }
    sort(all(ls));
    int la = 2;
    for (auto i: ls){
        while(la <= i.fi.se){
            int t = cv[a[la]].back();
            // cout << t << " " << la << endl;
            cv[a[la]].pop_back();
            update(0,t,1);
            update(1,t,a[la]);
            la++;
        }

        // for (int i = 1; i <= n; i++){
        //     cout << get(0,i,i) << " ";
        // }
        // cout << endl;
        // int t = getl(1,1,n,i.fi.fi);
        int t = 1;
        int l = 1;
        int r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if (get(0,mid,n) >= i.fi.fi){
                l = mid + 1;
                t = mid;
            }
            else{
                r = mid - 1;
            }
        }
        res[i.se] = get(1,t,n);
    }
    
    for (int i = 1; i <= test; i++){
        cout << res[i] << endl;
    }

    // update(0,3,1);
    // cout << getl(1,1,n,2);
    return 0;
}