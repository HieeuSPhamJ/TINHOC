#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
int a[30];
int ans = 0;
int full = 67108863;

void adudarkqua(int i, int sum){
    if (i == n){
        if (sum == (full)){
            ans++;
        }
        return;
    }
    adudarkqua(i + 1, sum | a[i + 1]);
    adudarkqua(i + 1, sum);
}

signed main(){
    freopen("VFONT.INP", "r", stdin);
    freopen("VFONT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int x = 0;
        for (int i = 0; i < s.length(); i++){
            x = (x | (1 << (s[i] - 'a')));
        }
        a[i] = x;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    adudarkqua(0,0);
    cout << ans;

    return 0;
}

