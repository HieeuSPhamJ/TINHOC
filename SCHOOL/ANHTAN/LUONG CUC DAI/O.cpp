#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 40;

int n;
int a[maxN][maxN];
int win[maxN];
int twin[maxN];
set <int> adj[maxN];
int check[maxN][maxN];

bool cmp(int x, int y){
    return twin[x] < twin[y];
}

void printWin(){
    for (int i = 1; i <= n; i++){
        cout << twin[i] << " ";
    }
    cout << endl;
}

bool solve(int i){
    int ok = 1;
    memset(check, 0, sizeof(check));
    // cout << win[i] << endl;
    cout << "Index: " << i << endl;
    vector <int> lists;
    set <int> tadj[maxN];
    for (int j = 1; j <= n; j++){
        twin[j] = win[j];
        tadj[j] = adj[j];
        if (i == j){
            continue;
        }
        lists.push_back(j);
    }

    printWin();

    sort(all(lists), cmp);
    for (auto e: tadj[i]){
        twin[i]++;
        tadj[e].erase(i);
    }
    tadj[i].clear();

    for (auto now: lists){
        cout << "With: " << now << endl;
        for (auto e: tadj[now]){
            cout << e << " ";
            // if (twin[e] >= twin[i]){
            //     twin[now]++;
            // }
            // else{
                twin[now]++;
            // }
            tadj[e].erase(now);
        }
        cout << endl;  
        
        printWin();
        tadj[now].clear();
    }

    lists.push_back(i);

    sort(all(lists), cmp);

    printWin();

    if (twin[lists[0]] != twin[i]){
        ok = 0;
    }

    return ok;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j]; 
            if (a[i][j] == 2){
                adj[i].insert(j);
                adj[j].insert(i);
            }
            win[i] += (a[i][j] == 1);
        }
    }
    

    // for (int i = 1; i <= n; i++){
    //     cout << solve(i);
    // }

    cout << solve(8);


    return 0;
}