#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
int t[N],d[N];
int check(int x,int y){
	if(x==0 && y==1) return 1;
	if(x==1 && y==0) return 1;
	if(x==2 && y==2) return 1;
	return 0;
}
signed main(){
	int n,ans=0;
	string s;
	cin>>n>>s;
	s=" "+s;
	t[0]=3;
	t[1]=2;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			t[i*2]=0;
		}
		if(s[i]=='1'){
			t[i*2]=1;
		}
		t[i*2+1]=2;
	}
	t[n*2+2]=4;
	int r=-1,mid=0;
	for(int i=1;i<=n*2+1;i+=2){
		d[i]=1;
		if(i<r) d[i]=min(r-i,d[mid*2-i]);
		while(check(t[i-d[i]],t[i+d[i]])) d[i]++;
		if(i+d[i]>r){
			r=i+d[i];
			mid=i;
		}
		ans+=(d[i]-1)/2;
	}
	cout<<ans<<"\n";
	return 0;
}