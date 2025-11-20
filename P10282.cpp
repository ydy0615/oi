#include<bits/stdc++.h>
using namespace std;
#define N 510
#define mod 1000000007
#define eps 1e-6
int a[N],b[N],n;
double av[N][N],bv[N][N];
long long dp[N][N];
int sum[N][N];
pair<double,int> c1[N][N],c2[N][N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int as=0,bs=0;
		for(int j=i;j<=n;j++){
			as+=a[j];
			bs+=b[j];
			av[i][j]=1.0*as/(j-i+1);
			bv[i][j]=1.0*bs/(j-i+1);
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c1[i][j]={av[j][i],j};
			c2[i][j]={bv[j][i],j};
		}
		sort(c1[i]+1,c1[i]+1+i);
		sort(c2[i]+1,c2[i]+1+i);
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=i;k++){
				sum[j][k]=(sum[j][k-1]+dp[c1[i][k].second-1][j-1])%mod;
			}
		}
		for(int j=1;j<=n;j++){
			int t=1;
			for(int y=1;y<=j;y++){
				while(c1[i][t].first<=c2[j][y].first && t<=i) t++;
				dp[i][j]=(dp[i][j]+sum[c2[j][y].second][t-1])%mod;
			}
		}
	}
	cout<<dp[n][n]<<"\n";
	return 0;
}