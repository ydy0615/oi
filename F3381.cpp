#include<bits/stdc++.h>
using namespace std;
#define N 2010
int a[N],b[N],f[N][40010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,T,n,m,ma,ans,sum;
	cin>>C>>T;
	while(T--){
		memset(f,0,sizeof(f));
		cin>>n>>m;
		ma=m;
		ans=0;
		for(int i=1;i<n;i++){
			cin>>a[i]>>b[i];
			ma=max({ma,a[i]+b[i]});
		}
		for(int i=0;i<m;i++) f[1][i]=i;
		for(int i=1;i<n;i++){
			sum=0;
			for(int j=0;j<ma;j++){
				if(j>=a[i]+b[i]) f[i+1][j]=max(f[i+1][j],f[i][j]);
				else if(j>=a[i]) f[i+1][j-a[i]]=max(f[i+1][j-a[i]],f[i][j]);
				else{
					f[i+1][j+b[i]]=max(f[i+1][j+b[i]],f[i][j]+b[i]);
					sum=max(sum,f[i][j]);
				}
			}
			for(int j=0;j<b[i];j++){
				f[i+1][j]=max(sum+j,f[i+1][j]);
			}
		}
		for(int i=0;i<ma;i++) ans=max(ans,f[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}