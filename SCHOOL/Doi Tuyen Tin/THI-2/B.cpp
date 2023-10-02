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

vector <ii> ls;

int a[maxN];
int goc[maxN];

void nenso(){
    set <int> s;
    for (auto i: ls){
        s.insert(i.fi);
        s.insert(i.se);
    }
    map <int,int> cv;
    int cnt = 1;
    for (auto i: s){
        cv[i] = cnt;
        goc[cnt] = i;
        cnt++;
    }
    for (auto &i: ls){
        i.fi = cv[i.fi];
        i.se = cv[i.se];
    }
}

int op[maxN];
int cl[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        ls.push_back({l,r});
    }
    nenso();
    
    for (auto i: ls){
        op[i.fi]++;
        cl[i.se]++;
        n = max({n,i.fi, i.se});
    }
    int ma = 0;
    for (int i = 1, cur = 0; i <= n; i++){
        cur += op[i - 1];
        cur -= cl[i];
        a[i] = max(cur + op[i], cur + cl[i]);
        ma = max(ma, a[i]);
        // cout << a[i] << " ";
    }
    // cout << endl;

    cout << ma << endl;
    for (int i = 1; i <= n; i++){
        if (a[i] == ma){
            cout << goc[i] << " ";
            int res = i;
            for (int j = i; j <= n; j++){
                if (a[j] != ma){
                    break;
                }
                res = j;
            }
            cout << goc[res] << endl;
            break;
        }
    }
    return 0;
}