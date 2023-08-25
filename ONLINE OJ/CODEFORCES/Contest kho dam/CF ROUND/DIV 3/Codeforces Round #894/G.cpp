#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int a[maxN];
int te[maxN];
multiset <int> s;
multiset <int> st;

void cal(int i, int t){
    // auto it = s.find(a[i]);
    // int x = -1;
    // int y = -1;
    // if (it != s.begin()){
    //     it--;
    //     x = *it;
    //     it++;
    // }
    // it++;
    // if (it != s.end()){
    //     y = *it;
    // }

    auto it = s.find(a[i]);
    int x = -1;
    int y = -1;
    if(it != s.begin()){
        auto it1 = it;
        it1--;
        x = *it1;
    }
    auto it1 = it;
    it1++;
    if(it1 != s.end())
        y = *(it1);

    if (t == 0){
        if(x != -1)
                st.erase(st.find(a[i] - x));
            if(y != -1)
                st.erase(st.find(y - a[i]));
            if(x != -1 && y != -1)
                st.insert(y - x);
        it--;
        s.erase(it);
    }
    else{
        if(x != -1)
            st.insert(a[i] - x);
        if(y != -1)
            st.insert(y - a[i]);
        if(x != -1 && y != -1)
            st.erase(st.find(y - x));

    }
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
        int n;
        cin >> n;
        s.clear();
        st.clear();
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
            st.insert(a[i]);
        }
        int q;
        cin >> q;
        while(q--){
            int i, v;
            cin >> i >> v;
            cal(i,0);
            a[i] = v;
            s.insert(a[i]);
            cal(i,1);

            int ans = *(s.rbegin());
            int x = 0;
            if(st.size()){
                x = *st.rbegin();
            }
            cout << ans + x << " ";
        }
        cout << endl;
    }
    return 0;
}