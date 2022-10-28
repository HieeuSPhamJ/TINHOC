#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int visited[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int t = 1;
    int cnt = 0;
    while(a[t] != -1 and t != 2){
        int x = a[t];
        a[t] = -1;
        t = x;
        // cout << t << " ";
        cnt++;
    }
    if (t == 2){
        cout << cnt;
    }
    else{
        cout << -1;
    }
    return 0;
}