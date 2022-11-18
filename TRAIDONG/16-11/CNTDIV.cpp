#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int n;
int Next[maxN];
int notPrime[maxN];

void init(){
    notPrime[0] = notPrime[1] = 1;
    for (int i = 1; i < maxN; i++){
        Next[i] = i;
    }
    for (int i = 2; i * i < maxN; i++){
        if (!notPrime[i]){
            for (int j = 2; i * j <= maxN; j++){
                notPrime[i * j] = 1;
                Next[i * j] = i;
            }
        }
    }    
}

void sub1(){
    int t = n * (n + 1) * (n + 2);
    int tt = t * t;
    int cnt = 0;
    for (int i = 1; i <= t; i++){
        cnt += (tt % i == 0 and t % i != 0);
    }
    cout << cnt << " ";
}

void sub3(){
    unordered_map <int,int> cnt;
    set <int> lists;
    for (int x = n; x <= n + 2; x++){
        int now = x;
        while(now > 1){
            int uc = Next[now];
            while(now % uc == 0){
                cnt[uc]++;
                now /= uc;
            }
            // cout << uc << endl;
            lists.insert(uc);
        }
    }

    // for (auto i: lists){
    //     cout << i << ": " << cnt[i] << endl;
    // }
    int T = 1;
    int T2 = 1;
    for (auto i: lists){
        T *= (cnt[i] + 1);
        T2 *= (2 * cnt[i] + 1);
    }
    cout << (T2 - (T * 2 - 1)) / 2 << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    init();
    int test;
    cin >> test;
    int TEST = test;
    while(test--){
        cin >> n;
        // if (n <= 1000){
        //     sub1();
        //     continue;
        // }
        sub3();
    }
    return 0;
}
