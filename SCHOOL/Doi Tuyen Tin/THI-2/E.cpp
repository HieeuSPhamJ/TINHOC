#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, m;
vector <pair<int,ii>> ls;
int rt[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

bool check(int k){
    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }
    int com = n;
    for (auto e: ls){
        if (e.fi < k){
            continue;
        }
        int a = e.se.fi;
        int b = e.se.se;
        a = find(a);
        b = find(b);
        if (a == b){    
            continue;
        }
        rt[a] = b;
        com--;
    }
    return (com == 1);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        ls.push_back({w,{a,b}});
    }
    int l = 0;
    int r = 1e18;
    int res = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}