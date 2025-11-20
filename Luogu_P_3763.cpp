#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define N 1000010
#define B 31
int pw[N],hs[N],ht[N];
int get(int hah[],int l,int r){
	return hah[r]-hah[l-1]*pw[r-l+1];
}
bool check(int l,int ed){
	int st=1,r=l+ed-1;
	for(int i=1;i<=3;i++){
		int lt=-1,rt=ed-st+2,mid;
		while(lt+1<rt){
			mid=(lt+rt)>>1;
			if(get(hs,l,l+mid-1)==get(ht,st,st+mid-1)) lt=mid;
			else rt=mid;
		}
		l+=lt+1;
		st+=lt+1;
		if(st>ed) return 1;
	}
	return get(hs,l,r)==get(ht,st,ed);
}
signed main(){
	int T,n,m;
	string s1,s2;
	pw[0]=1;
	for(int i=1;i<=100000;i++) pw[i]=pw[i-1]*B;
	cin>>T;
	while(T--){
		cin>>s1>>s2;
		n=s1.size();
		m=s2.size();
		s1=" "+s1;
		s2=" "+s2;
		for(int i=1;i<=n;i++) hs[i]=hs[i-1]*B+s1[i];
		for(int i=1;i<=m;i++) ht[i]=ht[i-1]*B+s2[i];
		int ans=0;
		for(int i=1;i<=n-m+1;i++){
			if(check(i,m)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}