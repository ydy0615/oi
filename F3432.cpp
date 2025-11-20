#include<bits/stdc++.h>
#define N 210
using namespace std;
int T,n;
map<int,int> t[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1,x;j<=n;j++){
				cin>>x;
				t[i+j][x]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1,x;j<=n;j++){
				cin>>x;
				t[i+j][x]--;
			}
		}
		bool flag=1;
		for(int i=1;i<=2*n;i++){
			for(auto p:t[i]) flag&=(p.second==0);
			t[i].clear();
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}