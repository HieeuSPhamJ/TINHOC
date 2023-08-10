#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

struct node{
    int leftNode, rightNode, left, right, val;
};

vector <node> seg;

void build(int i){
    if (seg[i].left == seg[i].right){
        seg[i].val = 0;
        return;
    }   
    int mid = (seg[i].left + seg[i].right) / 2;

    if (seg[i].leftNode == -1){
        seg[i].leftNode = seg.size();
        seg.push_back({-1,-1,seg[i].left,mid,0});
    }
    if (seg[i].rightNode == -1){
        seg[i].rightNode = seg.size();
        seg.push_back({-1,-1,mid + 1,seg[i].right,0});
    }

    build(seg[i].leftNode);
    build(seg[i].rightNode);
    seg[i].val = seg[seg[i].leftNode].val + seg[seg[i].rightNode].val;
}

void update(int i, int id, int oldI, int val){
    if (seg[i].left == seg[i].right){
        seg[i].val = val;
        return;
    }   
    int mid = (seg[i].left + seg[i].right) / 2;

    if (id <= mid){
        seg[i].leftNode = seg.size();
        seg[i].rightNode = seg[oldI].rightNode;
        seg.push_back({-1,-1,seg[i].left, mid,0});
        update(seg[i].leftNode,id,seg[oldI].leftNode,val);
    }
    else{
        seg[i].leftNode = seg[oldI].leftNode;
        seg[i].rightNode = seg.size();
        seg.push_back({-1,-1,mid + 1,seg[i].right,0});
        update(seg[i].rightNode,id,seg[oldI].rightNode,val);
    }
    
    seg[i].val = seg[seg[i].leftNode].val + seg[seg[i].rightNode].val;
}

int get(int i, int l, int r){
    if (r < seg[i].left or seg[i].right < l){
        return 0;
    }
    if (l <= seg[i].left and seg[i].right <= r){
        return seg[i].val;
    }

    return get(seg[i].leftNode, l, r) + get(seg[i].rightNode, l, r);
}

int version[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    int countVersion = 0;
    seg.push_back({-1,-1,1,n,0});
    build(0);
    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            countVersion++;
            version[countVersion] = seg.size();
            seg.push_back({-1,-1,1,n,0});
            int i, v;
            cin >> i >> v;
            update(version[countVersion],i,version[countVersion - 1],v);
        }
        else{
            int ver, l, r;
            cin >> ver >> l >> r;
            cout << get(version[ver],l,r) << endl;
        }
    }
    return 0;
}