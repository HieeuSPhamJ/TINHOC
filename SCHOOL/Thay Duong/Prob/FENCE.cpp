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

const int maxN = 5e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue <ii> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        q.push({a[i],i});  
    }
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    sort(rall(ls));
    while(ls.size()){
        a[q.top().se] = ls.back();
        ls.pop_back();
        q.pop();
    }

    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    int res = 0;
    for (int i = 2; i <= n; i++){
        res += abs(a[i] - a[i - 1]);
    }
    cout << res << endl;
    return 0;
}