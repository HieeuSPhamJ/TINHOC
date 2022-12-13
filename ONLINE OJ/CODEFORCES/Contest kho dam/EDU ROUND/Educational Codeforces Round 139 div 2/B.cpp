#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1000000531;
const int base = 256;


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
        string s;
        cin >> s;

        if (n == 2){
            cout << "NO" << endl;
            continue;
        }
        map <string, int> cnt;
        int check = 0;
        deque <string> lists;
        lists.push_back("");
        for (int i = 0; i < n - 1; i++){
            if (lists.size() >= 2){
                // cout << lists.front() << endl;
                cnt[lists.front()]++;
                lists.pop_front();
            }
            string t = s.substr(i,2);
            lists.push_back(t);
            // cout << "ASK: " << t << endl;
            if (cnt[t] != 0){
                check = 1;
                break;
            }
        }

        if (check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}