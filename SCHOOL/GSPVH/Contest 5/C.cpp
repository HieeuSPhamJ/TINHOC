/*
ADU thuật N*log*log mà sao tle được
ảo ma vl
như chơi đồ
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = (1 << 18) + 10;

int n, m, w;
ii a[maxN];
iii b[maxN];
int ans[maxN];

bool cmp(ii a, ii b){
    return a.fi > b.fi;
}

struct compare{
    bool operator()(iii a, iii b){
        return a.fi > b.fi;
    }
};

bool checkfast(int k){
    priority_queue <iii, vector <iii>, compare> q;
    queue <ii> Zero;
    int mon = w;
    for (int i = 1, j = n; i <= m; i++){
        ans[a[i].se] = -1;
        // cout << "With: " << a[i].fi << " " << a[i].se << endl;
        while(j >= 1 and a[i].fi <= b[j].fi){
            q.push({b[j].se.fi,{k,b[j].se.se}});
            // cout << " add: " << b[j].se.fi << " " << k << " " << b[j].se.se << endl;
            j--;
        }
        if (Zero.empty()){
            if (q.empty()){
                // cout << "het cong nhan" << endl;
                break;
            }
            iii t = q.top();
            q.pop();
            if (mon - t.fi < 0){
                // cout << "het tien" << endl;
                break;
            }   
            if (t.fi != 0){
                Zero.push({t.se.fi, t.se.se});
                mon -= t.fi;
            }
        }
        if (Zero.empty()){
            break;
        }
        ii t = Zero.front();
        Zero.pop();
        while(!Zero.empty() and t.fi == 0){
            t = Zero.front();
            Zero.pop();
        }
        if (t.fi == 0){
            break;
        }
        ans[a[i].se] = t.se;
        t.fi--;
        if (t.fi >= 1){
            Zero.push(t);
        }
    }
    for (int i = 1; i <= m; i++){
        if (ans[i] == -1){
            return 0;
        }
    }
    return 1;
}

bool checkslow(int k){
    priority_queue <iii, vector <iii>, compare> q; 
    int mon = w;
    for (int i = 1, j = n; i <= m; i++){
        ans[a[i].se] = -1;
        // cout << "With: " << a[i].fi << " " << a[i].se << endl;
        while(j >= 1 and a[i].fi <= b[j].fi){
            q.push({b[j].se.fi,{k,b[j].se.se}});
            // cout << " add: " << b[j].se.fi << " " << k << " " << b[j].se.se << endl;
            j--;
        }
        if (q.empty()){
            // cout << "het cong nhan" << endl;
            break;
        }
        auto t = q.top();
        q.pop();
        if (mon - t.fi < 0){
            // cout << "het tien" << endl;
            break;
        }   
        if (t.fi != 0){
            // cout << " buy: " << t.se.fi << endl;
        }
        // cout << " use: " << t.se.fi << " " << t.se.se << endl;
        mon -= t.fi;
        t.fi = 0;
        t.se.fi--;
        ans[a[i].se] = t.se.se;
        if (t.se.fi >= 1){
            q.push(t);
        }
    }
    for (int i = 1; i <= m; i++){
        if (ans[i] == -1){
            return 0;
        }
    }
    return 1;
}


signed main(){
    // freopen("cheating.INP", "r", stdin);
    // freopen("cheating.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test, TEST;
    cin >> TEST >> test;
    while(test--){
        cin >> n >> m >> w;
        for (int i = 1; i <= m; i++){
            cin >> a[i].fi;
            a[i].se = i;
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i].fi;
            b[i].se.se = i;
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i].se.fi;
        }
        sort(a + 1, a + 1 + m, cmp);
        sort(b + 1, b + 1 + n);
        int l = 1;
        int r = m;
        int res = -1;
        // cout << check(4) << endl;
        while(l <= r){
            int mid = (l + r) / 2;
            bool t;
            if (TEST == 1){
                t = checkslow(mid);
            }
            else{
                t = checkfast(mid);
            }
            if (t){
                r = mid - 1;
                res = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if (res == -1){
            cout << "NO" << endl;
            cout << endl;
        }
        else{
            cout << "YES" << endl;
            checkslow(res);
            for (int i = 1; i <= m; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}