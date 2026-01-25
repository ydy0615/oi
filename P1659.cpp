#include <bits/stdc++.h>
using namespace std;
#define N 3000010
#define int long long
#define mod 19930726
int ans[N],f[N];
int qh(int x,int y){
	return (x+y)*(y-x)/4;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	int TEMP,K,ma=0;
	cin>>TEMP>>K;
	string s,t;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		t+='#';
		t+=s[i];
	}
	t+='#';
	n=t.size();
	int p=0,k=0,sum=0;
	for(int i=1;i<n;i++){
		if(i<k) ans[i]=min(ans[2*p-i],k-i);
		else ans[i]=1;
		while(i-ans[i]>=0 && i+ans[i]<n && t[i-ans[i]]==t[i+ans[i]]){
			ans[i]++;
		}
		if(i+ans[i]-1>k){
			p=i;
			k=i+ans[i]-1;
		}
	}
	for(int i=1;i<n;i++){
		ans[i]/=2;
		if(i%2){
			sum+=ans[i];
			ma=max(ma,ans[i]);
		}
	}
	if(sum<K){
		cout<<"-1\n";
		return 0;
	}
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		int cnt=0;
		for(int i=1;i<n;i++){
			if(i%2 && ans[i]>=mid){
				cnt+=(ans[i]-mid);
			}
		}
		if(cnt<K) r=mid-1;
		else l=mid;
	}
	l++;
	f[l]=1;
	for(int i=l+1;i<=ma;i++){
		f[i]=f[i-1]*(i*2-1)%mod;
	}
	int anss=1;
	for(int i=1;i<n;i++){
		if(i%2 && ans[i]>l){
			anss=anss*f[ans[i]]%mod;
			K-=ans[i]-l;
		}
	}
	anss=anss*qpow(l*2-1,K)%mod;
	cout<<anss<<"\n";
	return 0;
}