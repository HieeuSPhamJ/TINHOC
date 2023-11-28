#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int root[maxN];
int val[maxN];

int checkRoot(int v){
    if (root[v]==v){
        return v;
    }
    else return (root[v]=checkRoot(root[v]));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= n + 3; i++){
        root[i] = i;
        val[i] = -1;
    }

    stack <int> q;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    stack <int> ans;

    int tans = 0;

    while(!q.empty()){
        int x = q.top();
        q.pop();
        val[x] = a[x];
        // for (int i = 1; i <= n; i++){
        //     cout << val[i] << " ";
        // }
        // cout << endl;

        int A = x;
        int u = checkRoot(A);
        for (int i = -1; i <= 1; i++){
            if (i == 0){
                continue;
            }
            int B = x + i;
            if (val[B] == -1){
                continue;
            }
            int v = checkRoot(B);
            if (u == v){
                continue;
            }
            // cout << A << ":" << u << " " << B << ":" << v << endl;
            root[v] = u;
            val[u] += val[v];
        }
        tans = max(tans, val[u]);
        ans.push(tans);
    }

    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}