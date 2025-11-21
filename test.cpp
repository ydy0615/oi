#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
#define inf 0x3f3f3f3f
int sum[N],mi[N],b[N];
signed main(){
	string str;
	cin>>str;
	int n=str.size(),ans=0,tmp=0,add=0,ans1,ans2;
	str=" "+str;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]-1;
		if(str[i]=='1') sum[i]+=2;
		b[i]=sum[i];
	}
	mi[n+1]=-inf;
	for(int i=n;i>=1;i--){
		mi[i]=max(mi[i+1],sum[i]);
	}
	ans=max(mi[1],0ll);
	for(int i=1;i<=n;i++){
		if(str[i]=='?'){
			if(add+2+mi[i]<=ans){
				add+=2;
			}
		}
		sum[i]+=add;
		tmp=min(tmp,sum[i]);
	}
	ans1=ans-tmp;
	//cout<<ans1<<endl;
	ans++;
	add=0;
	tmp=0;
	for(int i=1;i<=n;i++){
		sum[i]=b[i];
		if(str[i]=='?'){
			if(add+2+mi[i]<=ans){
				add+=2;
			}
		}
		sum[i]+=add;
		tmp=min(tmp,sum[i]);
	}
	ans2=ans-tmp;
	cout<<min(ans1,ans2)<<endl;
	return 0;
}