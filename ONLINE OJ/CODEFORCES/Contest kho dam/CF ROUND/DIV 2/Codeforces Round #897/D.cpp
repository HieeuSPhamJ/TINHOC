#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int adj[maxN];
int vis[maxN];
int mi = 0;
int tim = 0;
vector <int> st;
set <int> s;

void tarjan(int nu){
    // cout << nu << endl;
    vis[nu] = tim;
    st.push_back(nu);
    if (vis[adj[nu]] == tim){
        int cnt = 1;
        // cout << "find: " << endl;
        while(st.size() and st.back() != adj[nu]){
            cnt++;
            // cout << st.back() << endl;
            st.pop_back();
        }
        if (st.size()){
            // cout << st.back() << endl;
            st.pop_back();
        }
        s.insert(cnt);
    }
    else{
        tarjan(adj[nu]);
    }
    if (st.size() and st.back() == nu){
        st.pop_back();
    }
}
signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            vis[i] = 0;
            cin >> adj[i];
        }
        mi = 1e18;
        if (k == 1){
            int ok = 1;
            for (int i = 1; i <= n; i++){
                if (adj[i] != i){
                    ok = 0;
                    break;
                }
            }
            if (ok){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl; 
            }
            continue;
        }
        for (int i = 1; i <= n; i++){
            if (vis[i] == 0){
                // cout << "With: " << i << endl;
                st.clear();
                tim = i;
                tarjan(i);
            }
        }
        if (s.size() >= 2){
            cout << "NO" << endl;
        }
        else if (s.size()){
            if (*s.begin() == k){
                cout << "YES" << endl; 
            }
            else{   
                cout << "NO" << endl; 
            }
        }
        else{
            cout << "YES" << endl; 
        }

    }
    return 0;
}

/*

*/