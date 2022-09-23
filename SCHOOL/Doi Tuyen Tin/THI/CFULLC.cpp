#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 1e6 + 10;

int father[maxN];
int minVal[maxN];
int a[maxN];

int findFather(int node){
    if (node == father[node]){
        return node;
    }
    return father[node] = findFather(father[node]);
}

bool cmp(int x, int y){
    return (minVal[x] < minVal[y]);
}


signed main(){
    freopen("CFULLC.INP", "r", stdin);
    freopen("CFULLC.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
        cin >> a[i];
        minVal[i] = a[i];
        father[i] = i;
    }
	for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = findFather(a);
        int v = findFather(b);
        if (u == v){
            continue;
        }
        father[u] = v;
        minVal[v] = min(minVal[v], minVal[u]);
    }

    set <int> mySet;

    for (int i = 1; i <= n; i++){
        int fa = findFather(i);
        mySet.insert(fa);
//        cout << i << ": " << fa << " " << minVal[fa] << endl;
    }

    vector <int> myVec;

    for (auto i: mySet){
//        cout << i << " ";
        myVec.push_back(i);
    }
    sort(myVec.begin(), myVec.end(),cmp);
//    cout << endl;
    int ans = 0;
    int root = myVec[0];
    if (myVec.size() == 1){
        cout << 0;
        return 0;
    }
    for (int i = 1; i < (int)myVec.size(); i++){
//        cout << root << "-" << myVec[i] << endl;
        ans += minVal[root] + minVal[myVec[i]];
    }

    cout << ans;

    return 0;
}



