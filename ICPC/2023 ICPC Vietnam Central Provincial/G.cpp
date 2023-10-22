#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e4 + 10;

int grundy[2 * maxN];
int check[2 * maxN];

void init(){
    grundy[1] = 1;
    check[1] = 1;
    for (int i = 2; i < maxN; i++){
        for (int i = 1; i < maxN; i++){
            check[i] = 0;
        }
        for (int j = 1; j < i; j++){
            check[grundy[j]] = 1;
        }
        for (int j = 1; j <= i / 2; j++){
            check[grundy[j] xor grundy[i - j]] = 1;
        }
        for (int j = 0; j < 2 * maxN; j++){
            if (check[j] == 0){
                grundy[i] = j;
                break;
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();

    int n;
    cin >> n;
    int res = 0;
    while(n--){
        int x;
        cin >> x;
        res = res xor grundy[x];
        // cout << x << " " << grundy[x] << endl;
    }
    if (res){
        cout << "Alice";
    }
    else{
        cout << "Bob";
    }
    return 0;
}