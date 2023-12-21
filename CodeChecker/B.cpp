#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n;
int cong = 0;
int tru = 0;
int khong = 0;

int cal(string s){
    int res = 0;
    for (int i = 1, x = 0; i <= n; i++){
		if (s[i] == '+'){
            x++;
        }
        if (s[i] == '-'){
            x--;
        }
        res += x;
		if (x < 0){
            return -1;
        }
    }
    return res;
}

int pre[maxN];

int calmin(string s){
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        if (s[i] == '+'){
            pre[i]++;
        }
        else if (s[i] != '0'){
            pre[i]--;
        }
        
    }

    priority_queue <int> last;

    for (int i = 1, x = 0; i <= n; i++){
        if (s[i] == '_'){
            last.push(i);
            last.push(i);
            s[i] = '-';
        }
        while(pre[i] + x < 0){
            if (last.size() == 0){
                return -1;
            }
            int t = last.top();
            last.pop();
            x++;
            if (s[t] == '-'){
                s[t] = '0';
            }
            else{
                s[t] = '+';
            }
            // cout << i << ": " << t << endl;
        }
    }

    int res = cal(s);

    return res;
}

int calmax(string s){
    for (int i = 1; i <= n; i++){
        if (s[i] == '+'){
            cong++;
        }
        if (s[i] == '-'){
            tru++;
        }
        if (s[i] == '0'){
            khong++;
        }
    }
	int summax = (n - khong - (n + khong) % 2) / 2;
	cong = summax - cong;
    // cout << summax << " " << cong << endl;
    for (int i = 1, ok = (n + khong) % 2; i <= n; i++){
        if (s[i] == '_'){
            if (cong){
                s[i] = '+';
                cong--;
            }
            else{
                if (ok){
                    s[i] = '0';
                    ok = 0;
                }
                else{
                    s[i] = '-';
                }
            }
        }
        // cout << s[i];
    }
    // cout << s << endl;
    int res = cal(s);
    return res;
}
/*
+++_---
*/


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("B.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    n = s.length();
    s = ' ' + s;
    int mi = calmin(s);
    int ma = calmax(s);
    // cout << mi << " " << ma << endl;
    if (mi == -1 or ma == -1){
        cout << "NIE" << endl;
        return 0;
    }

    cout << mi << " " << ma << endl;
    return 0;
}