#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int> a[40];
int t[40];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,sum,vel,ans=0,b,c;
	char ch[34];
	int flg1=0,flg2=0;
	cin>>n>>m;
	b=0;
	for(int i=1;i<=m;i++){
		cin>>ch>>vel;
		sum=0;
		b=0;
		for(int j=0;j<n;j++){
			if(ch[n-j-1]=='1') b+=(1<<j);
			else if(ch[n-j-1]=='?') t[sum++]=j;
		}
		if(sum<16){
			for(int j=0,k;j<(1ll<<sum);j++){
				c=b;
				for(k=0;k<sum;k++) if(j&(1ll<<k)) c+=(1<<t[k]);
				for(int k=c;k>=1;k--){
					if(a[k][c]){
						ans-=a[k][c];
						break;
					}
				}
				a[i][c]=vel;
			}
			ans=ans+(1ll<<sum)*vel;
		}
		else{
			ans=(1ll<<n)*vel;
			for(int j=0,k;j<(1ll<<sum);j++){
				c=b;
				for(k=0;k<sum;k++) if((j&(1ll<<k))) c+=(1<<t[k]);
				for(int k=c;k>=1;k--){
					if(a[k][c]){
						ans-=a[k][c];
						break;
					}
				}
				a[i][c]=vel;
			}
			ans=ans+(1ll<<sum)*vel;
		}
	}
	cout<<ans<<"\n";
	return 0;
}