#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define inf 0x3f3f3f3f
int c[N],d[N];
double p[N];
int dis[N][N];
double dp[N][N][2];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	int n,m,v,e;
	double ans=inf;
	cin>>n>>m>>v>>e;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=v;i++) dis[i][i]=0;
	for(int i=1,u,v,w;i<=e;i++){
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j][0]=dp[i][j][1]=inf;
		}
	}
	dp[1][0][0]=0;
	dp[1][1][1]=0;
	for(int i=2;i<=n;i++){
		for(int j=0,tmp;j<=m;j++){
			dp[i][j][0]=min({
				dp[i-1][j][0]+dis[c[i]][c[i-1]],
				dp[i-1][j][1]+dis[c[i]][d[i-1]]*p[i-1]+dis[c[i]][c[i-1]]*(1-p[i-1]),
			});
			if(j!=0){
				dp[i][j][1]=min({
					dp[i-1][j-1][0]+dis[d[i]][c[i-1]]*p[i]+dis[c[i]][c[i-1]]*(1-p[i]),
					dp[i-1][j-1][1]+(dis[d[i]][d[i-1]]*p[i-1]+dis[d[i]][c[i-1]]*(1-p[i-1]))*p[i]
					+(dis[c[i]][d[i-1]]*p[i-1]+dis[c[i]][c[i-1]]*(1-p[i-1]))*(1-p[i]),
				});
			}
		}
	}
	for(int j=0,tmp;j<=m;j++){
		ans=min({ans,dp[n][j][0],dp[n][j][1]});
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}