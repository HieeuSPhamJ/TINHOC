#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, m, test;
vector <int> adj[maxN];
int father[maxN][17];
int level[maxN];
set <int> adu[maxN][17];
set <int> store[maxN];

void DFS(int node, int daddy){
    for (auto newNode: adj[node]){
        if (newNode == daddy){
            continue;
        }
        father[newNode][0] = node;
        level[newNode] = level[node] + 1;
        DFS(newNode, node);
    }
}

void merg(set <int> &res, set <int> b){
    set <int> a;
    swap(a,res);
    while((!a.empty() or !b.empty()) and res.size() < 10){
        if (!a.empty() and !b.empty()){
            if (*a.begin() < *b.begin()){
                res.insert(*a.begin());
                a.erase(a.begin());
            }
            else{
                res.insert(*b.begin());
                b.erase(b.begin());
            }
        }
        else{
            if (!a.empty()){
                res.insert(*a.begin());
                a.erase(a.begin());
            }
            else{
                res.insert(*b.begin());
                b.erase(b.begin());
            }
        }
    }
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
    for (int i = 1; i <= n; i++){
        merg(adu[i][0],store[i]);
        merg(adu[i][0],store[father[i][0]]);

    }
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            // cout << i << " " << j << endl;
            merg(adu[i][j], adu[i][j - 1]);
            // cout << "!" << i << " " << j - 1 << " : ";
            // for (auto x: adu[i][j]){
            //     cout << x << " ";
            // }
            // cout << endl;
            merg(adu[i][j], adu[father[i][j - 1]][j - 1]);
            // cout << "!" << father[i][j - 1] << " " << j - 1 << " : ";
            // for (auto x: adu[i][j]){
            //     cout << x << " ";
            // }
            // cout << endl;

        }
    }
}

void print(set <int> &lists, int w){
    // cout << "print: ";
    cout << min(w,(int)lists.size()) << " ";
    for (auto i: lists){
        cout << i << " ";
        w--;
        if (w <= 0){
            break;
        }
    }
    cout << endl;
}

void LCA(int a, int b, int w){
    // cout << "Test: " << a << " " << b << " " << w << endl;
    
    set <int> lists;

    merg(lists,store[a]);
    merg(lists,store[b]);

    
    if (a == b){
        print(lists, w);
        return;
    }


    if (level[a] < level[b]){
        swap(a,b);
    }

    for (int i = log2(level[a]); i >= 0; i--){
        if (level[father[father[a][0]][i]] >= level[b]){
            merg(lists,adu[a][i]);
            a = father[a][i];
            // cout << a << " " << b << endl;
        }
    }
    
    // print(lists,100);
    if (level[a] != level[b]){
        a = father[a][0];
        merg(lists,store[a]);
    }

    if (a == b){
        print(lists, w);
        return;
    }

    for (int i = log2(level[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            // cout << a << " " << b << endl;
            merg(lists,adu[a][i]);
            merg(lists,adu[b][i]);
            a = father[a][i];
            b = father[b][i];
        }
    }

    
    merg(lists,store[father[a][0]]);

    
    print(lists, w);
    // cout << endl;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> test;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        // cout << x << " " << i << endl;
        if (store[x].size() < 10){
            store[x].insert(i);
        }
    }

    DFS(1,1);
    init();

    while(test--){
        int a, b, w;
        cin >> a >> b >> w;
        LCA(a,b,w);
        // cout << "ADU";
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= 4; j++){
    //         cout << i << " " << j << ":" << endl;
    //         for (auto x: adu[i][j]){
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }
    //     // cout << "index " << i << endl;
    //     // for (auto j: store[i]){
    //     //     cout << j << " ";
    //     // }
    //     // cout << endl;
    // }

    return 0;
}
