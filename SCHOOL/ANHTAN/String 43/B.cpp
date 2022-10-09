#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 400010;
const int mod = 1337377;

struct node{
    node *child[26];
    bool checkEnd = 0;
    node(){
        for (int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        checkEnd = 0;
    }    
};

node *root = new node();

void insert(string a){
    node *p = root;
    for (int i = (int)a.length() - 1; i >= 0; i--){
        if (p->child[a[i] - 'a'] == NULL){
            p->child[a[i] - 'a'] = new node();
        }
        p = p->child[a[i] - 'a'];
    }
    p->checkEnd = 1;
}

int find(string a){
    node *p = root;
    for (int i = (int)a.length() - 1; i >= 0; i--){
        if (p->child[a[i] - 'a'] == NULL){
            return 0;
        }
        p = p->child[a[i] - 'a'];
    }
    if (p->checkEnd == 1){
        return 1;
    }
    return 0;
}


int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string x;
        cin >> x;
        insert(x);
        // cout << x << endl;
    }

    dp[0] = 1;

    // cout << find("cd");

    for (int i = 0; i < (int)s.length(); i++){
        node *p = root;
        // cout << i + 1 << endl;
        for (int j = 0; i - j >= 0 and j < 100; j++){
            int c = s[i - j] - 'a';
            // cout << s[i - j];
            if (p->child[c] == NULL){
                // cout << "*";
                break;

            }
            p = p->child[c];
            if (p->checkEnd == 1){
                (dp[i + 1] += dp[i - j]) %= mod;

            }
        }
        // cout << endl;
    }

    // for (int i = 0; i <= (int)s.length(); i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[(int)s.length()];
    return 0;
}