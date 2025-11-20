#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int a[N],n,len,l1[N],r1[N],d[N];
int ans=inf,ansl,ansr,anss[N];
int chk(int x,int y){
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(l+x>a[i+1]) return 1;
		if(r+y<a[i]) return -1;
		l=max(l+x,a[i]);
		r=min(r+y,a[i+1]);
	}
	if(r<len) return -1;
	if(l<=len && len<=r) return 0;
	if(l>len) return 1;
}
int check(int mid){
	int l=0,r=len-mid,midd;
	while(l<=r){
		midd=(l+r)>>1;
		int tmp=chk(midd,midd+mid);
		if(tmp==0){
			if(mid<ans){
				ans=mid;
				ansl=midd;
				ansr=midd+mid;
			}
			return 1;
		}
		if(tmp==1) r=midd-1;
		if(tmp==-1) l=midd+1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>len>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l1[i]=a[i-1]+1;
		r1[i]=a[i+1]-1;
	}
	l1[1]=0;
	r1[n]=len;
	a[n+1]=inf;
	int l=0,r=len,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]=min(d[i-1]+ansr,a[i+1]);
	}
	int sp=len;
	for(int i=n-1;i>=1;i--){
		sp=min(sp-ansl,d[i]);
		anss[i]=sp;
	}
	anss[n]=len;
	for(int i=1;i<=n;i++){
		cout<<anss[i-1]<<" "<<anss[i]<<"\n";
	}
	return 0;
}