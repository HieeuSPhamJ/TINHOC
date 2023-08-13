#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


multiset <int> ls;
multiset <int> lsDiff;


void insert(int x){
    if (ls.empty()){
        ls.insert(x);
        return;
    }
    if (x < *ls.begin()){
        lsDiff.insert(abs(*ls.begin() - x));
        ls.insert(x);
        return;
    }
    if (*ls.rbegin() < x){
        lsDiff.insert(abs(*ls.rbegin() - x));
        ls.insert(x);
        return;
    }
    auto it = ls.upper_bound(x);
    int r = *it;
    it--;
    int l = *it;
    lsDiff.erase(lsDiff.find(abs(r - l)));
    lsDiff.insert(abs(r - x));
    lsDiff.insert(abs(l - x));
    ls.insert(x);
}

void erase(int x){
    auto it = ls.find(x);
    if (ls.size() == 1){
        ls.erase(it);
        return;
    }
    if (it == ls.begin()){
        ls.erase(it);
        lsDiff.erase(lsDiff.find(abs(x - *ls.begin())));
        return;
    }
    if (*it == *ls.rbegin()){
        ls.erase(it);
        lsDiff.erase(lsDiff.find(abs(x - *ls.rbegin())));
        return;
    }
    ls.erase(it);
    it = ls.upper_bound(x);
    int r = *it;
    it--;
    int l = *it;
    lsDiff.erase(lsDiff.find(abs(r - x)));
    lsDiff.erase(lsDiff.find(abs(l - x)));
    lsDiff.insert(abs(r - l));
}

int get(){
    if (ls.size() <= 2){
        return 0;
    }
    return (*ls.rbegin() - *ls.begin()) - *lsDiff.rbegin();
}

void print(){
    cout << "---##---" << endl;
    for (auto i: ls){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: lsDiff){
        cout << i << " ";
    }
    cout << endl;
    cout << "--------" << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    while(n--){
        int x;
        cin >> x;
        insert(x);
    }
    // print();
    cout << get() << endl;
    while(test--){
        int t;
        cin >> t;
        int x;
        cin >> x;
        if (t == 1){
            insert(x);
        }
        else{
            erase(x);
        }
        // print();
        cout << get() << endl;
    }
    return 0;
}