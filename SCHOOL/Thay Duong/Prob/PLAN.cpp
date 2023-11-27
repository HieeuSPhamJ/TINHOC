#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int check[maxN];
int a[maxN];

signed main(){
    freopen("PLAN.INP", "r", stdin);
    freopen("PLAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        while(m--){
            int l, r;
            cin >> l >> r;
            check[l]++;
            check[r + 1]--;
        }
    }

    for (int i = 1, temp = 0; i < maxN; i++){
        temp += check[i];
        a[i] = temp;
    }

    for (int i = 1; i < maxN; i++){
        if (a[i] == 0){
            cout << i;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}