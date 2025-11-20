#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int t[30],w[30],ct[1<<20],cw[1<<20],f[1<<20];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>t[i]>>w[i];
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				ct[i]=max(ct[i],t[j]);
				cw[i]+=w[j];
			}
		}
	}
	f[0]=0;
	for(int i=1;i<(1<<n);i++){
		f[i]=inf;
		for(int j=(i-1)&i;;j=(j-1)&i){
			if(cw[i^j]<=m){
				f[i]=min(f[i],f[j]+ct[i^j]);
			}
			if(!j) break;
		}
	}
	cout<<f[(1<<n)-1]<<"\n";
	return 0;
}