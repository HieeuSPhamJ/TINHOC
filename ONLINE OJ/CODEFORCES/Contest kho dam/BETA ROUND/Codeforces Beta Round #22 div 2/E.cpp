#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int com[maxN];
int num[maxN];
int low[maxN];
int cnt = 1;
vector <int> st;
int ra[maxN];
int vao[maxN];

void tarjan(int nu){
    num[nu] = low[nu] = cnt;
    cnt++;
    st.push_back(nu);
    for (auto i: adj[nu]){
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
        }
        else{
            tarjan(i);
            low[nu] = min(low[nu], low[i]);
        }
    }
    if (low[nu] == num[nu]){
        while(st.back() != nu){
            num[st.back()] = low[st.back()] = 1e18;
            com[st.back()] = com[nu];
            st.pop_back();
        }
        num[st.back()] = low[st.back()] = 1e18;
        com[st.back()] = com[nu];
        st.pop_back();
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back({i,x});
        adj[i].push_back(x);
        com[i] = i;
    }
    for (int i = 1; i <= n; i++){
        if (!num[i]){
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++){
        adj[i].clear();
        // cout << num[i] << " " << low[i] << endl;
        // cout << com[i] << endl;
    }
    for (auto i: ls){
        if (com[i.fi] != com[i.se]){
            // cout << com[i.fi] << " " << com[i.se] << endl;
            ra[com[i.fi]]++;
            vao[com[i.se]]++;
        }
    }
    vector <int> v,r;
    for (int i = 1; i <= n; i++){
        // cout << vao[i] << " " << ra[i] << endl;
        if (vao[i] * ra[i] == 0 and vao[i] + ra[i] > 0){
            // cout << i << endl;
            if (vao[i] == 0){
                v.push_back(i);
            }
            else{
                r.push_back(i);
            }
        }
    }

    if (r.size() * v.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    cout << v.size() + r.size() - 1 << endl;

    for (int i = 0; i < v.size() - 1; i++){
        cout << v[i] << " " << v[i + 1] << endl;
    }
    r.push_back(v.front());
    for (int i = 0; i < r.size() - 1; i++){
        cout << r[i] << " " << r[i + 1] << endl;
    }
    

    return 0;
}