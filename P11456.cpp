#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define inf 0x3f3f3f3f
#define mod 1000000007
int dp[N],pr[N],nb[N];
int n;
priority_queue<pair<int,int> > q;
int tree[N];
int lb(int x){return x&(-x);}
void add(int i,int x){
	for(;i<=n;i+=lb(i))	tree[i]+=x;
}
int ask(int i){
	int ans=0;
	for(;i>=1;i-=lb(i)) ans+=tree[i];
	return ans;
}
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string str;
	cin>>n>>str;
	str=" "+str;
	dp[0]=1;
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='R'){
			tmp=i;
		}
		pr[i]=tmp;
	}
	tmp=inf;
	for(int i=n;i>=1;i--){
		if(str[i]=='B'){
			tmp=i;
		}
		nb[i]=tmp;
		if(tmp!=inf){
			q.push({-(tmp+tmp-i),i});
			cout<<i<<" $ ";
		}
	}
	for(int i=1;i<=n;i++){
		if(str[i]=='R'){
			dp[i]=0;
		}
		else{
			if(str[i]=='X') dp[i]=dp[i-1];
			int st=0,ed=0;
			if(str[i]=='B'){
				st=i;
			}
			cout<<i<<" "<<pr[i]<<" "<<ask(i)-ask(pr[i]-1)<<" : "<<endl;
			for(int j=i-1;j>=1;j-=2){
				if(str[j]=='B') st=j;
				if(str[j]=='R' && !ed) ed=j;
				int mid=(i+j)>>1;
				if((st>mid || !st) && (ed<=mid || !ed)){
					cout<<dp[j-1]<<" "<<j-1<<endl;
					dp[i]=(dp[i]+dp[j-1])%mod;
				}
				if(str[j-1]=='B'){
					st=j-1;
				}
				if(str[j-1]=='R' && !ed){
					ed=j-1;
				}
			}
		}
		add(i,dp[i]);
		//cout<<i<<" # "<<dp[i]<<endl;
	}
	/*for(int i=1;i<=n;i++){
		if(str[i]=='R'){
			dp[i]=0;
		}
		else{
			if(str[i]=='X') dp[i]=dp[i-1];
			int st=0,ed=0;
			if(str[i]=='B'){
				st=i;
			}
			for(int j=i-1;j>=1;j-=2){
				if(str[j]=='B') st=j;
				if(str[j]=='R' && !ed) ed=j;
				int mid=(i+j)>>1;
				if((st>mid || !st) && (ed<=mid || !ed)){
					dp[i]=(dp[i]+dp[j-1])%mod;
				}
				if(str[j-1]=='B'){
					st=j-1;
				}
				if(str[j-1]=='R' && !ed){
					ed=j-1;
				}
			}
		}
	}*/
	cout<<dp[n]<<"\n";
	return 0;
}