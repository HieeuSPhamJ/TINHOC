#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int const maxN = 2 * 1e6 + 10;

int prefix[maxN];
int f[maxN];
bool notPrime[maxN];

void init(){
    for (int i = 2; i * i <= maxN; i++){
        if (notPrime[i]){
            continue;
        }
        for (int j = 2; i * j <= maxN; j++){
            notPrime[i * j] = 1;
        }
    }
    vector <int> listPrime;
    for (int i = 2; i < maxN; i++){
        if (!notPrime[i]){
            listPrime.push_back(i);
        }
    }
    for (auto i: listPrime){
        for (int j = 1; i * j <= maxN; j++){
            f[i * j]++;
        }
    }
    for (int i = 1; i < maxN; i++){
        prefix[i] = prefix[i - 1] + f[i];
    }
}

int cal(int left, int right){
    return prefix[right] - prefix[left - 1];
}

signed main(){
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i <= m; i++){
            ans += cal(i + 1, i + n);
        }
        cout << ans << endl;
    }
    return 0;
}   