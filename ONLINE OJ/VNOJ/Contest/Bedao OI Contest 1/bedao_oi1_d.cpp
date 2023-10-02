#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct node{
    int bit[2];
    node(){
        bit[0] = bit[1] = -1;
    }
};

vector <node> trie;

int insert(int x){
    int p = 0;
    for (int i = 4; i >= 0; i--){
        int c = ((x & (1 << i)) != 0);
        // cout << i << " " << c << ": " << endl;
        if (trie[p].bit[c] == -1){
            trie[p].bit[c] = trie.size();
            trie.push_back(node());
            // cout << "cre " << trie[p].bit[c] << endl;
        }
        p = trie[p].bit[c];
    }
    // cout << endl;
}

const int maxN = 1e5 + 10;

int xa[maxN];
int mi[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    trie.push_back(node());
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        insert(x);
    }
    for (int i = 1; i <= n; i++){
        
    }
    return 0;
}