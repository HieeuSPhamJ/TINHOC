#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n;
int vis[1 << 20 + 2];

void bfs(int s){
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while(q.size()){
        int t = q.front();
        int dt = vis[t];
        q.pop();
        if (dt >= n * 2){
            continue;
        }
        for (int i = 1; i < n; i++){
            int nu = t;
            nu = nu xor (1 << i);
            nu = nu xor (1 << (i - 1));
            if (vis[nu] == 0){
                vis[nu] = dt + 1;
                q.push(nu);
            }
        }
        for (int i = 2; i < n; i++){
            int nu = t;
            nu = nu xor (1 << i);
            nu = nu xor (1 << (i - 1));
            nu = nu xor (1 << (i - 2));
            if (vis[nu] == 0){
                vis[nu] = dt + 1;
                q.push(nu);
            }
        }
    }
}

/*
1011
0100
1111
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    int st = 0;
    for (int i = 0; i < n; i++){
        st += (1 << i) * (s[i] - 'A');
    }

    bfs(st);

    cout << min(vis[0], vis[(1 << n) - 1]) - 1;
    return 0;
}