#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

vector <int> lst[3];

int check(int t, int n){
    int l = 0;
    int r = (int)lst[t].size() - 1;
    int res = 1e18;
    while(l <= r){
        int mid = (l + r) / 2;
        int c = lst[t][mid];
        if (c > n){
            r = mid - 1;
        }
        else{
            res = c;
            l = mid + 1;
        }
    }

    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int n = a + b;
    vector <int> ls;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            ls.push_back(i);
            if (n / i != i){
                ls.push_back(n / i);
            }
        }
    }
    
    for (int i = 1; i * i <= a; i++){
        if (a % i == 0){
            lst[1].push_back(i);
            if (a / i != i){
                lst[1].push_back(a / i);
            }
        }
    }
    for (int i = 1; i * i <= b; i++){
        if (b % i == 0){
            lst[2].push_back(i);
            if (b / i != i){
                lst[2].push_back(b / i);
            }
        }
    }

    sort(all(lst[1]));
    sort(all(lst[2]));

    int res = 1e18;

    for (auto i: ls){
        int j = n / i;
        if (a / check(1,i) <= j or b / check(2,i) <= j){
            res = min(res, 2 * (i + j));
        }
    }
    cout << res << endl;
    return 0;
}