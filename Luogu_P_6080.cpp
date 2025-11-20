#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define mod 31
#define int unsigned int
int a[N],b[N],srt[N];
int hsh[30],to[30],ttop,hah[30][N];
vector<int> ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,s,mo=0,sum=1,cnt;
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++){
		cin>>b[i];
		hsh[b[i]]=1;
		srt[i]=b[i];
		if(i!=k) sum*=mod;
	}
	ttop=0;
	for(int i=1;i<=s;i++){
		if(hsh[i]) to[i]=++ttop;
		hsh[i]=0;
	}
	cnt=ttop;
	for(int i=k;i>=1;i--){
		b[i]=to[b[i]];
		mo=mo*mod+b[i];
	}
	for(int i=1;i<=s;i++){
		for(int j=n;j>=n-k+1;j--){
			hah[i][n-k+1]=hah[i][n-k+1]*mod;
			if(a[j]==i) hah[i][n-k+1]++;
		}
		for(int j=n-k;j>=1;j--){
			hah[i][j]=hah[i][j+1]*mod;
			if(a[j+k]==i) hah[i][j]-=sum*mod;
			if(a[j]==i) hah[i][j]++;
		}
	}
	for(int i=1;i<k;i++) hsh[a[i]]++;
	for(int i=k;i<=n;i++){
		hsh[a[i]]++;
		hsh[a[i-k]]--;
		ttop=sum=0;
		for(int j=1;j<=s;j++) if(hsh[j]) to[j]=++ttop;
		if(ttop!=cnt) continue;
		for(int j=1;j<=s;j++) sum+=to[j]*hah[j][i-k+1];
		if(sum==mo) ans.push_back(i-k+1);
	}
	cout<<ans.size()<<"\n";
	for(int i:ans) cout<<i<<"\n";
	return 0;
}