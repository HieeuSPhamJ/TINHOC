/*
vl hàm sort ảo vl dùng nth_element ac:(((
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int maxN = 6e5 + 10;

int n;
int base = 0;
vector <int> a[(int)(6e5 + 10)];
int heap[(int)(6e5 + 10)];

long long check(int k){
    if (k < 1 or k > n){
        return 1e18;
    }
    int own = base;
    long long cost = 0;
    int len = 0;
    for (int t = 1; t < maxN; t++){
        for (int i = (int)a[t].size() - 1; i >= 0; i--){
            if (i >= k - 1){
                own++;
                cost += a[t][i];
            }
            else{
                len++;
                heap[len] = a[t][i];
            }
        }
    }
    if (own > k){
        return cost;
    }
    if (own == k){
        return cost;
    }
    int mid = k - own;
    nth_element(heap + 1, heap + mid + 1, heap + len + 1);
    for (int i = 1; i <= mid; i++){
        cost += heap[i];
        own++;
    }

    return cost;
}

void nenso(vector <ii> &ls){
    set <int> s;
    for (auto i: ls){
        s.insert(i.fi);
    }
    int cnt = 1;
    unordered_map <int,int> cnv;
    for (auto i: s){
        cnv[i] = cnt;
        cnt++;
        maxN = cnt;
    }
 
    for (auto &i: ls){
        i.fi = cnv[i.fi];
    }
}

signed main(){
    freopen("election.INP", "r", stdin);
    freopen("election.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int SUBTEST;
    cin >> SUBTEST;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }
    nenso(ls);
    for (auto i: ls){
        int x = i.fi;
        int c = i.se;
        if (x == 0 or c == 0){
            base++;
            continue;
        }
        a[x].push_back(c);
    }
    ls.clear();
    int l = base;
    int r = 0;
    for (int i = 1; i < maxN; i++){
        sort(rall(a[i]));
        r = max(r,(int)(a[i].size()) + 1);
    }
    r = min(r, n / 2 + n % 2);
    long long res = check(base);
    while(l <= r){
        int mid = l + (r - l) / 3;
        long long t = check(mid);
        res = min(res, t);
        if (t <= check(mid + 1)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    // cout << check(3) << endl;
    cout << res << endl;
    return 0;
}