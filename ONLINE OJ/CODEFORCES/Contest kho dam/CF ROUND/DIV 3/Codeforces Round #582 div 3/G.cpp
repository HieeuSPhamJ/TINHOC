#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct iii{
    int a,b,w;
};

bool cmp(iii a, iii b){
    return a.w > b.w;
}

int cal(int n){
    if (n == 1){
        return 0;
    }
    return (n * (n - 1)) / 2;
}

const int maxN = 2 * 1e5 + 10;

int sizeCom[maxN];
int father[maxN];

int findFather(int node){
    if (father[node] == node){
        return node;
    }
    return father[node] = findFather(father[node]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector <iii> listE;
    for (int i = 1; i <= n; i++){
        sizeCom[i] = 1;
        father[i] = i;
    }
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        listE.push_back({a,b,w});
    }

    sort(listE.begin(), listE.end(), cmp);
    
    vector <ii> listQuery;

    for (int i = 1; i <= test; i++){
        int inp;
        cin >> inp;
        listQuery.push_back({inp, i});
    }

    sort(listQuery.begin(), listQuery.end());

    vector <ii> listAns;

    int ans = 0;

    for (auto q: listQuery){
        int maxWeight = q.fi;
        // cout << "Weight: " << maxWeight << endl;
        while(!listE.empty() and listE.back().w <= maxWeight){
            int a = listE.back().a;
            int b = listE.back().b;
            listE.pop_back();
            // cout << a << " " << b << endl;
            int u = findFather(a);
            int v = findFather(b);
            if (u == v){
                continue;
            }
            // cout << u << "-" << v << endl;
            father[u] = v;
            ans -= cal(sizeCom[u]);
            ans -= cal(sizeCom[v]);
            // cout << sizeCom[u] << ":" << cal(sizeCom[u]) << " " << sizeCom[v] <<":" << cal(sizeCom[v]) << " ";

            sizeCom[v] += sizeCom[u];
            ans += cal(sizeCom[v]);
            // cout << sizeCom[v] << ":" << cal(sizeCom[v]) << endl;
        }
        listAns.push_back({q.se, ans});
        // cout << ans << endl;
    }

    sort(listAns.begin(), listAns.end());

    for (auto i: listAns){
        cout << i.se << " ";
    }
    return 0;
}