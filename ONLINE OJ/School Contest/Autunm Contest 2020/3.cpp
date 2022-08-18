#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 2 * 1e5 + 10;

int father[maxN];

bool cmp(iii a, iii b){
    return a.w < b.w;
}

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, wire, m, k;
        cin >> n >> wire >> m >> k;
        for (int i = 0; i <= n; i++){
            father[i] = i;
        }
        
        vector <iii> E;

        for (int i = 1; i <= k; i++){
            int inp;
            cin >> inp;
            E.push_back({0,inp,0});
        }

        
        for (int i = 1; i <= wire; i++){
            int a, b, w;
            cin >> a >> b >> w;
            E.push_back({a,b,w});
        }
        sort(E.begin(), E.end(), cmp);
        
        int ans = 0;

        for (auto tempE: E){
            int a = findFather(tempE.a);
            int b = findFather(tempE.b);
            if (a == b){
                continue;
            }
            ans += tempE.w;
            father[a] = b;
            // cout << tempE.a << " " << tempE.b << " " << tempE.w << endl;
        }

        // for (int i = 0; i <= n; i++){
        //     cout << i << ": " << father[i] << endl;
        // }

        cout << ans + m * (n - k) << endl;
        // cout << "------" << endl;
    }
    return 0;
}