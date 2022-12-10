#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        deque <int> lists;
        for (int i = 0; i < s.size(); i++){
            lists.push_back(s[i] - 'a');
        }
        vector <int> a[3];
        
        bool turn = 0;

        while(!lists.empty()){
            if (lists.back() > lists.front()){
                a[turn].push_back(lists.front());
                lists.pop_front();
            }
            else if (lists.back() < lists.front()){
                a[turn].push_back(lists.back());
                lists.pop_back();
            }
            else {
                if (lists.size() >= 4){
                    if (lists[lists.size() - 2] > lists.front()){
                        a[turn].push_back(lists.front());
                        lists.pop_front();
                    }
                    else if (lists.back() < lists[1]){
                        a[turn].push_back(lists.back());
                        lists.pop_back();
                    }
                    else{   
                        a[turn].push_back(lists.back());
                        lists.pop_back();
                    }
                }
                else{
                    a[turn].push_back(lists.back());
                    lists.pop_back();
                }
            }
            turn = !turn;
        }

        int check = -1;
        for (int i = 0; i < a[0].size(); i++){
            if (a[0][i] == a[1][i]){
                continue;
            }
            else if (a[0][i] > a[1][i]){
                check = 1;
                break;
            }
            else{
                check = 0;
                break;
            }
        }

        if (check == -1){
            cout << "Draw";
        }
        else if (check == 0){
            cout << "Alice";
        }
        else{
            cout << "Bob";
        }
        cout << endl;

    }
    return 0;
}