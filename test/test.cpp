#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    // vector lưu các cạnh
    vector <pair<int,pair<int,int>>> lists;

    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        // Nhập cách cạnh (a,b) với trọng số w
        lists.push_back({w,{a,b}});
    }
    
    // Bố của các đỉnh
    int father[10010];

    for (int i = 0; i < 10010; i++){
        father[i] = i;
        // Gắn bố của đỉnh i là i
    }

    // sort lại cạnh theo trọng số tăng dần
    sort(lists.begin(), lists.end());

    vector <pair <int,int>> MST;
    for (int i = 0; i <= m; i++){
        // Cạnh hiện tại
        auto now = lists[i];
        // u v lần lượt là các bố của các đỉnh đầu và cuối của cạnh hiện tại 
        int u = father[now.se.fi];
        int v = father[now.se.se];
        if (u == v){
            // nếu 2 đỉnh đầu và cuối của cạnh hiện tại có cùng một bố thì k cần phải nối nữa mà có thể bỏ qua
            continue;
        }

        MST.push_back({u,v});

        // cho u là bố của mọi thằng có bố là v
        for (int j = 1; j <= n; j++){
            if (father[j] == v){
                father[j] = u;
            }
        }
    }

    return 0;
}