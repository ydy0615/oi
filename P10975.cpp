#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a[20][1<<12];
int c[20][1<<12],dp[20][1<<12];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cnt,flg,h,w;
	for(int i=1;i<=11;i++){
		for(int j=0;j<(1<<i);j++){
			cnt=0,flg=1;
			for(int k=0;k<i;k++){
				if(j&(1<<k)){
					if(cnt&1){
						flg=0;
						break;
					}
					cnt=0;
				}
				else cnt++;
			}
			if(cnt&1) flg=0;
			if(flg) c[i][j]=1;
		}
		for(int j=0;j<(1<<i);j++){
			for(int k=0;k<(1<<i);k++){
				if((!(j&k)) && c[i][j|k]){
					a[i][j].push_back(k);
				}
			}
		}
	}
	
	while(1){
		cin>>h>>w;
		if(h==0 && w==0) break;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=h;i++){
			for(int j=0;j<(1<<w);j++){
				for(int k:a[w][j]){
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
		cout<<dp[h][0]<<"\n";
	}
	return 0;
}