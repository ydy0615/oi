#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define int long long
int x[N],y[N];
pair<int,int> a[N];
signed main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		int flag=1;
		for(int i=0;i<32;i++){
			for(int j=1;j<=n;j++){
				a[j].first=x[j]%(1ll<<i);
				a[j].second=y[j]%(1ll<<i);
				//cout<<i<<" "<<j<<" "<<a[i].first<<" "<<a[i].second<<" "<<(1ll<<i)<<"\n";
			}
			sort(a+1,a+n+1);
			int flg=1;
			for(int j=1;j<n;j++){
				if(a[j].first==a[j+1].first && a[j+1].second!=a[j].second){
					flg=0;
					break;
				}
			}
			if(!flg){
				flag=0;
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}