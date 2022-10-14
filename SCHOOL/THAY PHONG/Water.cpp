#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 1 * 1e5 + 10;
vector <iii> E;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        E.clear();
        int n, m;
        cin >> n >> m;
        int dig,build;
        cin >> dig >> build;
        for (int i = 0; i <= n; i++){
            father[i] = i;
        }
        

        for (int i = 1; i <= n; i++){
            E.push_back({0,i,dig});
        }
        for (int i = 1; i <= m; i++){
            int a, b, w;
            cin >> a >> b;
            E.push_back({a,b,build});
        }
        sort(E.begin(), E.end(), cmp);
        
        int ans = 0;

        for (auto tempE: E){
            int a = findFather(tempE.a);
            int b = findFather(tempE.b);
            if (a == b){
                continue;
            }
            ans = ans + tempE.w;
            father[a] = b;
        }

        cout << ans << endl;
    }

    return 0;
}