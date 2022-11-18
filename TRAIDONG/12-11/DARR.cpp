#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int suffix[maxN];
int a[maxN];
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    priority_queue <int> q;

    for (int i = n; i >= 1; i--){
        suffix[i] = suffix[i + 1] + a[i];
        if (i != 1)
        q.push(suffix[i]);
    }

    k--;
    int ans = suffix[1];

    while(k--){
        ans += q.top();
        q.pop();
    }
    
    cout << ans;
    return 0;
}