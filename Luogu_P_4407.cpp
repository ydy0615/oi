#include<bits/stdc++.h>
using namespace std;
#define N 2400010
#define mod 31
#define int unsigned long long
map<int,int> a[25],b[25][25],c[25];
int tmp[N];
int conv(string s,int typ,int y){
	int ans=0;
	if(typ==0){
		for(int i=0;i<s.size();i++){
			ans=ans*mod+s[i];
		}
	}
	if(typ==1){
		for(int i=0;i<s.size();i++){
			if(i!=y) ans=ans*mod+s[i];
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans,cnt;
	string str;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str;
		a[str.size()][conv(str,0,0)]++;
		for(int j=0;j<str.size();j++){
			tmp[j]=conv(str,1,j);
			b[str.size()-1][j][tmp[j]]++;
		}
		sort(tmp,tmp+str.size());
		cnt=unique(tmp,tmp+str.size())-tmp;
		for(int j=0;j<cnt;j++){
			c[str.size()-1][tmp[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>str;
		if(a[str.size()][conv(str,0,0)]){
			cout<<-1<<"\n";
			continue;
		}
		ans=0;
		for(int j=0;j<str.size();j++){
			tmp[j]=conv(str,1,j);
			ans+=b[str.size()-1][j][tmp[j]];
		}
		sort(tmp,tmp+str.size());
		cnt=unique(tmp,tmp+str.size())-tmp;
		for(int j=0;j<cnt;j++) ans+=a[str.size()-1][tmp[j]];
		ans+=c[str.size()][conv(str,0,0)];
		cout<<ans<<"\n";
	}
	return 0;
}