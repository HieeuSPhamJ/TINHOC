#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--){
    	int n; cin>>n;
    	while(n--){
    		char inp;
    		cin>>inp;
    		if (inp == 'L') cout<<'L';
    		else if (inp == 'R') cout<<'R';
    		else if (inp == 'D') cout<<'U';
    		else if (inp == 'U') cout<<'D';
    	}
		cout<<endl;
    }
    return 0;
}