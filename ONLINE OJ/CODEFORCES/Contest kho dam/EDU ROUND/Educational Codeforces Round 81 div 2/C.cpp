#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        vector <int> a[50];
        string s, t;
        cin >> s >> t;

        for (int i = 0; i < s.length(); i++){
            a[s[i] - 'a'].push_back(i);
        }

        int count = 1;

        int last = -1;

        for (int i = 0; i < t.length();){
             if (a[t[i] - 'a'].empty()){
                count = -1;
                break;
             }
            int left = 0;
            int right = a[t[i] - 'a'].size() - 1;
            int tempAns = -1;

            // cout << "LIST: ";
            // for (auto x: a[t[i] - 'a']){
            //     cout << x << " ";
            // }
            // cout << endl;

            while(left <= right){
                int mid = (left + right) / 2;
                // cout << left << " " << mid << " " << right << endl;
                if (a[t[i] - 'a'][mid] > last){
                    tempAns = a[t[i] - 'a'][mid];
                }
                if (a[t[i] - 'a'][mid] <= last){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            // cout << t[i] << ": " << tempAns << endl << endl;
            if (tempAns == -1){
                last = -1;
                count++;
            }
            else{
                last = tempAns;
            
                i++;
            }
        }

        cout << count << endl;

    }
    return 0;
}