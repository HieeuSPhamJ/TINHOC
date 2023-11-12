#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int dp[maxN];
int mk[maxN];

bool cmp(int a, int b){
    return mk[a] < mk[b];
}

void dfs(int nu){
    deque <ii> ls;
    for (auto i: adj[nu]){
        dfs(i);
        ls.push_back({dp[i],i});
    }
    if (adj[nu].size()){
        dp[nu] = 1e18;
    }
    // cout << "With: " << nu << endl;
    for (int t = 1; t <= (int)ls.size(); t++){
        int tres = 0;
        for (int i = 0; i < (int)ls.size(); i++){
            tres = max(tres, ls[i].fi + i);
        }
        if (dp[nu] > tres){
            dp[nu] = tres;
            // cout << tres << ": ";
            for (int i = 0; i < (int)ls.size(); i++){
                // cout << ls[i].fi << ' ';
                mk[ls[i].se] = i;
            }
            // cout << endl;
        }

        ls.push_back(ls.front());
        ls.pop_front();
    }
    cout << nu << " " << dp[nu] << endl;
    sort(all(adj[nu]),cmp);
}

void trace(int nu){
    // cout << nu << endl;
    for (auto i: adj[nu]){
        trace(i);
    }
    if (adj[nu].size()){
        cout << adj[nu].size();
    }
    else{
        cout << "a";
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    int n = 0;
    vector <int> st;
    while(cin >> c){
        n++;
        if (c == 'a'){
            dp[n] = 1;
            st.push_back(n);
        }
        else{
            int t = c - '0';
            while(t--){
                adj[n].push_back(st.back());
                // cout << n << ' ' << st.back() << endl;
                st.pop_back();
            }
            st.push_back(n);
        }
    }

    for (int i = 1; i <= n; i++){
        reverse(all(adj[i]));
    }

    dfs(n);

    cout << dp[n] << endl;

    trace(n);
    return 0;
}

/*
2 3 1
3 1 2
1 2 3
*/