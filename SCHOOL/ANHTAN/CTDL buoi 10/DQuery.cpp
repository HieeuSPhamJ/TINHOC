#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define ii pair <int,int>
#define f first
#define s second
#define st set<int>
using namespace std;

const int maxN = 2 * 1e5 + 10;

st seg[maxN];
st emptySet;

void update(int i, int left, int right, int index, int val){
    // cout << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        seg[i].insert(val);
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    if (seg[2 * i].size() > seg[2 * i + 1].size()){
        seg[i] = seg[2 * i];
        seg[i].insert(seg[2 * i + 1].begin(), seg[2 * i + 1].end());
        return;
    }
    seg[i] = seg[2 * i + 1];
    seg[i].insert(seg[2 * i].begin(), seg[2 * i].end());
    

}

st getSet(int i, int left, int right, int _left, int _right){
    // cout << left << ' ' << right << endl;
    if (right < _left or _right < left){
        return emptySet;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    st tempSet1 = getSet(2 * i, left, mid, _left, _right);
    st tempSet2 = getSet(2 * i + 1, mid + 1, right, _left, _right);
    
    if (tempSet1.size() > tempSet2.size()){
        tempSet1.insert(tempSet2.begin(), tempSet2.end());
        return tempSet1;
    }
    tempSet2.insert(tempSet1.begin(), tempSet1.end());
    return tempSet2;
    
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        // cout << i << endl;
        int inp;
        cin >> inp;
        update(1, 1, n, i, inp);
        
    }

    int test;
    cin >> test;

    // cout << test << endl;

    while (test--){
        int a, b;
        cin >> a >> b;
        cout << getSet(1, 1, n, a, b).size() << endl;
    }
    

    return 0;
}