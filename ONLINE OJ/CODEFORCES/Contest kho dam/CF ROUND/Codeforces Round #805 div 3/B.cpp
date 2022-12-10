#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;

        int i = 0;
        int countDay = 0;
        int cha[40];
        memset(cha, 0, sizeof(cha));
        int count = 0;
        while(i < s.length()){
            if (count == 0){
                countDay++;
            }
            if (cha[s[i] - 'a'] == 0){
                count++;
                cha[s[i] - 'a'] = 1;
            }
            // cout << s[i] - 'a' << " " << count << " " <<countDay << endl;
            if (count > 3){
                count = 0;
                memset(cha, 0, sizeof(cha));
                
                continue;
            }
            i++;
        }
        cout << countDay << endl;
    }
    return 0;
}