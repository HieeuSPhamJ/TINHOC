#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int allSus;
vector <int> adj[maxN];
vector <int> check[maxN];
vector <int> listsus[maxN];
vector <int> susWith[maxN];
int ra[maxN];
int vao[maxN];
vector <int> newAdj[maxN];

int find(int i, int f){
    if (adj[i].empty()){
        return -1;
    }
    int left = 0;
    int right = (int)adj[i].size() - 1;
    int res = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (adj[i][mid] < f){
            left = mid + 1;
        }
        else{
            res = mid;
            right = mid - 1;
        }
    }
    if (adj[i][res] == f){
        return res;
    }
    return -1;
}

int findNew(int i, int f){
    if (newAdj[i].empty()){
        return -1;
    }
    int left = 0;
    int right = (int)newAdj[i].size() - 1;
    int res = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (newAdj[i][mid] < f){
            left = mid + 1;
        }
        else{
            res = mid;
            right = mid - 1;
        }
    }
    if (newAdj[i][res] == f){
        return res;
    }
    return -1;
}

bool TRY(int i, int j){
    int rai = ra[i];
    int raj = ra[j];
    int vaoi = vao[i];
    int vaoj = vao[j];
    // cout << "TRY: " << i << " " << j << " " << allSus << endl;
    // cout << i << ": " << rai << " " << vaoi << endl;
    // cout << j << ": " << raj << " " << vaoj << endl;
    if (findNew(i,j) != -1){
        vaoj--;

    }
    else if (findNew(j,i) != -1){
        raj--;
    }
    // cout << i << ": " << rai << " " << vaoi << endl;
    // cout << j << ": " << raj << " " << vaoj << endl;
    if(rai + raj + vaoi + vaoj != allSus){
        return 0;
    }
    if (rai == vaoi and raj == vaoj){
        cout << min(i,j) << " " << max(i,j);
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int p, n;
    cin >> p >> n;
    for (int i = 1; i <= n; i++){
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++){
            int inp;
            cin >> inp;
            adj[i].push_back(inp);
            check[i].push_back(0);
        }
        sort(all(adj[i]));
    }
    // cout << find(7,3) << endl;
    unordered_map <int,int> sus;
    for (int node = 1; node <= n; node++){
        // cout << "With: " << node << endl;
        for (int i = 0; i < (int)adj[node].size(); i++){
            int now = adj[node][i];
            // cout << now << " ";
            int ith = find(now, node);
            // cout << ith << endl;
            if (ith != -1){
                check[node][i] = 1;
                check[now][ith] = 1;
            }
            else{
                newAdj[node].push_back(now);
                // cout << node << " " << now << endl;
                sus[node]++;
                sus[now]++;
                ra[node]++;
                vao[now]++;
                allSus++;
                // listsus[node].push_back(now);
                // listsus[now].push_back(node);
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << "Node: " << i << endl;
    //     for (auto x: adj[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    //     for (auto x: check[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    vector <ii> sortsus; 
    for (int i = 1; i <= n; i++){
        sortsus.push_back({sus[i],i});
    }
    sort(allrev(sortsus));
    vector <int> listsus;
    for (int i = 1; i <= n; i++){
        if (ra[i] != 0 or vao[i] != 0){
            listsus.push_back(i);
        }
        susWith[ra[i] + vao[i]].push_back(i);
    }

    // for (int i: listsus){
    //     cout << i << ": ";
    //     for (auto j: newAdj[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    if (p == 1){
        int ans = 0;
        for (auto i: listsus){
            if (ra[i] + vao[i] == allSus){
                cout << i;
                break;
            }
        }
    }
    else{
        int cnt = 0;
        for (int i: listsus){
            // cout << i << ": " << endl;
            for (int d = -1; d <= 1; d++){
                for (int j: susWith[allSus - (ra[i] + vao[i]) + d]){
                    if (i == j){
                        continue;   
                    }
                    if (TRY(i,j)){
                        return 0;
                    }
                    cnt++;
                    // cout << j << " ";
                }
                // cout << endl;
            }
        }
        // cout << cnt << endl;
    }

    // TRY(1,7);


    return 0;
}