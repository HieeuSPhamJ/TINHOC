#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define iii pair<int,ii>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const double eps = 0.000001;
const int mod = 998244353;
const int N = 100001;
const int MATRIX_SIZE = 3;
int n,T[N],ans[4],ok1,ok2[4],l,r;
vector <int> xet;
int check(int x){
    int cnt=0;
    ans[1]=ans[2]=ans[3]=0;
    xet.clear();
    xet.push_back(T[1]);
    for (int i=2;i<=n;++i){
        if (T[i]-xet[0]>x){
            // int tam=;
            if (cnt==3) return false;
            ans[++cnt]=xet.back()+xet[0];
            // cout<<cnt<<' '<<xet.back()<<' '<<xet[0]<<endl;
            xet.clear();
        }
        xet.push_back(T[i]);
    }
    if (cnt==3&&!xet.empty()) return false;
    // cout<<xet.back()<<' '<<xet[0]<<endl;
    ans[3]=xet.back()+xet[0];
    return true;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>T[i];
    sort(T+1,T+n+1);
    l=0;
    r=2e9;
    // check(1);
    while (l<=r){
        int mid=l+r>>1;
//        cout<<mid<<endl;
        if (check(mid)){
            ok1=mid;
            ok2[1]=ans[1];
            ok2[2]=ans[2];
            ok2[3]=ans[3];
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ok1/2;
    if (ok1%2) cout<<".500000"<<endl;
    else cout<<".000000"<<endl;
//     // if ()
}
signed main() {
freopen("input.inp", "r", stdin);
freopen("A.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   
        solve();
}