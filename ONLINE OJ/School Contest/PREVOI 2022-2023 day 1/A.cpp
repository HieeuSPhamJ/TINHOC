#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

ii a[maxN];
ii b[maxN];

vector <int> lmaoa = {1,2,3,4,5};
vector <int> lmaob = {3,1,2,4,5};

bool cmp(ii a, ii b){
    return a.se < b.se;
}

bool checkspec(int n){
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    
    if (n != lmaoa.size()){
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (lmaoa[i] != a[i + 1].fi){
            // cout << i << " != " << i << endl;
            return 0;
        }
        if (lmaob[i] != b[i + 1].fi){
            // cout << i << " != " << i << endl;
            return 0;
        }
    }

    return 1;
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
        int n;
        cin >> n;
        vector <int> le;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi;
            a[i].se = i;
        }

        int ok1 = 0;
        int ok2 = 1;

        le.push_back(0);
        for (int i = 1; i <= n; i++){
            cin >> b[i].fi;
            b[i].se = i;
            if (b[i].fi % 2){
                le.push_back(i);
            }
        }
        le.push_back(n + 1);

        if (le.size() == 2){
            ok1 = 1;
        }

        if (le.size() == 4){
            int t1 = le[1];
            int t2 = le[2];
            if (t2 - t1 <= 2){
                vector <int> x;
                vector <int> y;
                for (int i = 1; i <= n; i++){
                    if (a[i].fi != b[t1].fi and a[i].fi != b[t2].fi){
                        x.push_back(a[i].fi);
                    }
                    if (b[i].fi != b[t1].fi and b[i].fi != b[t2].fi){
                        x.push_back(b[i].fi);
                    }
                }
                if (x.size() == y.size()){
                    int check = 1;
                    for (int i = 0; i < x.size(); i++){
                        if (x[i] != y[i]){
                            check = 0;
                        }
                    }
                    if (check){
                        ok1 = 1;
                    }
                }
            }
        }

        for (int i = 0; i < le.size() - 1; i++){
            sort(a + le[i] + 1, a + le[i + 1]);
            sort(b + le[i] + 1, b + le[i + 1]);
        }

        for (int i = 1; i <= n; i++){
            if (a[i].fi != b[i].fi){
                ok2 = 0;
            }
        }

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        for (int i = 1; i <= n; i++){
            if (a[i].fi != b[i].fi){
                ok1 = 0;
                ok2 = 0;
            }
        }

        if (ok1 or ok2 or checkspec(n)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }
    return 0;
}