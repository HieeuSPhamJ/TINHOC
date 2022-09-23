#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 3 * 1e5 + 10;


vector <iii> f;

bool checkss(int i, int j){
    int a1 = f[i].fi.fi;
    int b1 = f[i].fi.se;
    int GCD = __gcd(a1,b1);
    a1 /= GCD;
    b1 /= GCD;
    int a2 = f[j].fi.fi;
    int b2 = f[j].fi.se;
    GCD = __gcd(a2,b2);
    a2 /= GCD;
    b2 /= GCD;
    return (a1 == a2 and b1 == b2);
}

bool check(int i, int j, int k){
    bool ssab = !checkss(i,j);
    bool ssbc = !checkss(i,k);
    bool ssac = !checkss(j,k);
//    cout << "Check: " << ssab << " " << ssbc << " " << ssac << endl;
    return (ssab and ssbc and ssac);
}

signed main(){
    freopen("FTANGLE.INP", "r", stdin);
    freopen("FTANGLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set <iii> mySet;
    for (int i = 1; i <= n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        mySet.insert({{a,b},c});
    }

    for (auto i: mySet){
        f.push_back(i);
    }

    int ans = 0;

    n = f.size();

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (checkss(i,j)){
                continue;
            }
            for (int k = j + 1; k < n; k++){
                if (check(i,j,k)){
//                        cout << "approved";
//                        cout << endl;
                    ans++;
                }
//                    cout << " " << f[i].fi.fi << " " << f[i].fi.se << " " << f[i].se << endl;
//                    cout << " " << f[j].fi.fi << " " << f[j].fi.se << " " << f[j].se << endl;
//                    cout << " " << f[k].fi.fi << " " << f[k].fi.se << " " << f[k].se << endl;
//                    cout << endl;
            }
        }
    }

    cout << ans;

    return 0;
}

/*
5
-5 3 0
-5 -3 -30
0 1 0
3 7 35
1 -2 -1

6
0 8 0
-5 3 0
-5 2 25
0 9 -3
0 1 -2
-4 -5 29

*/
