#include"bits/stdc++.h"
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxV = 1e7 + 10;
const int maxN = 1e6 + 10;


int n, test;
int nxt[maxV];
int in[20];
int a[maxN];

void init(){
    for (int i = 2; i * i < maxV; i++){
        if (nxt[i] == 0){
            for (int j = i * i; j < maxV; j += i){
                nxt[j] = i;
            }
        }
    }
    for (int i = 1; i < maxV; i++){
        if (nxt[i] == 0){
            nxt[i] = 1;
        }
    }
}

bool cmp(pair<ii,int> a, pair<ii,int> b){
    int sa = a.fi.fi / sqrt(n);
    int sb = b.fi.fi / sqrt(n);
    if (sa == sb){
        return a.fi.se < b.fi.se;
    }
    return sa < sb;
}

int res[maxN];
int cnt[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin >> n >> test;
    map <set<int>,int> trash;
    set <int> tmp;
    tmp.insert(0);
    trash[tmp] = 0;
    for (int i = 1, count = 1; i <= n; i++){
        int x;
        cin >> x;
        // cout << x << ": ";
        set <int> s;
        if (x == 0){
            a[i] = 0;
            continue;
        }
        if (x < 0){
            x = -x;
            s.insert(-1);
        }
        while(nxt[x] > 1){
            if (s.find(nxt[x]) != s.end()){
                s.erase(s.find(nxt[x]));
            }
            else{
                s.insert(nxt[x]);
            }
            // cout << nxt[x] << " ";
            x /= nxt[x];
        }
        if (x != 1){
            if (s.find(x) != s.end()){
                s.erase(s.find(x));
            }
            else{
                s.insert(x);
            }
            // cout << x;
        }
        

        // cout << endl;
        
        // for (auto j: s){
        //     cout << j << " ";
        // }
        // cout << endl;
        if (trash[s]){
            a[i] = trash[s];
        }
        else{
            a[i] = count;
            trash[s] = count;
            count++;
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    vector <pair<ii,int>> ls;

    for (int i = 1; i <= test; i++){
        int l, r;
        cin >> l >> r;
        ls.push_back({{l,r},i});
    }

    sort(all(ls), cmp);
    int num = 0;
    int L = 1;
    int R = 1;
    num = 1;
    cnt[a[1]]++;

    for (auto i: ls){
        int l = i.fi.fi;
        int r = i.fi.se;
        while(L < l){
            if (cnt[a[L]] == 1){
                num--;
            }
            cnt[a[L]]--;
            L++;
        }
        while(l < L){
            L--;
            cnt[a[L]]++;
            if (cnt[a[L]] == 1){
                num++;
            }
        }
        while(R < r){
            R++;
            cnt[a[R]]++;
            if (cnt[a[R]] == 1){
                num++;
            }
        }
        while(r < R){
            if (cnt[a[R]] == 1){
                num--;
            }
            cnt[a[R]]--;
            R--;
        }
        res[i.se] = max(1, num);
        if (cnt[0]){
            res[i.se] = max(1, num - 1);
        }
    }

    for (int i = 1; i <= test; i++){
        cout << res[i] << endl;
    }

    return 0;
}