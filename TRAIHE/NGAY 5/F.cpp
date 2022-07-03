#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
#define endl "\n"
using namespace std;

const int inf = 1e9;
const int maxN = 3 * 1e5 + 10;

struct iii{
    int l;
    int r;
    int id;
    iii(int a, int b, int c){
        l = a;
        r = b;
        id = c;
    }
};

int n, test;
int seg[maxN * 4];
vector <iii> lists;


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
 
    int mid = (left + right) / 2;
 
    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
 
    seg[i] = max(seg[2 * i + 1], seg[2 * i]);
    
}



int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }
 
        int mid = (left + right) / 2;
 
        return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}
 


bool cmp(iii a, iii b){
    if (a.l == b.l and a.r == b.r){
        // cout << "SAME";
        return a.id < b.id;
    }

    if (a.l > b.l){
        return !cmp(b, a);
    }

    if (b.r < a.r){
        return 0;
    }

    if (a.r == b.r){
        return 0;
    }
    // cout << a.l << " " << b.l - 1 << " " << a.r + 1 << " " << b.r << endl;
    return get(1, 1, n, a.l, b.l - 1) < get(1, 1, n, a.r + 1, b.r);    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;


    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        update(1, 1, n, i, inp);
    }

    for (int i = 1; i <= test; i++){
        int left;
        int right;
        cin >> left >> right;
        iii temp(left, right, i);
        lists.push_back(temp);
    }
    // iii d(2, 5, 9);
    // iii c(1, 3, 10);
    // int x = cmp(c, d);
    // cout << endl << x;

    sort(lists.begin(), lists.end(), cmp);

    for (auto i: lists){
        cout << i.id << " ";
    }
    

    

    return 0;
}