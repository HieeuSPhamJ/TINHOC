#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 510;

int n, m;
vector <int> adj[maxN];
int ty[maxN];
int s[maxN];
int g[maxN];
vector <int> ls;
int p[maxN];
vector <int> pathto[maxN];
int vis[1 << 10][maxN];
int check[1 << 10][maxN];
int po[1 << 10];

void Try(int mask, int power){
    priority_queue <ii, vector <ii>, greater <ii>> q;
    q.push({0,1});
    vis[mask][1] = 1;
    while(q.size() and q.top().fi <= power){
        ii t = q.top();
        // if (mask == (1 << m) - 1){
        //     cout << "With: " << t.se << endl;
        // }
        q.pop();
        power += g[t.se];
        vis[mask][t.se] = 1;
        for (auto i: adj[t.se]){
            if (vis[mask][i] or (ty[i] == 2 and check[mask][i] == 0)){
                // if (mask == (1 << m) - 1){
                //     cout << i << ": " << vis[mask][i] << " " << ty[i] << " " << check[mask][i] << endl;
                // }
                continue;
            }
            if (check[mask][i]){
                q.push({0,i});
            }
            else{
               q.push({s[i],i});
            }
        }
        // cout << endl;
    }
    po[mask] = max(po[mask], power);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 2; i <= n; i++){
        cin >> p[i] >> ty[i] >> s[i] >> g[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
        if (ty[i] == 2){
            ls.push_back(i);
        }
    }
    
    m = ls.size();

    for (int i = 0; i < m; i++){
        int t = ls[i];
        while(t != 1){
            t = p[t];
            pathto[i].push_back(t);
        }
        reverse(all(pathto[i]));
        // cout << i << ": ";
        // for (auto x: pathto[i]){
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    memset(po,-1,sizeof(po));
    Try(0, 1);
    // // cout << po[0] << endl;
    for (int mask = 0; mask < (1 << m); mask++){
        // cout << "With " << bitset<10>(mask) << ": " << po[mask] << endl;
        for (int j = 0; j < m; j++){
            if ((mask & (1 << j)) == 0){
                int pmask = mask | (1 << j);
                for (int i = 1; i <= n; i++){
                    check[pmask][i] |= vis[mask][i];
                    vis[pmask][i] = 0;
                }

                int spo = po[mask];
                for (auto i: pathto[j]){
                    // cout << i << endl;
                    if (spo >= s[i]){
                        check[pmask][i] = 1;
                        spo += g[i];
                    }
                    else{
                        goto bru;
                    }
                }
                check[pmask][ls[j]] = 1;

                if (spo >= 1e9){
                    cout << "Yes" << endl;
                    return 0;
                }
                spo *= g[ls[j]];
                
                // cout << spo << endl;
                // if (pmask == (1 << m) - 1){
                //     cout << bitset<10>(pmask) << ": " << spo << endl;
                //     for (auto i: ls){
                //         cout << i << " " << check[pmask][i] << endl;
                //     }

                // }
                Try(pmask, spo);
                // cout << po[pmask] << endl;
            }
            bru:;
        }
    }

    // cout << *max_element(s + 1, s + 1 + n) << " " << *max_element(po + 1, po + 1 + (1 << m)) << endl;
    // for (auto i: ls){
    //     check[(1 << m) - 1][i] = 1;
    //     // cout << check[(1 << m) - 1][i] << endl;
    // }
    // Try((1 << m) - 1,254809800);
    for (int i = 1; i <= n; i++){
        if (vis[(1 << m) - 1][i] == 0){
            // cout << i << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}

/*
254809800 
227372456
*/