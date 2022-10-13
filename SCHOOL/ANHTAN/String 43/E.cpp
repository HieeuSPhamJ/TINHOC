#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxBIT = 10010;

int COUNT = 0;

int a[maxBIT];

struct node{
    node *child[2];
    int checkEnd;
    int dp;
    int cnt;
    node(){
        child[0] = NULL;
        child[1] = NULL;
        checkEnd = 0;
        dp = 0;
        cnt = COUNT;
        COUNT++;
    }
};


node *root = new node();

int DFS(node *n){
    node *p = n;
    n->dp = n->checkEnd;
    
    for (int i = 0; i <= 1; i++){
        if (p->child[i] == NULL){
            continue;
        }
        n->dp += DFS(p->child[i]);
    }   

    // cout << n->cnt << " " << n->dp << " " << n->checkEnd << endl;

    return n->dp;
}

int check(string n){
    node *p = root;
    for (int i = 0; i < n.size(); i++){
        int dig = n[i] - '0';
        // cout << p->cnt << " ";
        if (p->child[dig] == NULL){
            cout << i << endl;
            return 0;
        }   
        p = p->child[dig];
        
    }
    if (p->checkEnd) return 1;
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    while (n--){
        int num;
        cin >> num;
        // cout << "#" << num << endl;
        node *p = root;
        for (int i = 1; i <= num; i++){
            int dig;
            cin >> dig;
            if (p->child[dig] == NULL){
                p->child[dig] = new node();
            }   
            p = p->child[dig];
            // cout << dig << " ";
            // cout << p->cnt << endl;
        }
        p->checkEnd += 1;
        // cout << "*" << endl;
    }
    DFS(root);
    // cout << DFS(root) << endl;

    // cout << "====" << endl;

    
    // cout << check("10");

    while(m--){
        int num;
        cin >> num;
        node *p = root;
        int ans = 0;
        int check = 1;
        // cout << "NUM: " << num << endl;
        for (int i = 1; i <= num; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= num; i++){
            int dig = a[i];
            if (p->child[dig] == NULL){
                check = 0;
                break;
            }   
            // cout << p->child[dig]->cnt << " ";
            p = p->child[dig];
            ans += p->checkEnd;
        }
        // cout << " Path" << endl;
        // cout << "Ass: " << p->cnt << " " << p->dp << endl;
        if (check != 0){
            ans += p->dp - (p->checkEnd);
        }
        cout << ans << endl;
    }
    return 0;
}