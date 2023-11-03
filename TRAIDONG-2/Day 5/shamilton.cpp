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

struct Edge {
    int target, id;
    Edge(int _target, int _id): target(_target), id(_id) {}
};

vector<Edge> adj[30];
bool used_edge[200010]; 

list<int> euler_walk(int u) {
    // Sử dụng cấu trúc danh sách liên kết để lưu kết quả
    list<int> ans;
    
    // Xuất phát từ đỉnh u
    ans.push_back(u);
    
    while (!adj[u].empty()) {
        // Chọn một cạnh bất kì chưa thăm
        int v = adj[u].back().target;
        int eid = adj[u].back().id;
        
        // Xoá cạnh vừa đi qua khỏi đồ thị
        // Lưu ý việc xoá cạnh có thể **ảnh hưởng** tới các
        // thao tác trên đồ thị về sau do việc xoá cạnh sẽ
        // **phá huỷ** hoàn toàn danh sách cạnh
        // Nên sao lưu danh sách cạnh ra biến khác nếu cần dùng lại
        adj[u].pop_back();
        
        // Bỏ qua nếu cạnh đã thăm
        if (used_edge[eid]) continue;
        
        // Đánh dấu cạnh đã đi qua
        used_edge[eid] = true;
        
        // Di chuyển sang đỉnh mới
        u = v;
        
        // Thêm cạnh vào đường đi hiện tại
        // Có nhiều cách lưu chu trình như lưu đỉnh, cạnh, 
        // chỉ số cạnh, ...
        ans.push_back(u);
    }
    
    // Tìm cạnh chưa thăm từ một đỉnh trên chu trình hiện tại
    // Bắt đầu từ đỉnh thứ hai trong chu trình do ta biết 
    // rằng đỉnh đầu tiên trong chu trình (u) đã không còn
    // cạnh ra
    for (auto it = ++ans.begin(); it != ans.end(); ++it) {
        // Gọi đệ quy tiếp tục tìm chu trình mới
        auto t = euler_walk(*it);
        
        // Nối chu trình tìm được vào chu trình hiện tại
        t.pop_back();  
        ans.splice(it, t);
    }
    
    return ans;
}

vector <int> sto[30][30];

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
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        ii t = {s.front() - 'a', s.back() - 'a'};
        adj[t.fi].push_back({t.se, i});
        sto[t.fi][t.se].push_back(i);
        s = t.fi;
        // cout << t.fi << ' ' << t.se << endl; 
    }

    list <int> l = euler_walk(s);
    vector <int> ls;
    for (auto i: l){
        ls.push_back(i);
    }

    if ((int)ls.size() < n + 1){
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 1; i < (int)ls.size(); i++){
        cout << sto[ls[i - 1]][ls[i]].back() << " ";
        sto[ls[i - 1]][ls[i]].pop_back();
    }

    

    return 0;
}