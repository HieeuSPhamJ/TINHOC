#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;
const int maxB = 31;
int n, k;
int a[maxN];
int dp[30 * maxN];

struct node{
    int child[2];
    node(){
        child[0] = child[1] = -1;
    }
};

struct trie{
    vector <node> ls;

    trie(){
        ls.push_back(node());
    }

    void insert(int n){
        // cout << "i: " << n << endl;
        // cout << bitset<maxB>(n) << endl;
        int p = 0;
        for (int i = maxB - 1; i >= 0; i--){
            int c = ((n & (1 << i)) != 0);
            dp[p]++;
            if (ls[p].child[c] == -1){
                ls[p].child[c] = ls.size();
                ls.push_back(node());
            }
            // cout << p << " " << ls[p].child[c] << endl;
            p = ls[p].child[c];
        }
        dp[p]++;
    }

    int cal(int n){
        int p = 0;
        int res = 0;
        for (int i = maxB - 1; i >= 0; i--){
            int c = ((n & (1 << i)) != 0);
            int kc = ((k & (1 << i)) != 0);
            // cout << "w: " << i << ":" << endl;
            if ((c xor 0) > kc){
                if (ls[p].child[0] != -1){
                    // cout << "add " << 0 << endl;
                    res += dp[ls[p].child[0]];
                }
            }
            if ((c xor 1) > kc){
                if (ls[p].child[1] != -1){
                    // cout << "add " << 1 << endl;
                    res += dp[ls[p].child[1]];
                }
            }
            if ((c xor 0) == kc){
                if (ls[p].child[0] != -1){
                    // cout << "move " << 0 << endl;
                    p = ls[p].child[0];
                    continue;
                }
            }
            if ((c xor 1) == kc){
                if (ls[p].child[1] != -1){
                    // cout << "move " << 1 << endl;
                    p = ls[p].child[1];
                    continue;
                }
            }
            // cout << "break" << endl;
            return res;
        }
        res += dp[p];

        return res;
    }

} Trie;

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
    cin >> n >> k;
    Trie.insert(0);
    long long res = 0;
    // Trie.insert(2);
    // Trie.insert(6);
    // cout << Trie.cal(5) << endl;
    for (int i = 1, prexor = 0; i <= n; i++){
        int x;
        cin >> x;
        prexor = prexor xor x;
        int t = Trie.cal(prexor);
        res += t;
        // cout << i << " " << prexor << " " << t << endl;
        Trie.insert(prexor);
    }
    cout << res << endl;
    return 0;
}
/*
2 2
1 2
3 3
2 3
1 3
2 4
1 4
5 5
2 5
1 5
6 6
5 6
4 6
3 6
1 6
7 7
4 7
2 7
1 7
19
*/