#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(val) val.begin(), val.end()
#define rall(val) val.rbegin(), val.rend()
using namespace std;


const int inf = 1e18;
const int maxN = 1e6 + 10;

struct node{
    int i;
    int l;
    int r;
};

bool cmp(node a, node b){
    return a.r <= b.r;
}

int n, test;
node TEST[maxN];
vector <int> seg[maxN * 4];
int ans[maxN];
int a[maxN];

void create(int i, int l, int r){
    vector <int> temp;
    for(int j = l;j <= r; j++){
        temp.push_back(a[j]);
    }
    sort(all(temp));
    seg[i].swap(temp);
}

void build(int i,int l,int r){
    ans[i] = inf;
    create(i,l,r);
    if(l == r){
        return;
    }
    int mid=(l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
}

int lmao;

void change(int i, int l, int r, int id, int val){
    auto it = upper_bound(all(seg[i]), val);
    auto lit = upper_bound(all(seg[i]), val);
    lit--;
    int mid=(l + r) / 2;
    if (r <= id){
        if (it != seg[i].end() and ans[i] > *it - val){
            ans[i] = *it - val;
        }
        if (it != seg[i].begin() and ans[i] > val - *lit){
            ans[i] = val - *lit;
        }
        if (lmao <= ans[i]){
            return;
        }
        if (l == r){
            lmao = min(lmao, ans[i]);
            return;
        }
    }
    if (id > mid){
        change(2 * i + 1, mid + 1, r, id, val);
    }
    change(2 * i, l, mid, id, val);
    lmao = min(lmao, ans[i] = min({ans[i], ans[2 * i], ans[2 * i + 1]}));
}

int query(int i,int _l,int _r,int l,int r)
{
    int mid = (_l + _r) / 2;
    if(_l == l and _r == r){
        return ans[i];
    }
    /*
    l r 1
    1 2 3 4 4
    12  123
    => 1
    */
    if (l > mid){
        return query(2 * i + 1, mid + 1, _r, l, r);
    }
    if (r <= mid){
        return query(2 * i, _l, mid, l, r);
    }
    return min(query(2 * i, _l, mid, l, mid), query(2 * i + 1, mid + 1, _r, mid + 1, r));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= test; i++){
        TEST[i].i = i;
        cin >> TEST[i].l >> TEST[i].r;
    }

    sort(TEST + 1, TEST + 1 + test, cmp);
    build(1,1,n);

    vector <ii> res;
    int j = 1;
    for(int i = 2;i <= n; i++){
        lmao = 1e18;
        change(1, 1, n, i - 1, a[i]);
        while (j <= test and TEST[j].r <= i){
            int t = query(1, 1, n, TEST[j].l, i);
            res.push_back({TEST[j].i,t});
            j++;
        }
    }

    sort(all(res));

    for(auto i: res){
        cout << i.se << endl;
        // cout << TEST[i].i << " " << TEST[i].l << " " << TEST[i].r << endl;
    }

    return 0;
}