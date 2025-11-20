#include<bits/stdc++.h>
using namespace std;
#define N 20010
inline void read(int &a){
	a=0;
	char c;
	while((c=getchar())<48);
	do a=a*10+(c^48);
	while((c=getchar())>47);
}
int k[N],f[N],c[N],n,ans=0x3f3f3f3f,i,j,x,y,s;
int main(){
	read(n);
	for(i=1;i<=n+1;++i){
		s+=c[i-1]*y;
		f[i]=f[i-1]+y;
		if(i<=n) read(x),read(y);
		c[i]=c[i-1]+x;
		k[i]=c[i]*f[i];
	}
	for(i=1;i<n;++i){
		int l=i+1,r=n,l1,lr;
		while(l<r){
			l1=(l+l+r)/3;
			lr=(l+r+r+2)/3;
			if(k[l1]+k[i]-c[i]*f[l1]-c[l1]*f[n+1]<=k[lr]+k[i]-c[i]*f[lr]-c[lr]*f[n+1]){
				r=lr-1;
			}
			else{
				l=l1+1;
			}
		}
		ans=min({ans,k[l]+k[i]-c[i]*f[l]-c[l]*f[n+1],k[l+1]+k[i]-c[i]*f[l+1]-c[l+1]*f[n+1],k[l-1]+k[i]-c[i]*f[l-1]-c[l-1]*f[n+1]});
	}
	cout<<ans+s;
	return 0;
}