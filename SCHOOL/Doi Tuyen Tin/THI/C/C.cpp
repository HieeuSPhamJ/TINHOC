#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int father[maxN];
int minVal[maxN];

int findFather(int node){
    if (node == father[node]){
        return node;
    }
    return father[node] = findFather(father[node]);
}

bool cmp(int x, int y){
    return minVal[x] < minVal[y];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        father[i] = i;
        minVal[i] = a[i];
    }

    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        int u = findFather(x);
        int v = findFather(y);
        if (u == v){
            continue;
        }
        father[u] = v;
        minVal[v] = min(minVal[u], minVal[v]);
    }

    set <int> mySet;

    for (int i = 1; i <= n; i++){
        int fa = findFather(i);
        mySet.insert(fa);
    }

    vector <int> myVec;

    for (auto i: mySet){
        myVec.push_back(i);
        // cout << i << ": " << minVal[i] << endl;
    }

    sort(myVec.begin(), myVec.end(), cmp);
    
    int root = minVal[myVec[0]];
    int ans = 0;
    for (int i = 1; i < (int)myVec.size(); i++){
        ans += root + minVal[myVec[i]];
    }

    cout << ans;

    return 0;
}