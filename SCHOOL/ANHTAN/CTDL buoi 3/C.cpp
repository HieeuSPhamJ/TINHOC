#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 1e9 + 7;

int boss[maxN];

int findBoss(int n){
    if (n == boss[n]){
        return n;
    }
    return boss[n] = findBoss(boss[n]);
}


long long powFast(long long n){
    long long ans = 1;
    for (int i = 1; i <= n; i++){
        ans = (ans * 2) % mod;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, test;
    cin >> n >> test;

    for (int i = 1; i <= n; i++){
        boss[i] = i;
    }
    int com = n;

    while (test--){
        int a, b, l;
        cin >> a >> b >> l;
        for (int i = 0; i < l; i++){
            // cout << a + i << ' ' << b + i << endl;
            int u = findBoss(a + i);
            int v = findBoss(b + i);
            if (u != v){
                boss[u] = v;
                com--;
            }

        }
    }

    cout << powFast(com);

    return 0;
}