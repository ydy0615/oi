#include<bits/stdc++.h>
using namespace std;
#define N 20
#define eps 1e-6
double x[N],y[N];
int f[N][N],dp[1<<20];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(dp,0x3f,sizeof(dp));
		int n,a;
		cin>>n>>a;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double x_1=x[i],y_1=y[i],x_2=x[j],y_2=y[j];
				double a1=(y_2-(y_1*x_2)/x_1)/(x_2*x_2-x_2*x_1);
				double b1=(y_1-a1*x_1*x_1)/x_1;
				if(a1>=-eps){
					f[i][j]=0;
					continue;
				}
				int tmp=0;
				for(int k=1;k<=n;k++){
					if(fabs(x[k]*x[k]*a1+b1*x[k]-y[k])<=eps){
						tmp+=(1<<(k-1));
					}
				}
				f[i][j]=tmp;
			}
		}
		dp[0]=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1);
				for(int k=j+1;k<=n;k++){
					dp[i|f[j][k]]=min(dp[i|f[j][k]],dp[i]+1);
				}
			}
		}
		cout<<dp[(1<<n)-1]<<"\n";
	}
	return 0;
}