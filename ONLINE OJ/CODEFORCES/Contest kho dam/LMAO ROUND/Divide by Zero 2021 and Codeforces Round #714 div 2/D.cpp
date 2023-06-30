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

int root[maxN];
int a[maxN];

int get(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = get(root[n]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, p;
        cin >> n >> p;
        vector <ii> ls;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            root[i] = i;
            ls.push_back({a[i], i});
        }
        sort(all(ls));
        int com = n;
        int res = 0;
        
        for (auto cur: ls){
            if (cur.fi >= p){
                break;
            }
            // cout << "With: " << cur.se << endl;
            for (int i = cur.se - 1; i >= 1; i--){
                if (a[i] >= cur.fi and __gcd(a[i], cur.fi) == cur.fi){
                    int u = get(cur.se);
                    int v = get(i);
                    if (u == v){
                        break;
                    }
                    // cout << cur.se << " " << i << " " << u << " " << v << endl;
                    res += cur.fi;
                    root[u] = v;
                    com--;
                }
                else{
                    break;
                }
            }

            for (int i = cur.se + 1; i <= n; i++){
                if (a[i] >= cur.fi and __gcd(a[i], cur.fi) == cur.fi){
                    int u = get(cur.se);
                    int v = get(i);
                    if (u == v){
                        break;
                    }
                    // cout << cur.se << " " << i << " " << u << " " << v << endl;
                    res += cur.fi;
                    root[u] = v;
                    com--;
                }
                else{
                    break;
                }
            }
        }

        cout << res + (com - 1) * p << endl;
    }
    return 0;
}