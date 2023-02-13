#include<bits/stdc++.h>
#define ii pair <double,double>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define iii pair <ii,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;



struct line{
    double a, b;
    int id;
    line(double _a,double _b, int _id){
        a = _a;
        b = _b;
        id = _id;
    }
    double val(int x){
        return a * x + b;
    }
};
 
vector<line> st;

struct CHT{
 
    bool sus(line d1,line d2,line d3){
        // cout << d1.id << " " << d2.id << " " << d3.id << endl;
        // cout << (d3.b - d1.b) / (d1.a - d3.a) << " " << (d2.b - d1.b) / (d1.a - d2.a) << endl;
        return  (d3.b - d1.b) / (d1.a - d3.a) > (d2.b - d1.b) / (d1.a - d2.a);
    }
    void add(line x){
        // cout << x.a << " " << x.b << " " << x.id << endl;
        while(st.size()>1 and sus(st[st.size()-2],st.back(),x)){
            // cout << st.back().id << endl;
            st.pop_back();
        }
        st.push_back(x);
    }
    int query(int x){
        int l = 0;
        int r = st.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            int now = st[mid].val(x);
            ans = st[mid].id;
            // cout << mid << " " << ans << endl;
            if (mid != 0 and now > st[mid-1].val(x)){
                r = mid - 1;    
            }
            else if (mid + 1 != st.size() and now > st[mid+1].val(x)){
                l = mid + 1;
            }
            else{
                if (mid != 0 and now == st[mid-1].val(x)){
                    ans = min(ans,st[mid - 1].id);  
                }
                else if (mid + 1 != st.size() and now == st[mid+1].val(x)){
                    ans = min(ans,st[mid + 1].id);  
                }
                break;
            }
        }
        return ans;
    }
};

bool cmp(iii a, iii b){
    return a.fi.se - a.fi.fi >= b.fi.se - b.fi.fi;
}

signed main(){
    // freopen("bus.INP", "r", stdin);
    // freopen("bus.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector <iii> lists;
    for (int i = 1; i <= n; i++){
        double a, b;
        cin >> a >> b;
        lists.push_back({{a,b},i});
    }
    sort(all(lists),cmp);

    CHT c;

    for (auto i: lists){
        c.add(line((i.fi.se - i.fi.fi) / l, i.fi.fi, i.se));
    }

    vector <ii> query;
    int test;
    cin >> test;
    while(test--){
        int x;
        cin >> x;
        query.push_back({x,test});
    }
    sort(all(query));

    int j = 0;
    vector <ii> ans;

    for (auto i: query){   
        int res = st[j].id;
        int x = i.fi;
        // cout << "With: " << x << endl;
        while(j + 1 < st.size() and st[j + 1].val(x) <= st[j].val(x)){
            if (st[j + 1].val(x) == st[j].val(x)){
                j++;
                res = min(res, st[j + 1].id);
            }
            // cout << 
            res = st[j + 1].id;
            j++;
        }
        // cout << x << " " << res << endl;
        ans.push_back({i.se,res});
    }

    sort(rall(ans));
    for (auto i: ans){
        cout << i.se << endl;
    }

    return 0;
}
