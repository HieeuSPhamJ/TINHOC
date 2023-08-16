#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[1000];

void cal(int n){
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        ls.push_back(i);
    }
    int res = 0;
    while(next_permutation(all(ls))){
        for (int i = 1; i <= n; i++){
            a[i] = ls[i - 1];
        }
        set <int> s;
        for (int i = 1; i <= n; i++){
            s.insert(__gcd(a[i], a[i % n + 1]));
        }
        res = max(res,(int)s.size());
    }
    ls.clear();
    for (int i = 1; i <= n; i++){
        ls.push_back(i);
    }
    int cnt = 0;
    while(next_permutation(all(ls))){
        for (int i = 1; i <= n; i++){
            a[i] = ls[i - 1];
        }
        set <int> s;
        for (int i = 1; i <= n; i++){
            s.insert(__gcd(a[i], a[i % n + 1]));
        }
        if (s.size() == res){
            for (int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            cnt++;
        }
    }
    cout << res << ": " << cnt << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // for (int i = 1; i <= 7; i++){
    //     cout << "With: " << i << endl;
    //     cal(i);
    // }
    cal(8);
    return 0;
}