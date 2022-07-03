#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define endl "\n"
// #define int long long
using namespace std;

const int maxN = 5 * 1e5 + 10;
int a[maxN];
int rmq[30][maxN];
int lg[maxN];

unsigned int gcd(unsigned int u, unsigned int v) {
  int shift;
  if (u == 0)
    return v;
  if (v == 0)
    return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    unsigned m;
    v >>= __builtin_ctz(v);
    v -= u;
    m = (int)v >> 31;
    u += v & m;
    v = (v + m) ^ m;
  } while (v != 0);
  return u << shift;
}

void init(){
    for (int i = 0; i <= 18; i++){
        lg[1 << i] = i;
    }
    for (int i = 1; i < maxN; i++){
        lg[i] = max(lg[i], lg[i - 1]);
        // cout << lg[i] << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmq[0][i] = a[i];
    }

    for (int j = 1; j <= 19; j++){
        for (int i = 1; i <= n - (1 << j) + 1; i++){
            rmq[j][i] = gcd(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }

    for (int i = 1; i <= test; i++){
        int l, r;
        cin >> l >> r;
        int d = lg[r - l + 1];
        cout << gcd(rmq[d][l], rmq[d][r - (1 << d) + 1]) << endl;
    }



    return 0;
}