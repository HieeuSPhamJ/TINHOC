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

const int maxN = 1e5 + 10;

int rt[3][maxN];
int va[3][maxN];
int mk[3][maxN];
int mava[3];

int find(int t, int u){
    if (rt[t][u] == u){
        return u;
    }
    return rt[t][u] = find(t, rt[t][u]);
}

void Try(int t, int i){
    mk[t][i] = 1;
    if (mk[t][i + 1] == 1){
        int u = find(t,i + 1);
        int v = find(t,i);
        if (u != v){
            // cout << t <<": " << i << " " << i - 1 << endl;
            rt[t][u] = v;
            va[t][v] += va[t][u];
        }
    }
    if (mk[t][i - 1] == 1){
        int u = find(t,i - 1);
        int v = find(t,i);
        if (u != v){
            // cout << t <<": " << i << " " << i - 1 << endl;
            rt[t][u] = v;
            va[t][v] += va[t][u];
        }
    }
    mava[t] = max(mava[t], va[t][find(t,i)]);
}

signed main(){
    freopen("SHOPPING.INP", "r", stdin);
    freopen("SHOPPING.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> a, b;
    int MA = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a.push_back({x,i});
        rt[1][i] = i;
        va[1][i] = 1;
        MA = max(MA, x);
    }
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        b.push_back({x,i});
        rt[2][i] = i;
        va[2][i] = 1;
        MA = max(MA, x);
    }

    sort(all(a));
    sort(all(b));
    
    int res = 0;
    for (int ma = MA; ma >= 1; ma--){
        // cout << "With: " << ma << endl;
        while(a.size() and a.back().fi >= ma){
            int i = a.back().se;
            // cout << i << endl;
            a.pop_back();
            Try(1,i);
        }   
        while(b.size() and b.back().fi >= ma){
            int i = b.back().se;
            // cout << i << endl;
            b.pop_back();
            Try(2,i);
        }   
        res = max(res,mava[1] * mava[2] * ma);
    }

    cout << res << endl;

    return 0;
}