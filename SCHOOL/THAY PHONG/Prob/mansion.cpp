#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1 * 1e6 + 10;

int n, m, k;
int cnt = 0;
int dem = 0;
vector <iii> lists;
int End1 = -1;
int End2 = -1;
vector <ii> adj[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;
int visited[maxN];

bool cmpy(iii a, iii b){
    if (a.se.se == b.se.se){
        return a.se.fi < b.se.fi;
    }
    return a.se.se < b.se.se;
}

bool cmpx(iii a, iii b){
    if (a.se.fi == b.se.fi){
        return a.se.se < b.se.se;
    }
    return a.se.fi < b.se.fi;
}

void reset(){
    for (int i = 1; i <= cnt + dem; i++){
        visited[i] = inf;
    }
}

void Dickcha(int Start){
    reset();
    myHeap.push({0, Start});
    visited[Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.id == End1 or tempV.id == End2){
            continue;
        }
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    lists.push_back({cnt,{1,1}});
    cnt++;
    lists.push_back({cnt,{n,m}});
    End1 = cnt;
    cnt++;
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({cnt,{a,b}});
        cnt++;
    }

    dem = cnt + 10;
    End2 = End1 + dem;
    

    for (auto x: lists){
        ii i = x.se;
        if (i != make_pair(1ll,1ll) and i != make_pair(n,m)){
            // cout << cnv[i] << " " << cnv[i] + dem << endl;
            int cv = x.fi;
            adj[cv].push_back({1, cv + dem});
            adj[cv + dem].push_back({1,cv});   
        }
    }

    sort(lists.begin(), lists.end(), cmpx);
    for (int i = 1; i < (int)lists.size(); i++){
        ii a = lists[i].se;
        ii b = lists[i - 1].se;
        // cout << cnv[a] << " " << cnv[b] << endl;
        if (a.fi == b.fi){
            // cout << a.fi << " " << a.se << " - " << b.fi << " " << b.se << endl;
            // cout << cnv[a] << " " << cnv[b] << endl;
            int cva = lists[i].fi;
            int cvb = lists[i - 1].fi;
            adj[cva].push_back({abs(a.se - b.se), cvb});
            adj[cvb].push_back({abs(a.se - b.se), cva});
        }
    }
    sort(lists.begin(), lists.end(),cmpy);
    for (int i = 1; i < (int)lists.size(); i++){
        ii a = lists[i].se;
        ii b = lists[i - 1].se;
        
        if (a.se == b.se){
            // cout << cnv[a] + dem << " " << cnv[b] + dem << endl;
            int cva = lists[i].fi + dem;
            int cvb = lists[i - 1].fi + dem;
            adj[cva].push_back({abs(a.fi - b.fi), cvb});
            adj[cvb].push_back({abs(a.fi - b.fi), cva});
        }
    }

    Dickcha(0);
    // cout << "CNV: " << cnv[{n,m}] << " " << cnv[{n,m}] + dem << endl;
    if (visited[End1] == inf and visited[End2] == inf){
        cout << -1;
        return 0;
    }
    
    cout << min(visited[End1], visited[End2]);

    return 0;
}