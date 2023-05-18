#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;
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

int n;
vector <ii> ls;
set <int> s;
int a[maxN];
int moc[maxN];
map <int,int> conv;

void nenso(){
    set <int> temp;
    for (int i = 1; i <= n; i++){
        temp.insert(a[i]);
    }
    int cnt = 1;
    conv.clear();
    for (auto i: temp){
        conv[i] = cnt;
        cnt++;
    }
    for (auto &i: ls){
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
        s.insert(a);
        s.insert(b);
        ls.push_back({a,b});
    }
    n = 0;
    for (auto i: s){
        n++;
        a[n] = i;
        moc[n] = i;
    }
    nenso();

    for (auto i: ls){
        swap(a[i.fi],a[i.se]);
    }
    ls.clear();
    for (int i = 1; i <= n; i++){
        if (moc[i - 1] + 1 != moc[i]){
            ls.push_back({moc[i] - 1, moc[i] - moc[i - 1] - 1});
        }
        ls.push_back({a[i],1});
    }
    n = 0;
    for (auto i: ls){
        n++;
        a[n] = i.fi;
        moc[n] = i.se;
    }

    nenso();

    int res = 0;

    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
        // cout << a[i] << " " << moc[i] << endl;
        res += get(1, 1, n, a[i], n) * moc[i];
        update(1, 1, n, a[i], moc[i]);
    }
    
    cout << res << endl;

    return 0;
}

/*
1 5 3 4 2 6
1 2 3 4
2 4   1
*/