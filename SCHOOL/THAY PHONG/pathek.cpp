#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
int k = 1;
bool ans[maxN];
vector <int> adj[maxN];
int dp[maxN];
int cnt[maxN];
int check = 1;
int ban[maxN];

void DFS(int node, int father){
    if (check == 0){
        return;
    }
    cnt[node] = 1;
    vector <int> temp;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        temp.push_back(cnt[newNode]);
    }   
    if (temp.size() == 1){
        if (temp[0] != k){
            cnt[node] = temp[0] + 1;
        }   
        return;
    }

    sort(temp.begin(), temp.end());

    int left = 0;
    int right = temp.size() - 1;
    while(left < right){
        if (temp[left] + temp[right] == k){
            temp[left] = -1;
            temp[right] = -1;
            left++;
            right--;
        }
        else if (temp[left] + temp[right] < k){
            left++;
        }
        else if (temp[left] + temp[right] > k){
            right--;
        }
    }
    int count = 0;
    int val = 0;
    for (auto i: temp){
        if (i != -1 and i != k and i != 0){
            count++;
            val = i;
        }
    }
    if (count > 1){
        check = 0;
        return;
    }
    if (count == 0){
        return;
    }
    cnt[node] = val + 1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> listK;
    m = n - 1;
    for (int i = 1; i * i <= n; i++){
        if (m % i == 0){
            listK.push_back(i);
            if (i != m / i){
                listK.push_back(m / i);
            }
        }
    }

    for (auto i: listK){
        if (ban[i]){
            continue;
        }
        k = i;
        check = 1;
        DFS(1,1);
        if (check == 1){
            ans[i] = 1;
        }
        else{
            for (int j = i*i; j < n; j+=i){
                ban[j] = 1;
            }
        }
    }

    // k = 1;
    // DFS(1,1);

    for (int i = 1; i <= m; i++){
        cout << ans[i];
    }
    return 0;
}