#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n;
int sizetree;
ii a[maxN];
vector <int> adj[maxN];



void buildtree(int left, int right){
    sizetree--;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }

    sizetree = n;
    buildtree(1,n);
    
    return 0;
}