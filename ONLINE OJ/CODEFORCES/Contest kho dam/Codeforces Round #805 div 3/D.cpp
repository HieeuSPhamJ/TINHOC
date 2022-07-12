#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 2 * 1e5 + 10;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int w;
        cin >> w;
        int n = s.length();
        vector <ii> lists;

        int maxSum = 0;

        for (int i = 0; i < n; i++){
            int temp = s[i] - 'a' + 1;
            maxSum += temp;
            lists.push_back({temp, i});
            // cout << a[i] << ' ';
        }
        sort(lists.rbegin(), lists.rend());


        int id = 0;

        while(maxSum > w){
            maxSum -= lists[id].f;
            // cout << lists[id].s << ' ';
            s[lists[id].s] = ' ';
            id++;
        }

        if (maxSum == 0){
            cout << "";
        }
        else{
            for (int i = 0; i < n; i++){
                if (s[i] != ' '){
                    cout << s[i];
                }
            }
        }

        cout << endl;
    }
    return 0;
}