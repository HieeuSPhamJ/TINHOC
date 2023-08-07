#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int c[maxN];
int a[maxN];
int rt[maxN];
int num[maxN];
int low[maxN];
int cnt = 0;
vector <int> st;

void tarjan(int nu){
    st.push_back(nu);
    cnt++;
    num[nu] = low[nu] = cnt;
    if (num[a[nu]]){
        low[nu] = min(low[nu], num[a[nu]]);
    }
    else{
        tarjan(a[nu]);
        low[nu] = min(low[nu], low[a[nu]]);
    }

    if (low[nu] == num[nu]){
        while(st.back() != nu){
            low[st.back()] = num[st.back()] = 1e18;
            rt[st.back()] = rt[nu];
            c[rt[nu]] = min(c[rt[nu]], c[st.back()]);
            st.pop_back();
        }
        low[st.back()] = num[st.back()] = 1e18;
        rt[st.back()] = nu;
        c[rt[nu]] = min(c[rt[nu]], c[st.back()]);
        st.pop_back();
    }
}

int ra[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        rt[i] = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i);
        }
    }
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(rt[i]);
        if (rt[a[i]] == rt[i]){
            continue;
        }
        ra[rt[i]]++;
    }

    int res = 0;

    for (auto i: s){
        if (ra[i] == 0){
            // cout << i << " ";
            res += c[i];
        }
    }
    // cout << endl;

    cout << res << endl;
    
    return 0;
}