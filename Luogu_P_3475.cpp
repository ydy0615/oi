#include<bits/stdc++.h>
using namespace std;
bitset<30> mp[30],s;
int f[1<<15];
vector<int> t[20];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,x,ans=0x3f3f3f3f,as,cnt,sum;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		mp[u][v-1]=1;
		mp[v][u-1]=1;
	}
	n/=2;
	for(int i=0;i<(1<<n);i++){
		cnt=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) cnt++;
		}
		f[i]=cnt;
		t[cnt].push_back(i);
	}
	for(int i=0;i<(1<<n);i++){
		for(int j:t[n-f[i]]){
			x=i+(j<<n);sum=0;
			for(int k=0;k<n*2;k++){
				if(x&(1<<k)){
					s=(mp[k+1].to_ullong()|x)-x;
					sum+=s.count();
				}
			}
			if(sum<ans){
				ans=sum;
				as=x;
			}
		}
	}
	for(int i=0;i<n*2;i++){
		if(as&(1<<i)){
			cout<<i+1<<" ";
		}
	}
	return 0;
}