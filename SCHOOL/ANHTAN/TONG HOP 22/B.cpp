#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 1e5 + 10;

int father[maxN];
int sizeCon[maxN];

bool cmp(iii a, iii b){
    return a.w < b.w;
}

bool cmpQ(iii a, iii b){
    return a.a > b.a;
}

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        father[i] = i;
        sizeCon[i] = 1;
    }
    vector <iii> listE;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        listE.push_back({a,b,w});
    }

    vector <iii> listQuery;

    for (int i = 1; i <= q; i++){
        int v, k;
        cin >> k >> v;
        listQuery.push_back({k,v,i});
    }

    sort(listE.begin(), listE.end(), cmp);
    sort(listQuery.begin(), listQuery.end(), cmpQ);

    vector <ii> ans;
    
    for (auto q: listQuery){
        // cout << q.a << " " << q.b << " " <<q.w << endl;
        while(!listE.empty() and listE.back().w >= q.a){
            // cout << listE.back().w << '-' << endl;
            int a = listE.back().a;
            int b = listE.back().b;
            listE.pop_back();
            int u = findFather(a);
            int v = findFather(b);
            if (u == v){
                continue;
            }
            father[u] = v;
            sizeCon[v] += sizeCon[u];
        }
        // cout << q.b << " " << sizeCon[findFather(q.b)] - 1 << endl;
        ans.push_back({q.w,sizeCon[findFather(q.b)] - 1});
    }

    sort(ans.begin(), ans.end());

    for (auto i: ans){
        cout << i.se << endl;
    }


    return 0;
}