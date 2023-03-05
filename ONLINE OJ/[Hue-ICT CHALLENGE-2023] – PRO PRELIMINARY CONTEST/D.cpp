#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct dtype{
    int data[5];
    int get(){
        return min({data[0], data[1], data[2], data[3]});
    }
};

dtype add(dtype a, dtype b){
    a.data[0] += b.data[0];
    a.data[1] += b.data[1];
    a.data[2] += b.data[2];
    a.data[3] += b.data[3];
    return a;
}

dtype subtr(dtype a, dtype b){
    a.data[0] -= b.data[0];
    a.data[1] -= b.data[1];
    a.data[2] -= b.data[2];
    a.data[3] -= b.data[3];
    return a;
}

const int maxN = 1e6 + 10;


int k;
dtype pre[maxN];


bool check(int l, int r){
    // cout << l << " " << r << endl;
    dtype t = subtr(pre[r], pre[l - 1]);
    if (t.get() >= k){
        return 1;
    }
    return 0;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cin >> k;

    int n = s.length();

    pre[0].data[0] = 0;
    pre[0].data[1] = 0;
    pre[0].data[2] = 0;
    pre[0].data[3] = 0;
    
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        if (s[i - 1] == 'H'){
            pre[i].data[0]++;
        }
        else if (s[i - 1] == 'U'){
            pre[i].data[1]++;
        }
        else if (s[i - 1] == 'C'){
            pre[i].data[2]++;
        }
        else {
            pre[i].data[3]++;
        }
    }
    // for (int j = 0; j < 4; j++){
    //     for (int i = 1; i <= n; i++){
    //         cout << pre[i].data[j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 1e18;
    for (int i = 1, j = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        while(check(j,i) and j <= i){
            // cout << j << endl;
            int len = i - j + 1;
            ans = min(ans, (len - k * 4));
            j++;
        }
        if (j > i){
            j = i;
        }
    }

    if (ans == 1e18){
        cout << -1;
        return 0;
    }

    cout << ans;

    return 0;
}