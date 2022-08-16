#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int check[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    stack <int> st;
    for (int i = 1; i <= k; i++){
        int inp;
        cin >> inp;
        st.push(inp);
    }
    vector <int> ans;
    while(!st.empty()){
        if (check[st.top()] == 0){
            ans.push_back(st.top());
            check[st.top()] = 1;
        }
        st.pop();
    }
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            ans.push_back(i);
        }
    }
    for (auto i: ans){
        cout << i << endl;
    }
    return 0;
}