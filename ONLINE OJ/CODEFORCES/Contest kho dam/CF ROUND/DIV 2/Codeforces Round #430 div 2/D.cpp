#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
    node *a[3];
    int checkEnd = 0;
    int child = 0;
    node(){
        a[0] = NULL;
        a[1] = NULL;
    }
};

node *root = new node();

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask &(((1 << 22) - 1) xor (1 << i)));
}
int changeBit(int mask, int type, int i){
    if (type){
        return onBit(mask, i);
    }
    return offBit(mask, i);
}

void insert(int x){
    node *p = root;
    for (int i = 21; i >= 0; i--){
        int temp = getBit(x, i);
        if (p->a[temp] == NULL){
            p->a[temp] = new node();
        }
        p = p->a[temp];
    }
    p->checkEnd = 1;
}

void dfs(node *p){
    p->child = p->checkEnd;
    for (int i = 0; i <= 1; i++){
        if (p->a[i] == NULL){
            continue;
        }
        dfs(p->a[i]);
        p->child += p->a[i]->child;
    }
}

int get(int x){
    int res = 0;
    node *p = root;
    for (int i = 3; i >= 0; i--){
        int temp = getBit(x, i);
        cout << "Index: " << i << " " << temp << endl;
        for (int d = 0; d <= 1; d++){
            if (p->a[temp xor d] == NULL){
                res = changeBit(res, temp xor d, i);
                return res;
            }
            else if (p->a[temp xor d]->child == (1 << i)){
                p = p->a[temp xor d];
            }
        }
    }
    return res;
}

const int maxN = 3 * 1e5 + 10;

int fullxor[maxN];
int suffix[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector <int> lists;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        lists.push_back(inp);
    }
    dfs(root);
    // cout << root->child << endl;
    int XOR = 0;
    for (int i = 1; i <= test; i++){
        cin >> fullxor[i];
    }
    for (int i = test; i >= 1; i--){
        suffix[i] = suffix[i - 1] xor fullxor[i];
    }
    for (auto i: lists){
        insert(i xor XOR);
    }
    for (int i = 1; i <= test; i++){   
        cout << get(suffix[i + 1]) << endl;
    }
    return 0;
}