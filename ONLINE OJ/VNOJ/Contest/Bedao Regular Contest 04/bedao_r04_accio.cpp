#include<bits/stdc++.h>
using namespace std;



int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    
    int c = s1[0];
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < min(s1.size(), s2.size()); i++){
        count1 += (s1[i] == c);
        count2 += (s2[i] == c);
    }
    if (s1.size() != s2.size() or count1 != count2){
        cout << -1;
    }
    else{
        int n = s1.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            
            if (s1[i] != s2[i]){
                for (int j = 1; i + j < n; j++){
                    if (s1[i + j] != s2[i + j]){
                        count += j;
                        swap(s1[i + j], s1[i]);
                        break;
                    }
                }
            }
            // cout << s1 << endl;
            
        }
        cout << count;
    }


    return 0;
}