#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
    node* a[26];
    bool checkEnd = 0;
    node(){
        for (int i = 0; i < 26; i++){
            a[i] = NULL;
        }
        checkEnd = 0;
    }
};

node *root = new node();

void insert(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - 'a';
        if (p->a[dig] == NULL){
            p->a[dig] = new node();
        }
        p = p->a[dig];
    }
    p->checkEnd = 1;
}


int find(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - 'a';
        if (p->a[dig] == NULL){
            return 0;
        }
        p = p->a[dig];
    }
    
    if (p->checkEnd == 1){
        return 1;
    }
    return 0;

}

const int maxN = 1e5 + 10;

int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++){
        string x;
        cin >> x;
        insert(x);
    }
    int len = s.length();
    s = "-" + s;
    for (int i = 1; i <= len; i++){
        node *p = root;
        for (int j = i; j <= len; j++){
            int dig = s[j] - 'a';
            if (p->a[dig] == NULL){
                break;
            }
            p = p->a[dig];
            if (p->checkEnd){
                dp[j] = max(dp[j], dp[i - 1] + j - i + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= len; i++){
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    // cout << endl;
    cout << ans;
    return 0;
}