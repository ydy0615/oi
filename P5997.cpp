#include<bits/stdc++.h>
using namespace std;
pair<int,int> dp[1<<24];
int a[25],b[110];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	sort(b+1,b+m+1,greater<int>());
	dp[0]={1,b[1]+1};
	for(int i=0;i<(1<<n);i++){
		if(dp[i].first==0) continue;
		for(int k=1;k<=n;k++){
			if(!(i&(1<<(k-1)))){
				if(dp[i].second>a[k]){
					if(dp[i|(1<<(k-1))].first>dp[i].first || dp[i|(1<<(k-1))].first==0){
						dp[i|(1<<(k-1))]={dp[i].first,dp[i].second-a[k]};
					}
					else if(dp[i|(1<<(k-1))].first==dp[i].first && dp[i|(1<<(k-1))].second<dp[i].second-a[k]){
						dp[i|(1<<(k-1))]={dp[i].first,dp[i].second-a[k]};
					}
				}
				else if(b[dp[i].first+1]+1>a[k] && dp[i].first<m){
					if(dp[i|(1<<(k-1))].first>dp[i].first+1 || dp[i|(1<<(k-1))].first==0){
						dp[i|(1<<(k-1))]={dp[i].first+1,b[dp[i].first+1]+1-a[k]};
					}
					else if(dp[i|(1<<(k-1))].first==dp[i].first+1 && dp[i|(1<<(k-1))].second<b[dp[i].first+1]+1-a[k]){
						dp[i|(1<<(k-1))]={dp[i].first+1,b[dp[i].first+1]+1-a[k]};
					}
				}
			}
		}
	}
	if(dp[(1<<n)-1].first==0 || dp[(1<<n)-1].first>m) cout<<"NIE\n";
	else cout<<dp[(1<<n)-1].first<<"\n";
	return 0;
}