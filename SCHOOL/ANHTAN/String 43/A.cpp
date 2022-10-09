#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
    node *child[26];
    bool checkEnd = 0;
    // int dp = 0;
    node(){
        for (int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        checkEnd = 0;
        // dp = 0;
    }    
};

node *root = new node();
int ans = 0;

void insert(string a){
    node *p = root;
    for (int i = 0; i < (int)a.length(); i++){
        if (p->child[a[i] - 'a'] == NULL){
            p->child[a[i] - 'a'] = new node();
        }
        p = p->child[a[i] - 'a'];
    }
    p->checkEnd = 1;
}

int find(string a){
    node *p = root;
    for (int i = 0; i < (int)a.length(); i++){
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

int DFS(node *n){
    node *p = n;
    int ans = 0;
    for (int i = 0; i < 26; i++){
        if (p->child[i] == NULL){
            continue;
        }
        ans = max(ans, DFS(p->child[i]));
    }   
    return ans + n->checkEnd;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    cout << DFS(root);

    return 0;
}