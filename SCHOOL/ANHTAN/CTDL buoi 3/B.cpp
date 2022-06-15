#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 5 * 1e5 + 10;

int n, test;
int a[maxN];
int t[maxN];
bool check[maxN];
int boss[maxN];
int val[maxN];
int maxAns = 0;
int ans[maxN];

void printVal(){
    cout << "Val: ";
    for (int i = 1; i <= n; i++){
        cout << val[i] << ' '; 
    }
    cout << endl;
}

void printBoss(){
    cout << "Boss: ";
    for (int i = 1; i <= n; i++){
        cout << boss[i] << ' '; 
    }
    cout << endl;
}

void printCheck(){
    cout << "Check: ";
    for (int i = 1; i <= n; i++){
        cout << check[i] << ' '; 
    }
    cout << endl;
}

int checkBoss(int node){
    if (node == boss[node]){
        return node;
    }
    return boss[node] = checkBoss(boss[node]);
}

void connect(int i, int j){
    int u = checkBoss(i);
    int v = checkBoss(j);
    if (u != v){
        boss[v] = u;
        val[u] += val[v];
        maxAns = max(maxAns, val[u]);
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        boss[i] = i;
        val[i] = a[i];
    }

    boss[0] = 1;
    boss[n + 1] = n;

    for (int i = 1; i <= test; i++){
        cin >> t[i];
        // cout << t[i] << endl;
        check[t[i]] = 1;    
    }

    for (int i = 1; i <= n; i++){
        if (!check[i]){
            maxAns = max(maxAns, val[i]);
        }
    }

    for (int i = 1; i <= n; i++){
        if (!check[i] and !check[i - 1]){
            connect(i, i - 1);  
        }
    }

    for (int i = 1; i <= n; i++){
        if (!check[i]){
            ans[test] = max(ans[test], val[i]);
        }
    }

    // printCheck();
    for (int i = test; i > 1; i--){
        check[t[i]] = 0;
        maxAns = max(maxAns, val[t[i]]);
        if (check[t[i]] == 0 and check[t[i] - 1] == 0){
            connect(t[i], t[i] - 1);
        }
        if (check[t[i]] == 0 and check[t[i] + 1] == 0){
            connect(t[i], t[i] + 1);
        }
        // cout << t[i] << endl;
        // printCheck();
        // printBoss();
        // cout << maxAns << endl << endl;
        ans[i - 1] = maxAns;
    }
    // cout << maxAns;

    for (int i = 1; i <= test; i++){
        cout << ans[i] << endl;
    }


    return 0;
}