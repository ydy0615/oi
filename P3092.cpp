#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 20
int a[N],b[N],c[M];
int f[N][M],dp[(1<<M)];
int main(){
	int m,n,l,r,mid,ma,ans=-1,sum=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>c[i];
		sum+=c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			l=i,r=n;
			while(l<r){
				mid=(l+r+1)>>1;
				if(b[mid]-b[i]<=c[j]){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
			//cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
			f[i][j]=l;
		}
	}
	dp[0]=0;
	for(int i=0;i<(1<<m);i++){
		ma=0;
		for(int j=0;j<m;j++){
			if(!(i&(1<<j))){
				dp[i+(1<<j)]=max(dp[i+(1<<j)],f[dp[i]][j+1]);
			}
			else ma+=c[j+1];
		}
		//cout<<i<<" "<<dp[i]<<endl;
		if(dp[i]==n) ans=max(ans,sum-ma);
	}
	cout<<ans<<endl;
	return 0;
}