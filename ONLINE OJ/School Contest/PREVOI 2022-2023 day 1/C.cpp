#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;
const int inf = 1e18;

int n, m, k;
vector <ii> adj[maxN];
int spec[maxN];
int ans[maxN];
int getId[maxN];
int visited[maxN];
unordered_set <int> ban;
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

void reset(){
    for (int i = 1; i <= n; i++){
        visited[i] = inf;
    }
}

void dickcha(){
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        // cout << tempV.se << " " << visited[tempV.se] << endl;
        myHeap.pop(); 
        if (tempV.fi != visited[tempV.se]){
            continue;
        }
        for (auto newV: adj[tempV.se]){
            if (visited[tempV.se] + newV.fi < visited[newV.se]){
                // cout << newV.se << ' ';
                visited[newV.se] = visited[tempV.se] + newV.fi;
                
                myHeap.push({visited[newV.se], newV.se});
            }
        }
        // cout << endl << endl;
    }
}

void Try(){
    dickcha();
    for (int i = 1; i <= k; i++){
        if (ban.find(spec[i]) == ban.end() and visited[spec[i]] != 0){
            ans[spec[i]] = min(ans[spec[i]], visited[spec[i]]);
            // cout << spec[i] << " " << visited[spec[i]] << endl;
        }
    }
}

int calmin(){
    for (int i = 1; i <= k; i++){
        ans[spec[i]] = inf;
    }
    for (int j = log2(k); j >= 0; j--){
        // cout << "Try: " << endl;
        reset();
        for (int i = 1; i <= k; i++){
            if (getBit(i,j) and ban.find(spec[i]) == ban.end()){
                myHeap.push({0,spec[i]});
                visited[spec[i]] = 0;
                // cout << spec[i] << " ";
            }
        }
        // cout << endl;
        Try();
        // cout << "Try: " << endl;  
        reset();
        for (int i = 1; i <= k; i++){
            if (!getBit(i,j) and ban.find(spec[i]) == ban.end()){
                myHeap.push({0,spec[i]});
                visited[spec[i]] = 0;
                // cout << spec[i] << " ";
            }
        }
        // cout << endl;
        Try();
    }   
    int res = inf;
    for (int i = 1; i <= k; i++){
        if (ban.find(spec[i]) == ban.end()){
            res = min(res, ans[spec[i]]);
            // cout << spec[i] << " " << ans[spec[i]] << endl;
        }
    }
    return res;

}


vector <ii> lists;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        // cout << a << " " << b << " " << w << endl;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    for (int i = 1; i <= k; i++){
        cin >> spec[i];
    }

    int res = inf;

    for (int i = 1; i <= k; i++){
        reset();
        myHeap.push({0,spec[i]});
        visited[spec[i]] = 0;
        dickcha();
        lists.clear();
        for (int j = i + 1; j <= k; j++){
            lists.push_back({visited[spec[j]],spec[j]});
            // cout << spec[i] << " " << spec[j] << ": " << visited[spec[j]] << endl;
        }    
        ban.insert(spec[i]);
        sort(all(lists));
        for (auto j: lists){
            if (res <= j.fi){
                break;
            }
            ban.insert(j.se);
            // cout << spec[i] << "-" << j.se << endl;
            // cout << j.fi << " " << calmin() << endl;
            res = min(res,j.fi + calmin());

            ban.erase(j.se);
        }

    }

    cout << res << endl;


    return 0;
}