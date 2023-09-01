#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e18;

int n;
int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[i] = -1;
    if (val != -1){
        lazy[2 * i] = val;
        lazy[2 * i + 1] = val;
        seg[2 * i] = val;
        seg[2 * i + 1] = val;
    }
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = val;
        lazy[i] = val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1,t2);
}

void update(int l, int r, int v){
    l++;
    r++;
    update(1,1,n + 1,l,r,v);
}

int get(int l, int r){
    l++;
    r++;
    return get(1,1,n + 1,l,r);
}

void print(int t){
    for (int i = 0; i <= t; i++){
        cout << get(t,t);
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    n = 10;
    update(0,10,1);
    update(3,3,0);
    // cout << get(1,3) << endl;
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        n = s.length();
        for (int i  = 1; i <= 4 * n; i++){
            seg[i] = 0;
            lazy[i] = -1;
        }
        int ok = 1;
        update(0,0,1);
        for (int i = 0, t = 0; i < n; i++){
            char c = s[i];
            if (c == '+'){
                t++;
                update(t,t,0);
            }
            else if (c == '-'){
                update(t,t,0);
                t--;
            }
            else if (c == '1'){
                // print(t);
                if (get(0,t) >= 0){
                    update(0,t,1);
                    continue;
                }
                ok = 0;
                break;
            }
            else if (c == '0'){
                // print(t);
                if (get(0,t) == 1 or t <= 1){
                    ok = 0;
                    break;
                }
                update(t,t,-1);
            }
        }
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}