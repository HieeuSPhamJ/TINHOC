#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct dataType{
    int a,b,c,m;
};

const int maxN = 3 * 1e6 + 10;
// const int mod = 1e9 + 7;

int N;
int n, q;
int l[maxN];
int r[maxN];
int z[maxN];
int realVal[maxN];
// vector <int> lists;
vector <ii> gaps;
int tempPre[maxN];
ii prefixNum[maxN];

void prepare(){
    
    // memset(realVal, 0, sizeof(realVal));
    // memset(tempPre, 0, sizeof(tempPre));
    
    vector <int> storeCollision;
    N = 1;
    for (ii gap: gaps){
        storeCollision.push_back(gap.fi);
        // store.insert(gap.fi + 1);
        storeCollision.push_back(gap.se);
        storeCollision.push_back(gap.se + 1);
    }
    
    sort(storeCollision.begin(), storeCollision.end());
    storeCollision.push_back(-1);
    vector <int> store; 
    for (int i = 0; i < storeCollision.size() - 1; i++){
        if (storeCollision[i] != storeCollision[i + 1]){
            store.push_back(storeCollision[i]);
            N++;
        }
    }
    for (int i = 0; i <= N; i++){
        prefixNum[i] = {0,0};
        realVal[i] = tempPre[i] = 0;
    }
    unordered_map <int,int> conv;
    int cnt = 1;
    for (int i: store){
        conv[i] = cnt;
        realVal[cnt] = i;
        cnt++;
    }
    for (int i = 0; i < gaps.size(); i++){
        gaps[i].fi = conv[gaps[i].fi];
        gaps[i].se = conv[gaps[i].se];   
        tempPre[gaps[i].fi] += 1;
        tempPre[gaps[i].se + 1] -= 1;
    }
    prefixNum[0].fi = 0;
    prefixNum[0].se = 0;
    for (int i = 1, temp = 0; i <= N + 1; i++){
        temp += tempPre[i];
        prefixNum[i].fi = temp;
        prefixNum[i].se = prefixNum[i - 1].se + abs(realVal[i] - realVal[i - 1]) * prefixNum[i - 1].fi;
    }
    // cout << "Table: " << endl;
    // for (int i = 1; i <= N + 1; i++){
    //     cout << realVal[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= N + 1; i++){
    //     cout << prefixNum[i].fi << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= N + 1; i++){
    //     cout << prefixNum[i].se << " ";
    // }

    // cout << endl;
}

int cal(int i){
    if (i > prefixNum[N + 1].se){
        return 0;
    }
    i = prefixNum[N + 1].se - i + 1;
    int left = 1;
    int right = N + 1;
    int id = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        if (prefixNum[mid].se >= i){
            right = mid - 1;
        }
        else{
            left = mid + 1;
            id = mid;
        }
    }
    // cout << id << endl;
    int num = i - prefixNum[id].se;
    int where = (num - 1) / prefixNum[id].fi; 
    int ans = realVal[id] + where;

    return ans;
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
        // lists.clear();
        gaps.clear();
        cin >> n >> q;
        dataType L,R,Z;
        cin >> l[1] >> l[2] >> L.a >> L.b >> L.c >> L.m;
        cin >> r[1] >> r[2] >> R.a >> R.b >> R.c >> R.m;
        cin >> z[1] >> z[2] >> Z.a >> Z.b >> Z.c >> Z.m;
        for (int i = 3; i <= n; i++){
            l[i] = (L.a * l[i - 1] + L.b * l[i - 2] + L.c) % L.m;
            r[i] = (R.a * r[i - 1] + R.b * r[i - 2] + R.c) % R.m;
            if (i <= q){
                z[i] = (Z.a * z[i - 1] + Z.b * z[i - 2] + Z.c) % Z.m;
            }
        }
        for (int i = 1; i <= n; i++){
            if (l[i] > r[i]){
                swap(l[i], r[i]);
            }
            l[i]++;
            r[i]++;
            // for (int j = l[i]; j <= r[i]; j++){
            //     lists.push_back(j);
            // }
            gaps.push_back({l[i], r[i]});
            // cout << l[i] << " " << r[i] << endl;
        }
        prepare();
        // sort(lists.rbegin(), lists.rend());
        long long ans = 0;
        for (int i = 1; i <= q; i++){
            // cout << z[i] + 1 << endl;
            // (ans += cal(z[i] + 1) * i) %= mod;
            ans += (1ll * cal(z[i] + 1)) * i;
        }
        cout << ans << endl;
        // cout << cal(16);
    }
    return 0;
}

/*
0
0

*/
