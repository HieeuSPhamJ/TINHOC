#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 1e4 + 10;

int n;
int a[100001];
int g[MAX_N << 1];
bool check[MAX_N << 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    g[1] = 1;
    check[1] = true;
    for (int i = 2; i < MAX_N; i++) {
        for (int j = 1; j < MAX_N; j++) {
            check[j] = false;
        }
        for (int j = 1; j < i; j++) {
            check[g[j]] = true;
        }
        for (int j = 1; j <= (i >> 1); j++) {
            check[g[j] ^ g[i - j]] = true;
        }
        for (int j = 0; j < (MAX_N << 1); j++) {
            if (!check[j]) {
                g[i] = j;
                break;
            }
        }
    }

    int sumXor = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumXor ^= g[a[i]];
    }

    cout << (sumXor ? "Alice" : "Bob");

    return 0;
}
