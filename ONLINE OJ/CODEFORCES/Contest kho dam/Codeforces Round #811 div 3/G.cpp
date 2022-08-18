#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


const int maxN = 2 * 1e5 + 10;

vector <iii> adj[maxN];
int preA[maxN];
int preB[maxN];
int ans[maxN];
vector <int> listE;

void getPrefix(int node, int khang){
    for (auto newNode: adj[node]){
        if (newNode.fi == khang){
            continue;
        }
        preA[newNode.fi] = preA[node] + newNode.se.fi;
        preB[newNode.fi] = preB[node] + newNode.se.se;
        getPrefix(newNode.fi, node);
    }

}

void DFS(int node, int father){
    for (auto newNode: adj[node]){
        if (newNode.fi == father){
            continue;
        }
        listE.push_back(newNode.fi);

        int left = 1;
        int right = listE.size() - 1;
        int tempAns = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (preA[newNode.fi] >= preB[listE[mid]]){
                left = mid + 1;
                tempAns = max(tempAns, mid);
            }
            else{
                right = mid - 1;
            }
        }

        ans[newNode.fi] = tempAns;
        
        DFS(newNode.fi, node);
        listE.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        listE.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
        }
        for (int i = 2; i <= n; i++){
            int j, a, b;
            cin >> j >> a >> b;
            adj[i].push_back({j,{a,b}});
            adj[j].push_back({i,{a,b}});
        }
        getPrefix(1,1);
        
        listE.push_back(1);

        DFS(1,1);

        for (int i = 2; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}