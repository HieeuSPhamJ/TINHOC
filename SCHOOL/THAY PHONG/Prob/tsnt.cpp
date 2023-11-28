#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

bool notprime[maxN];
int nxt[maxN];

void init(){
    notprime[0] = notprime[1] = 1;
    for (int i = 0; i < maxN; i++){
        nxt[i] = 1;
    }
    for (int i = 2; i * i < maxN; i++){
        if (notprime[i] == 0){
            for (int j = i * i; j < maxN; j += i){
                notprime[j] = 1;
                nxt[j] = i;
            }
        }
    } 
}

int cal(int n){
    if (n == 0){
        cout << 0 << endl;
        exit(0);
    }
    int cnt = 0;
    while(nxt[n] != 1){
        if (n % nxt[n] == 0){
            // cout << n << " " << nxt[n] << endl;
            cnt++;
            n /= nxt[n];
        }
    }
    // cout << n << endl;
    cnt += (n != 1);
    return cnt;
}

signed main(){
    //freopen("input.INP", "r", stdin); 
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    int cnt = 0;
    int ma = 0;
    // cout << cal(16) << endl;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        x = cal(x);
        cnt += x;
        ma = max(ma, x);
    }
    cout << cnt - ma << endl;
    return 0;
}