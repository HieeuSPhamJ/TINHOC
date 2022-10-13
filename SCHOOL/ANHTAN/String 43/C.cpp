#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxBIT = 5;


bool getBit(int mask, int i){
    return (mask & (1ll << i));
}

int onBit(int mask, int i){
    return mask | (1ll << i);
}

int offBit(int mask, int i){
    return (mask xor (1ll << i));
}


int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1ll);
        mask >>= 1ll;
    }
    return count;
}

struct node{
    node *child[2];
    bool checkEnd;
    node(){
        child[0] = NULL;
        child[1] = NULL;
        checkEnd = 0;
    }
};

node *root = new node();

void insert(int n){
    node *p = root;
    for (int i = maxBIT; i >= 0; i--){
        int dig = getBit(n,i);
        if (p->child[dig] == NULL){
            p->child[dig] = new node();
        }   
        p = p->child[dig];
    }
}

int check(int n){
    node *p = root;
    for (int i = maxBIT; i >= 0; i--){
        int dig = getBit(n,i);
        if (p->child[dig] == NULL){
            return 0;
        }   
        p = p->child[dig];
    }
    return 1;
}

int find(int n){
    int mask = 0;
    node *p = root;
    for (int i = maxBIT; i >= 0; i--){
        int dig = getBit(n,i);
        // cout << dig << " ";
        if (p->child[!dig] != NULL){
            cout << !dig;
            if (!dig){
                mask = onBit(mask,i);
            }
            p = p->child[!dig]; 
        }
        else{
            for (int x = 0; x <= 1; x++){
                if (p->child[x] != NULL){
                    p = p->child[x];
                    cout << x;   
                    if (!x){
                        mask = onBit(mask,i);
                    }
                }
            }
        }
    }
    cout << endl;
    return mask;
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
        int inp;
        cin >> inp;
        insert(inp);
    }
    // cout << check(2) << endl;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        cout << find(inp) << " ";
        cout << endl;
    }
    return 0;
}