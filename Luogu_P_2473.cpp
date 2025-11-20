#include<bits/stdc++.h>
using namespace std;
double dp[110][(1<<15)];
int p[20];
bitset<20> b[20];
int v[20];
int main(){
	//memset(dp,-0x3f,sizeof(dp));
	int k,n;
	cin>>k>>n;
	for(int i=1,x;i<=n;i++){
		cin>>p[i];
		cin>>x;
		while(x!=0){
			b[i][x-1]=1;
			cin>>x;
		}
		v[i]=b[i].to_ullong();
	}
	for(int i=k;i>=1;i--){
		for(int j=0;j<(1<<n);j++){
			//if(dp[i][j]<0) continue;
			for(int k=1;k<=n;k++){
				if((j&v[k])==v[k]){
					dp[i][j]+=max(dp[i+1][j|(1<<(k-1))]+p[k],dp[i+1][j]);
				}
				else{
					dp[i][j]+=dp[i+1][j];
				}
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			dp[i][j]/=n;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
		//cout<<endl;
	}
	cout<<fixed<<setprecision(6)<<dp[1][0]<<endl;
	return 0;
}