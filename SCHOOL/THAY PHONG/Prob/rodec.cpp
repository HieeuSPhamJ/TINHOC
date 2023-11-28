#include<bits/stdc++.h>
#define ii pair <int,int>
#define i3 pair <int,ii>
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
const int maxN = 1e5 + 10;

struct iii{
    int a, b, w;
};

int n, m, test, MST, dick;

vector <ii> adj[maxN];
int visited[maxN];
ii trace[maxN];
int check[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;
vector <iii> E;
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

void Dickcha(){
    dick = 0;
    myHeap.push({0, 0});
    visited[0] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                trace[newV.id] = {newV.val, tempV.id};
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
            else if (visited[tempV.id] + newV.val == visited[newV.id]){
                if (newV.val < trace[newV.id].val){
                    trace[newV.id] = {newV.val, tempV.id};
                }
            }
        }
        // cout << endl;
    }

    set <i3> lists;
    memset(check,0,sizeof(check));
    for (int i = 1; i <= n; i++){
        if (check[i]){
            continue;
        }
        check[i] = 1;
        int temp = i;
        cout << i << " ";
        while(trace[temp].id != -1){
            lists.insert({trace[temp].val, {min(temp, trace[temp].id), max(temp, trace[temp].id)}});
            temp = trace[temp].id;
            cout << temp << " ";
        }
        cout << endl;
    }
    for (auto i: lists){
        dick += i.fi;
    }
}
 
void Krukal(){
    MST = 0;
    sort(E.begin(), E.end(), cmp);
    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            continue;
        }
        MST += tempE.w;
        father[a] = b;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        for (int i = 0; i <= n; i++){
            visited[i] = inf;
            father[i] = i;
            adj[i].clear();
            trace[i] = {-1,-1};
        }
        
        for (int i = 1; i<= m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({w,b});
            adj[b].push_back({w,a});
            E.push_back({a,b,w});
        }

        Krukal();
        Dickcha();

        if(MST == dick){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}