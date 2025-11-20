#include<bits/stdc++.h>
using namespace std;
int dp[130][1<<10][1<<10],w[130],th[130];
int s,n,m;
int main(){
	while(cin>>s>>m>>n && s){
		memset(dp,0x3f,sizeof(dp));
		memset(w,0,sizeof(w));
		memset(th,0,sizeof(th));	
		int s1=0,s2=0,sum=0;
		for(int i=1,t,x;i<=m;i++){
			cin>>t;
			sum+=t;
			x=0;
			while(1){
				cin>>x;
				if(s1&(1<<(x-1))) s2|=1<<(x-1);
				s1|=1<<(x-1);
				char c=getchar();
				if(c=='\n') break;
			}
		}
		dp[0][s1][s2]=sum;
		for(int i=1,t,x;i<=n;i++){
			cin>>t;
			w[i]=t;
			x=0;
			while(1){
				cin>>x;
				th[i]|=1<<(x-1);
				char c=getchar();
				if(c=='\n') break;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<s);j++){
				int k=j;
				dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				int s1=j|th[i+1],s2=k|(j&th[i+1]);
				dp[i+1][j|th[i+1]][k|(j&th[i+1])]=min(dp[i+1][j|th[i+1]][k|(j&th[i+1])],dp[i][j][k]+w[i+1]);
				k=((k-1)&j);
				while(k!=j){
					dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
					dp[i+1][j|th[i+1]][k|(j&th[i+1])]=min(dp[i+1][j|th[i+1]][k|(j&th[i+1])],dp[i][j][k]+w[i+1]);
					k=((k-1)&j);
				}
			}
		}
		cout<<dp[n][(1<<s)-1][(1<<s)-1]<<"\n";
	}
	return 0;
}