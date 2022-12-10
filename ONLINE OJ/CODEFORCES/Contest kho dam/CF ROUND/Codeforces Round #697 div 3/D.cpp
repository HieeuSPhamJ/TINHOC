#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector <int> listOne;
        vector <int> listTwo;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            if (inp == 1){
                listOne.push_back(a[i]);
            }
            else{
                listTwo.push_back(a[i]);
            }
        }

        sort(listOne.rbegin(), listOne.rend());
        sort(listTwo.rbegin(), listTwo.rend());

        int ans = 0;
        int tempAns = 0;

        for (int i = 0, j = 0; i < (int)listOne.size() or j < (int)listTwo.size();){
            if (tempAns >= m){
                break;
            }
            if (i < (int)listOne.size()){
                ans++;
                tempAns += listOne[i];
                i++;
            }
            else if (j < (int)listTwo.size()){
                ans+=2;
                tempAns += listTwo[j];
                j++;
            }
            if (tempAns >= m){
                break;
            }
            if ((i - 2 >= 0) and (j < (int)listTwo.size()) and (listOne[i - 1] + listOne[i - 2] >= listTwo[j])){
                tempAns += listTwo[j];
                tempAns -= listOne[i - 1] + listOne[i - 2];
                i -= 2;
                j++;
            }

            if (tempAns >= m){
                break;
            }

        }
        if (tempAns < m){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}