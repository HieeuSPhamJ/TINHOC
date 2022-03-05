#include<bits/stdc++.h>
using namespace std;

int v, e;
vector <pair<int,int>> vect;

int main(){
    cin >> v >> e;
    for (int i = 1; i <= e; i++){
        int a, b;
        cin >> a >> b;
        if (a < b){
            vect.push_back({a, b});
        }
        else{
            vect.push_back({b, a});
        }

    }
    sort(vect.begin(), vect.end());
    // for (int i = 0; i < e; i++){
    //     cout << vect[i].first << ' ' << vect[i].second << endl;
    // }
    int count = 0;
    for (int i = 0; i < e - 1; i++){
        for (int j = i + 1; j <= e; j++){
            pair<int,int> e1 = vect[i];
            pair<int,int> e2 = vect[j];
            if (e1.first == e2.first){
                pair<int,int> newE;
                if (e1.second < e2.second){
                    newE = {e1.second, e2.second};
                }
                else{
                    newE = {e2.second, e1.second};
                }
                // for (int x = 0; x < e; x++){
                //     pair<int,int> tempE = vect[x];
                //     if (newE == tempE){
                //         count++;
                //         // cout << e1.first << ' ' << e1.second << ' ' << e2.second << endl;
                //     }
                // }
                int left = 0;
                int right = e - 1;
                while(left <= right){
                    int mid = (left + right) / 2;
                    pair<int,int> tempE = vect[mid];
                    if (newE == tempE){
                        count++;
                        // cout << e1.first << ' ' << e1.second << ' ' << e2.second << endl;
                    }
                    if (tempE < newE){
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }
            }
            else{
                break;
            }
        }
    }
    cout << count;
    return 0;
}