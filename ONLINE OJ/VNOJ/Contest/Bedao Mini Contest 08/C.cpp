#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> v;
    char maze[101][101];
    int n, m;
    int test;
    cin>>n>>m;
    cin>>test;
    for (int i=0;i<n;i++) {
        for (int e=0;e<m;e++){
            cin>>maze[i][e];
        }
    }
    for (int i=1;i<n;i++) {
        int x=i,y=0;
        string s="";
        while (x<n && y<m) {
            s+=maze[x][y];
            x++; y++;
        }
        v.push_back(s); reverse(s.begin(),s.end());
        v.push_back(s);
    }
    for (int j=m-1;j>=0;j--) {
        int x=0,y=j;
        string s="";
        while (x<n && y<m) {
            s+=maze[x][y];
            x++; y++;
        }
        v.push_back( s ); reverse(s.begin(),s.end());
        v.push_back( s );
    }
    for (int i=1;i<n;i++) {
        int x=i,y=m-1;
        string s="";
        while (x<n && y<m) {
            s+=maze[x][y];
            x++; y--;
        }
        v.push_back(s); reverse(s.begin(),s.end());
        v.push_back(s);                
    }
    for (int i=0;i<m;i++) {
        int x=0,y=i;
        string s="";
        while (x<n && y<m) {
            s+=maze[x][y];
            x++; y--;
        }
        v.push_back(s); reverse(s.begin(),s.end());
        v.push_back(s);        
    }
    for (int i=0;i<n;i++) {
        v.push_back(maze[i]);
        string s=maze[i]; reverse(s.begin(),s.end());
        v.push_back(s);
    }
    for (int j=0;j<m;j++) {
        string s="";
        for (int i=0;i<n;i++) {
            s+=maze[i][j];
        }
        v.push_back( s ); reverse(s.begin(), s.end());
        v.push_back( s );
    }

    while (test--){
        string s;
        cin>>s;
        bool check=false;
        for (int i=0;i<v.size();i++) {
            if (v[i].find(s)<100) {
                cout<<"YES";
                check=true;
                break;
            }
        }
        if (!check) {
            cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
}
