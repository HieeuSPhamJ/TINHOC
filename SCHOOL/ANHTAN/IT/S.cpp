#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

multiset <int> seg[maxN * 4];
multiset <int> add[maxN * 4];
multiset <int> del[maxN * 4];



void updateadd(int i, int l, int r, int index, int val){
    if (index < l or r < index){
        return;
    }
    if (l == r){
        seg[i].insert(val);
        add[i].insert(val);
        return;
    }
    int mid = (l + r) / 2;

    updateadd(2 * i, l, mid, index, val);
    updateadd(2 * i + 1, mid + 1, r, index, val);

    for (auto x: add[2 * i]){
        seg[i].insert(x);
        add[i].insert(x);
    }
    add[2 * i].clear();
    for (auto x: add[2 * i + 1]){
        seg[i].insert(x);
        add[i].insert(x);
    }
    add[2 * i + 1].clear();
}

void updatedel(int i, int l, int r, int index, int val){
    if (index < l or r < index){
        return;
    }
    if (l == r){
        auto it = seg[i].find(val);
        if (it != seg[i].end()){
            seg[i].erase(it);
            del[i].insert(val);
        }
        return;
    }
    int mid = (l + r) / 2;

    updatedel(2 * i, l, mid, index, val);
    updatedel(2 * i + 1, mid + 1, r, index, val);

    for (auto x: del[2 * i]){
        seg[i].erase(seg[i].find(x));
        del[i].insert(x);
    }
    del[2 * i].clear();
    for (auto x: del[2 * i + 1]){
        seg[i].erase(seg[i].find(x));
        del[i].insert(x);
    }
    del[2 * i + 1].clear();
}

int get(int i, int l, int r, int L, int R, int k){
    if (R < l or r < L){
        return inf;
    }

    auto it = seg[i].upper_bound(k);
    if (it == seg[i].end()){
        return inf;
    }

    if (l == r){
        // cout << l << ' ' << r << endl;
        return l;
    }


    int mid = (l + r) / 2;

    int t = get(2 * i + 1, mid + 1, r, L, R, k);
    // cout << mid + 1 << ' ' << r << " " << t << endl;
    if (t != inf){
        return t;
    }
    t = get(2 * i, l, mid, L, R, k);
    // cout <<l << ' ' << mid << " " << t << endl;
    return t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, test;
    cin >> n >> test;
    while(test--){
        int type;
        cin >> type;
        if (type == 1){
            int i, v;
            cin >> i >> v;
            updateadd(1,1,n,i,v);
        }
        else if (type == 2){
            int i, v;
            cin >> i >> v;
            updatedel(1,1,n,i,v);
        }
        else{
            int l, r, v;
            cin >> l >> r >> v;
            int t = get(1,1,n,l,r,v);
            if (t == inf){
                cout << "NONE" << endl;
                continue;
            }
            cout << t << endl;
        }

    }

    return 0;
}
