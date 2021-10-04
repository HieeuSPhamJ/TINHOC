#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q; cin>>q;
    while(q--){
    	string ax,ay;
    	int bx,by;
    	cin>>ax>>bx>>ay>>by;
		int x=ax.length()+bx;
		int y=ay.length()+by;
		if (x>y) cout<<"X > Y";
		else if (x<y) cout<<"X < Y";
		else {
			for (int i=1;i<=x;i++){
				char xi=ax[i];
				char yi=ay[i];
				if (xi>yi) cout<<"X > Y";
				else if (xi<yi) cout<<"X < Y";
		
			}
		}
    	cout<<endl;
    }
    
    return 0;
}