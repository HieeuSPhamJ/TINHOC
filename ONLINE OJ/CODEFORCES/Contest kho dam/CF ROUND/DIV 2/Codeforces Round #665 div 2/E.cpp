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

const int maxN = 1e6 + 10;
const int mama = 1e6;

int seg[maxN * 4];
int a[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        a[i] += val;
        seg[i] = bool(a[i]);
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
    update(1, 1, mama + 1, i + 1, v);
}

int get(int l, int r){
    return get(1, 1, mama + 1, l + 1, r + 1);
}

bool cmp(pair<ii,int> a, pair<ii,int> b){
    return a.se < b.se;
}

void print(){
    for (int i = 0; i <= mama; i++){
        cout << get(i,i) << " ";
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <pair <ii,int>> ls;
    for (int i = 1; i <= n; i++){
        int y, l, r;
        cin >> y >> l >> r;
        ls.push_back({{l,r},y});
    }


    vector <pair<ii,int>> lsx;

    for (int i = 1; i <= m; i++){
        int x, l, r;
        cin >> x >> l >> r;
        lsx.push_back({{l,r},x});
    }

    ls.push_back({{0,mama},0});
    ls.push_back({{0,mama},mama});
    lsx.push_back({{0,mama},0});
    lsx.push_back({{0,mama},mama});
    
    sort(rall(ls));
    sort(all(lsx), cmp);
    set <ii> s;
    set <ii> sto;
    int res = 0;
    for (auto i: lsx){
        int l = i.fi.fi;
        int r = i.fi.se;
        int x = i.se;
        // cout << "With: " << x << " [" << l << ";" << r << "]" << endl;

        while(sto.size() and (*sto.begin()).fi < x){
            int y = (*sto.begin()).se;
            // cout << "remove: " << y << endl;
            update(y,-1);
            sto.erase(sto.begin());
        }

        // print();
        
        // cout << "RES: " << max(0ll, get(l, r) - 1) << endl;
        res += max(0ll, get(l, r) - 1);

        while(ls.size() and ls.back().fi.fi <= x){
            s.insert({ls.back().fi.se,ls.back().se});         
            ls.pop_back();
        }

        // cout << "temp s: " << endl;
        // for (auto i: s){
        //     cout << i.fi << " " << i.se << endl;
        // }

        if (l == 0){
            while (s.size() and (*s.begin()).se <= r){
                // cout << "add: " << (*s.begin()).se << endl;
                update((*s.begin()).se, 1);
                sto.insert(*s.begin());
                s.erase(*s.begin());
                
            }
        }
        else{
            while (s.size() and (*s.rbegin()).se >= l){
                // cout << "add: " << (*s.rbegin()).se << endl;
                update((*s.rbegin()).se, 1);
                sto.insert(*s.rbegin());
                s.erase(*s.rbegin());
            }
        }
    }

    cout << res << endl;

    return 0;
}