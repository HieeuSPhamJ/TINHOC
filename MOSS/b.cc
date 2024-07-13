#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;


int a[maxN];

vector <ii> ls;

void add(int x, int y){
    ls.push_back({x,y});
    a[y] = a[x];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ls.clear();
        for (int i = 1; i < n; i++){
            int target = 0;
            for (int j = i + 1; j <= n; j++){
                if (a[j] == i){
                    target = j;
                    break;
                }
            }
            if (!target){
                continue;
            }
            ls.push_back({target, n + 1});

            for (int j = target; i < j; j--){
                // a[j] = a[j - 1];
                // ls.push_back({j - 1, j});
                add(j - 1, j);
            }

            ls.push_back({n + 1, i});
        }

        cout << ls.size() << endl;
        for (auto i: ls){
            cout << i.fi << " " << i.se << endl;
        }
    }
    return 0;
}

/*
2 3 1 x
2 x 1 3
2 1 x 3
2 1 3 x
*/
