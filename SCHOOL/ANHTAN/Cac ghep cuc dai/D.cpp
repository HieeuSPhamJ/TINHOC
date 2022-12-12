#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
vector <int> adj[maxN];
int ml[maxN];
int mr[maxN];
int dist[maxN];

bool canop(){
    queue <int> q;
    for (int i = 1; i <= n; i++){
        if (ml[i] == 0){
            q.push(i);
            dist[i] = 0;
        }
        else{
            dist[i] = -1;
        }
    }
    int can = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for (auto i: adj[t]){
            if (mr[i] == 0){
                can = 1;
            }
            else  if(dist[mr[i]] < 0){
                dist[mr[i]] = dist[t] + 1;
                q.push(mr[i]);
            }
        }
    }

    return can;
}

bool Try(int node){
    for (auto i: adj[node]){
        if (mr[i] == 0){
            ml[node] = i;
            mr[i] = node;
            return 1;
        }
        if ((dist[mr[i]] == dist[node] + 1) and Try(mr[i])){
            ml[node] = i;
            mr[i] = node;
            return 1;
        }
    }
    return 0;
}

int cac(){
    while(canop()){
        // cout << "try" << endl;
        for (int i = 1; i <= n; i++){
            if (ml[i] == 0){
                Try(i);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += (ml[i] != 0);
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> n;
    m = n;

    vector <pair<int,ii>> lists;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int w;
            cin >> w;
            lists.push_back({w,{i,j}});
        }
    }

    sort(rall(lists));

    int ans = 1e18;

    while(!lists.empty()){
        auto v = lists.back();
        lists.pop_back();

        adj[v.se.fi].push_back(v.se.se);

        if (cac() == n){
            ans = v.fi;
            break;
        }
    }

    cout << ans;


    return 0;
}