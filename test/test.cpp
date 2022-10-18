#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000005;

int n, m, soThuTuDfs, dem, tongTien, costMin = INT_MAX;
int low[maxN], num[maxN], deleted[maxN], prices[maxN];
bool isVisit[maxN];
vector<int> args[maxN];
stack<int> st, st2;

void dfs(int u) {
    isVisit[u] = true;
    low[u] = num[u] = ++soThuTuDfs;
    st.push(u);
    for (int v : args[u]) {
        if (deleted[v]) continue;
        if (isVisit[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (isVisit[v] == 1) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        ++dem;
        st2 = st;
        int v;
        while (v != u) {
            v = st.top();
            st.pop();
            deleted[v] = true;
            isVisit[v] = 2;
            cout << "Node: " << v << endl;
            cout << costMin << " " << prices[v] << endl;
            costMin = min(costMin, prices[v]);
        }

        // Lỗi ở đây
        cout << costMin << endl;
        tongTien += costMin;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> prices[i];

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        args[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!isVisit[i]) {
            dfs(i);
        }
    }

    cout << tongTien << " " << dem;

    return 0;
}