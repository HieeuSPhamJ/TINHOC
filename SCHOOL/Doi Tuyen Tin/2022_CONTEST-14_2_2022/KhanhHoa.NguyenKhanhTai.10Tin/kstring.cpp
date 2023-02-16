#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define TASKNAME "kstring"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
typedef vector<int> vi;
string str;
int len,d;
int dist(string x,string y){
    int dem = 0;
    for(int i=0;i<x.length();i++){
        if (x[i] != y[i]) dem++;
    }
    return dem;
}
int solve(vector<string> st){
         int dem=0;
         for(int i=0;i<st.size()-1;i++){
            for(int j=i+1;j<st.size();j++){
                if (dist(st[i],st[j]) <= d) dem++;
            }
         }
         return dem;
}

main(){

     ios_base::sync_with_stdio(NULL);
     cin.tie(NULL);
     cout.tie(NULL);
     freopen(TASKNAME".inp","r",stdin);
     freopen(TASKNAME".out","w",stdout);
     cin>>len>>d;
     cin>>str;
     int turn = 0;
     for(int i=1;i<=len;i++){
         vector<string> st;
         string tmp = "";
         for(int j=0;j<str.length();j++){
            tmp = tmp + str[j];
            if (tmp.size()==i) {
                st.pb(tmp);
                tmp = "";
            }
         }
         int ans = solve(st);
         cout<<ans<<' ';
         if (ans==0 || len/i<2) {
            turn = i;
            break;
         }
     }
     for(int i=turn+1;i<=len;i++){
        cout<<0<<' ';
     }
}

