#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

int n, k;
ii seg[4 * maxN];
int a[maxN];

void update(int i, int l, int r, int id, ii v){
    if (id < l or r < id){
        return;
    }
    // cout << l << " " << r << endl;
    if (l == r){
        seg[i] = v;
        return;
    }

    int mid = (l + r) / 2;

    update(2 * i, l, mid, id, v);
    update(2 * i + 1, mid + 1, r, id, v);
    
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

void update(int i, ii v){
    update(1, 1, n, i, v);
}

ii get(int i, int l, int r, int L, int R){
    if (R < l or r < L){
        return {-1,-1};
    }
    if (L <= l and r <= R){
        return seg[i];
    }
    int mid = (l + r) / 2;
    return max(get(2 * i, l, mid, L, R), get(2 * i + 1, mid + 1, r, L, R));
}

ii get(int l, int r){
    return get(1,1,n,l,r);
}


signed main(){
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - '0';
        update(i,{a[i],-i});
    }
    int last = 1;
    while(k){
        int t = -get(1,1,n,last, last + k).se;
        // cout << last << " " << t << endl;
        
        for (last; last < t; last++){
            a[last] = -1;
            k--;
        }
        if (last == t){
            last++;
        }
        if (last >= n){
            break;
        }
    }
    priority_queue <ii,vector <ii>, greater <ii>> q;
    for (int i = 1; i <= n; i++){
        if (a[i] == -1){
            continue;
        }
        q.push({a[i], i});
    }
    while(k--){
        a[q.top().se] = -1;
        q.pop();
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == -1){
            continue;
        }
        cout << a[i];
    }
    return 0;
}