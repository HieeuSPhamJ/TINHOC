#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

struct node{
    vector <int> ls;
    void add(int n){
        ls.push_back(n);
        sort(rall(ls));
        while (ls.size() > 2){
            ls.pop_back();
        } 
    }
    void merge(node a){
        for (auto i: a.ls){
            ls.push_back(i);
        }
        sort(rall(ls));
        while (ls.size() > 2){
            ls.pop_back();
        }
    }
};

node seg[maxN * 4];
node emp;

void print(node a, char en = endl){
    cout << "[";
    for (auto i: a.ls){
        cout << i << " ";
    }
    cout << "]" << en;
}

void build(int i, int l, int r){
    if (l > r){
        return;
    }
    // cout << l << ' ' << r << endl;
    if (l == r){
        seg[i].add(a[l]);
        // cout << l << " "<< r << endl;
        // print(seg[i]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    seg[i].merge(seg[2 * i]);
    seg[i].merge(seg[2 * i + 1]);
    
    // cout << l << " "<< r << endl;
    // cout << "->" << mid << endl;
    // print(seg[i]);

}



node get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return emp;
    }
    if (_left <= left and right <= _right){
        // cout << left << " " << right << endl;
        // print(seg[i]);
        return seg[i];
    }

    int mid = (left + right) / 2;

    node t1 = get(2 * i, left, mid, _left, _right);
    node t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    t1.merge(t2);
    // cout << left << " " << right << endl;
    // print(t1);
    return t1;
}

signed main(){
    freopen("rdat.INP", "r", stdin);
    freopen("rdat.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }   
    build(1,1,n);

    while(test--){
        int l, r;
        cin >> l >> r;
        // cout << "With: " << endl;
        node t = get(1,1,n,l,r);
        cout << t.ls[0] + t.ls[1] << endl;
    }

    return 0;
}