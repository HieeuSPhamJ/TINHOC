#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int a[maxN];
int resa[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> n >> k;
    priority_queue <ii,vector<ii>,greater<ii>> q;
    for (int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        a[i] = y - x;
        q.push({x,i});
    }
    int res = 0;
    for (int i = 1; i <= k; i++){
        ii t = q.top();
        q.pop();
        res += t.fi;
        resa[abs(t.se)]++;
        if (t.se <= 0){
            continue;
        }
        q.push({a[t.se],-t.se});
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++){
        cout << resa[i];
    }
    return 0;
}