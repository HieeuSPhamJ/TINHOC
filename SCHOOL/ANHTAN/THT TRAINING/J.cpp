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

int a[maxN];
int re[maxN];

void nenso(){
    set <int> temp;
    for (int i = 1; i <= n; i++){
        temp.insert(a[i]);
    }
    int cnt = 1;
    map <int,int> conv;
    for (auto i: temp){
        conv[i] = cnt;
        re[cnt] = i;
        cnt++;
    }

    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
    }
}

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

    nenso();

    return 0;
}