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

int n;
int a[maxN];
int seg[maxN * 4];


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] += val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = (seg[2 * i] + seg[2 * i + 1]);
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
    return (t1 + t2);
}

void update(int i, int v){
    update(1,1,n,i,v);
}

int get(int l, int r){
    if (r < l){
        return 0;
    }
    return get(1,1,n,l,r);
}

int cal(vector <int> &ls){
    int res = 0;
    for (int i = 1; i <= 4 * n; i++){
        seg[i] = 0;
    }
    for (auto i: ls){
        res += get(i + 1, n);
        update(i,1);
    }
    return res;
}

void nenso(){
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(a[i]);
    }
    int cnt = 1;
    map <int,int> cnv;
    for (auto i: s){
        cnv[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = cnv[a[i]];
        // cout << a[i] << " ";
    }
    // cout << endl;
}


signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin); 
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            vector <int> ls;
            for (int k = 1; k <= i; k++){
                ls.push_back(a[k]);
            }
            for (int k = j; k <= n; k++){
                ls.push_back(a[k]);
            }
            if (cal(ls) <= k){
                // cout << i << " " << j << endl;
                 res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}