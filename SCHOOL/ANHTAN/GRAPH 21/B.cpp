#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 2 * 1e5 + 10;

int father[maxN];

bool cmp(iii a, iii b){
    return a.w < b.w;
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    vector <iii> E;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back({a,b,w});
    }
    sort(E.begin(), E.end(), cmp);
    
    int ans = 0;

    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            continue;
        }
        ans = max(ans,tempE.w);
        father[a] = b;
    }

    cout << ans;

    return 0;
}