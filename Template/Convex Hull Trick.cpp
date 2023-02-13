#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


struct line{
    int a, b;
    line(int _a,int _b){
        a = _a;
        b = _b;
    }
    int val(int x){
        return a * x + b;
    }
};
 
struct CHT{
    vector<line> st;
 
    bool sus(line d1,line d2,line d3){
        return  (double)(d3.b - d1.b) / (d1.a - d3.a) <= (double)(d2.b - d1.b) / (d1.a - d2.a);
    }
    void add(line x){
        while(st.size()>1 and sus(st[st.size()-2],st.back(),x))
            st.pop_back();
        st.push_back(x);
    }
    int query(int x){
        int l = 0;
        int r = st.size()-1;
        int ans = 1e18;
        while(l <= r){
            int mid = (l + r) / 2;
            int now = st[mid].val(x);
            ans = min(ans, now);
            if (mid != 0 and now > st[mid-1].val(x)){
                r = mid - 1;
            }
            else if (mid + 1 != st.size() and now > st[mid+1].val(x)){
                l = mid + 1;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}