#include<bits/stdc++.h>
using namespace std;
#define N 20
#define int long long
int a[N],v[N][N],dp[(1<<16)][20];
signed main(){
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(a[i]-a[j])>k){
				v[i][j]=1;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	for(int j=1;j<=n;j++){
		dp[(1<<(j-1))][j]=1;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(v[j][k] && !(i&(1<<(k-1)))){
					dp[i|(1<<(k-1))][k]+=dp[i][j];
					//cout<<(i|(1<<(k-1)))<<" "<<k<<" "<<i<<" "<<j<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=dp[(1<<n)-1][i];
	}
	cout<<ans<<endl;
	return 0;
}