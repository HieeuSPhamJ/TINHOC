#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,pair <int,int>>

#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1010;

ii dir[] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int test;
int n, m;
int a[maxN][maxN];
vector <iii> listNode;
ii father[maxN][maxN];
bool select[maxN][maxN];

ii findFather(ii node){
    if (node == father[node.fi][node.se]){
        return node;
    }
    return father[node.fi][node.se] = findFather(father[node.fi][node.se]);
}

bool cmp(ii x, ii y){
    return x.se > y.se;
}
signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            father[i][j] = {i,j};
            listNode.push_back({a[i][j], {i, j}});
        }
    }

    sort(listNode.begin(), listNode.end());
    
    vector <ii> testList;
    
    cin >> test;
    for (int i = 1; i <= test; i++){
        int inp;
        cin >> inp;
        testList.push_back({i, inp});
    }
    sort(testList.begin(), testList.end(), cmp);

    // for (auto test: testList){
    //     cout << test.se << " ";
    // }
    // cout << endl;

    int com = 0;

    vector <ii> listAns;

    for (auto test: testList){
        int maxVal = test.se;
        // cout << "VAL: " << maxVal << endl;
        vector <ii> listE;

        while(!listNode.empty() and listNode.back().fi > maxVal){
            ii node = listNode.back().se;
            listNode.pop_back();
            listE.push_back(node);
            com++;
        } 

        for (auto node: listE){
            for (int i = 0; i < 4; i++){
                ii newNode = {node.fi + dir[i].fi, node.se + dir[i].se};
                if (a[newNode.fi][newNode.se] > maxVal){
                    ii u = findFather(node);
                    ii v = findFather(newNode);
                    // cout << newNode.fi << " " << newNode.se << endl;
                    if (u == v){
                        continue;
                    }
                    com--;
                    father[u.fi][u.se] = v;
                }
            }
        }

        listAns.push_back({test.fi, com});
        // cout << com << endl;

    }    

    sort(listAns.begin(), listAns.end());

    for (auto ans: listAns){
        cout << ans.se << endl;
    }

    return 0;
}