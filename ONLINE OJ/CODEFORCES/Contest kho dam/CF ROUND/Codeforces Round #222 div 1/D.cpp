#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 4e5 + 10;
const int inf = 1e18;

int n;
int res = 0;
int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[i] = 0;
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] += val;
        lazy[i] += val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1,t2);
}

bool cmp(pair<ii,ii> a, pair <ii,ii> b){
    return a.fi.fi <= b.fi.fi;
}

bool cmpiii(pair<ii,int> a, pair <ii,int> b){
    return a.fi.fi <= b.fi.fi;
}

void nenso(vector <pair<ii,ii>> &ls){
    set <int> s;
    for (auto i: ls){
        s.insert(i.fi.fi);
        s.insert(i.fi.se);
        s.insert(i.se.fi);
    }
    int cnt = 0;
    map <int,int> cnv;
    for (auto i: s){
        cnt++;
        cnv[i] = cnt;
        n = cnt;
    }

    for (auto &i: ls){
        i.fi.fi = cnv[i.fi.fi];
        i.fi.se = cnv[i.fi.se];
        i.se.fi = cnv[i.se.fi];
    }
}

void print(vector <pair<ii,int>> &ls){
    set <ii> s;
    sort(all(ls), cmpiii);
    for (auto i: ls){
        while(s.size() and (*s.begin()).fi < i.fi.fi){
            s.erase(s.begin());
        }
        s.insert({i.fi.se,i.se});
        if (s.size() == res){
            for (auto i: s){
                cout << i.se << " ";
            }
            return;
        }
    }
}

signed main(){
    //freopen("teams.INP", "r", stdin);
    //freopen("teams.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector <pair<ii,ii>> ls;
    int debugloi = 0;
    for (int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> c >> b;
        ls.push_back({{a,b},{c,i}});
        if (a == 89340 and i == 1){
            debugloi = 1;
        }
    }
    nenso(ls);
    sort(all(ls));

    multiset <pair<ii,int>> s;
    
    
    for (auto i: ls){
        int l = i.fi.fi;
        int r = i.fi.se;
        int mid = i.se.fi;
        // cout << "With: " << l << " " << mid << " " << r << endl;
        while(s.size() and (*s.begin()).fi.fi < l){
            pair<ii,int> t = *s.begin();
            s.erase(s.begin());
            update(1,1,n,t.fi.fi,t.fi.se,-1);
            // cout << " del: " << t.fi << " " << t.se << endl;
        }
        update(1,1,n,mid,r,1);
        s.insert({{mid,r},i.se.se});
        // cout << " add: " << mid << " " << r << endl; 
        res = max(res,seg[1]);
        // cout << "=> " << get(1,1,n,1,n) << endl;
    }

    cout << res << endl;
    s.clear();
    for (int i = 1; i < 4 * maxN; i++){
        seg[i] = 0;
        lazy[i] = 0;
    }
    for (auto i: ls){
        int l = i.fi.fi;
        int r = i.fi.se;
        int mid = i.se.fi;
        // cout << "With: " << l << " " << mid << " " << r << endl;
        while(s.size() and (*s.begin()).fi.fi < l){
            pair<ii,int> t = *s.begin();
            s.erase(s.begin());
            update(1,1,n,t.fi.fi,t.fi.se,-1);
            // cout << " del: " << t.fi.fi << " " << t.fi.se << endl;
        }
        update(1,1,n,mid,r,1);
        s.insert({{mid,r},i.se.se});
        // cout << " add: " << mid << " " << r << endl; 
        if (res == seg[1]){
            break;
        }
    }

    vector <pair<ii,int>> ts;

    for (auto i: s){
        ts.push_back(i);
    }

    print(ts);
    return 0;
}