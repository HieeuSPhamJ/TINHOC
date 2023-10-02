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

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    set <int> q;
    for (int i = 1; i <= n; i++){
        q.insert(i);
    }
    priority_queue <ii,vector<ii>,greater<ii>> tq;
    while(m--){
        int t, w, s;
        cin >> t >> w >> s;
        while(tq.size() and tq.top().fi <= t){
            q.insert(tq.top().se);
            tq.pop();
        }
        if (q.size()){
            auto it = q.begin();
            // cout << *it << endl;
            a[*it] += w;
            tq.push({t + s, *it});
            q.erase(it);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << a[i] << endl;
    }
    return 0;
}