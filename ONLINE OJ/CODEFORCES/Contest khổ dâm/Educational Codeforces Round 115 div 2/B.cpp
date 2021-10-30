#include <bits/stdc++.h>
using namespace std;

int day[6][1010];

int main(){
int test; cin>>test;
while(test--){
	int n; cin>>n;
	for (int i=1;i<=5;i++) day[i][0]=0;
	for (int i=1;i<=n;i++)
		for (int e=1;e<=5;e++){
			cin>>day[e][i];
			day[e][0]+=day[e][i];
		}
	// for (int i=0;i<=n;i++){
		// for (int e=1;e<=5;e++) cout<<day[e][i]<<' ';
		// cout<<endl;
	// }
	int check=0;
	for (int i=1;i<=5;i++){
		for (int e=i+1;e<=5;e++){
			// cout<<day[i][0]<<' '<<day[e][0]<<endl;
			if (day[i][0]>=n/2 and day[e][0]>=n/2){
				// cout<<"#";
				int count=0;
				for (int x=1;x<=n;x++){
					// cout<<day[i][x]<<' '<<day[e][x]<<endl;
					if (day[i][x]==1 or day[e][x]==1){
						count++;
					}
				}
				if (count==n) check=1;
			}
			// if (check) break;
		}
		// if (check) break;
	}
	if (check) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	
}
return 0;
}