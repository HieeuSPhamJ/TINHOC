#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 200010;

int a[maxN];

int cal(int len, int x){
    len = len - x;
    // cout << len << endl;
    int t = (len) / (x + 1) + (len % (x + 1) != 0);
    return t;
}

signed main(){
    // freopen("GROUPS.INP", "r", stdin);
    // freopen("GROUPS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    vector <int> ls;
    for (int i = 2; i <= n; i++){
        if (a[i] - a[i - 1] <= x){
            continue;
        }

        // cout << i - 1 << " " << i << " " << t << endl;
        ls.push_back(cal(a[i] - a[i - 1] - 1, x));
    }   

    sort(rall(ls));

    while(ls.size() and ls.back() <= k){
        k -= ls.back();
        ls.pop_back();
    }

    cout << ls.size() + 1 << endl;


    // cout << cal(5,2);

    return 0;
}

/*
1 2 3 4 5  6  7  8
1 1 5 8 12 13 20 22
2 3 2
4 5 2
6 7 3


*/