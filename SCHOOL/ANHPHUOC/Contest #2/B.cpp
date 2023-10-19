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

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2){
        cout << -1 << endl;
        return 0;
    }
    sum /= 2;
    // cout << sum << endl;
    vector <int> ls[2];

    for (int i = 1; i <= n; i++){
        ls[(i + 1) % 2].push_back(i);
    }
    int s0 = 0;
    int s1 = 0;
    for (auto i: ls[0]){
        s0 += i;
    }
    for (auto i: ls[1]){
        s1 += i;
    }
    int i = 1;
    while(s0 > s1){
        s0--;
        s1++;
        swap(ls[0][i], ls[1][i - 1]);
    }
    set <int> s[2];
    
    for (int t = 0; t <= 1; t++){
        for (auto i: ls[t]){
            s[t].insert(i);
        }
    }

    int v1 = *s[1].begin();
    
    while(1){
        int v0 = *s[0].upper_bound(v1);
        
    }

    for (int t = 0; t <= 1; t++){
        for (auto i: s[t]){
            cout << i << " ";
        }
    }
    return 0;
}