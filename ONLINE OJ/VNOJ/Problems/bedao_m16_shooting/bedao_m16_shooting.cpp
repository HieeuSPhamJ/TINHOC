#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
vector <int> closeAt[maxN], openAt[maxN];
// int closeAt[maxN], openAt[maxN];
int at[maxN];
int seg[maxN * 4];
int lazy[maxN * 4];

void setlazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[i] = 0;
}

void update(int i, int l, int r, int L, int R, int val){
    // cout << i << " " << l << " " << r << endl;
    if (r < L or R < l){
        return;
    }
    if (L <= l and r <= R){
        lazy[i] += val;
        seg[i] += val;
        return;
    }
    setlazy(i);
    int mid = (l + r) / 2;
    update(2 * i, l, mid, L, R, val);
    update(2 * i + 1, mid + 1, r, L, R, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int l, int r, int L, int R){
    if (r < L or R < l){
        return 0;
    }
    if (L <= l and r <= R){
        return seg[i];
    }
    setlazy(i);
    int mid = (l + r) / 2;
    int t1 = get(2 * i, l, mid, L, R);
    int t2 = get(2 * i + 1, mid + 1, r, L, R);
    return max(t1,t2);
}

void update(int l, int r, int v){
    if (l < 1){
        l = 1;
    }
    if (l > r){
        return;
    }
    update(1,1,n,l,r,v);
}

int get(int l, int r){
    if (l < 1){
        l = 1;
    }
    if (l > r){
        return 0;
    }
    return get(1,1,n,l,r);
}


vector <ii> lists;

void nenso(){
    unordered_map <int,int> conv;
    set <int> s;
    for (auto i: lists){
        s.insert(i.fi);
        s.insert(i.se);
    }
    int cnt = 1;
    for (auto i: s){
        conv[i] = cnt;
        cnt++;
    }
    for (auto &i: lists){
        i.fi = conv[i.fi];
        i.se = conv[i.se];
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
        int a, b;
        cin >> a >> b;
        lists.push_back({a,b});
    }

    nenso();
    
    for (auto i: lists){
        at[i.fi]++;
        at[i.se + 1]--;
        cout << i.fi << " " << i.se << endl;
        closeAt[i.se].push_back(i.fi);
        openAt[i.fi].push_back(i.se);
        // openAt[a]++;
        // closeAt[b]++;
    }
    n = maxN;
    for (int i = 1, t = 0; i <= n; i++){
        t += at[i];
        at[i] = t;
        update(i,i,at[i]);
    }
    int res = 0;
    for (int i = 1; i <= 6; i++){
        while(!openAt[i].empty()){
            int t = openAt[i].back();
            openAt[i].pop_back();
            update(1,i - 1,1);
        }
        while(!closeAt[i - 1].empty()){
            int t = closeAt[i - 1].back();
            closeAt[i - 1].pop_back();
            update(1,t - 1,-1);
        }

        
        int dp = get(1,i - 1);
        // cout << i << dp << endl;
        res = max(dp,res);
    }

    cout << res << endl;


    return 0;
}