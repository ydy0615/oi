#include<bits/stdc++.h>
using namespace std;
char dp1[(1<<25)];
bool dp2[(1<<25)];
int t[(1<<25)];
map<int,long long> t2;
bitset<55> b[55];
int main(){
	int n,x,y,m,ans=0,cnt;
	cin>>n;
	m=max(n/2,1);
	while(cin>>x>>y){
		b[x][y-1]=1;
		b[y][x-1]=1;
	}
	t[0]=(1<<n)-1;
	b[51]=((1ll<<m)-1);
	for(int i=1;i<=m;i++){
		dp1[(1<<(i-1))]=1;
		t[(1<<(i-1))]=(b[i]&b[51]).to_ulong();
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=1;j<=m;j++){
			t[i|(1<<(j-1))]=t[i]&b[j].to_ullong();
			if(t[i]&(1<<(j-1)) && !(i&(1<<(j-1)))){
				dp1[i|(1<<(j-1))]=max(dp1[i|(1<<(j-1))],char(dp1[i]+1));
			}
			else{
				dp1[i|(1<<(j-1))]=max(dp1[i|(1<<(j-1))],dp1[i]);
			}
		}
	}
	dp2[0]=1;
	t2[0]=(1<<n)-1;
	for(int i=0;i<(1<<(n-m));i++){
		if(!dp2[i]) continue;
		cnt=0;
		for(int j=m+1;j<=n;j++){
			if(t2[i]&(1<<(j-1))){
				t2[i|(1<<(j-m-1))]=(t2[i]&b[j].to_ullong());
				dp2[i|(1<<(j-m-1))]=1;
			}
			if(i&(1<<(j-m-1))) cnt++;
		}
		ans=max(dp1[t2[i]&((1<<m)-1)]+cnt,ans);
	}
	cout<<ans<<"\n";
	return 0;
}