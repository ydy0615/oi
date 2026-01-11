#include<bits/stdc++.h>
using namespace std;
#define N 40000010
#define int long long
int ans[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b,c;
	cin>>a>>b;
	c=b+"#"+a;
	int n=c.size();
	int p=0,k=1,l;
	ans[0]=n;
	while(ans[1]<n && c[ans[1]+1]==c[ans[1]]) ans[1]++;
	for(int i=2;i<n;i++){
		l=ans[i-p];
		if(i+l-1<k){
			ans[i]=l;
		}
		else{
			ans[i]=max(0ll,k-i+1);
			while(i+ans[i]<n && c[i+ans[i]]==c[ans[i]]) ans[i]++;
			p=i;
			k=i+ans[i]-1;
		}
	}
	int ans1=0,ans2=0;
	for(int i=0;i<b.size();i++){
		if(i==0){
			ans1=ans1^(1)*(b.size()+1);
		}
		else ans1=ans1^(i+1)*(ans[i]+1);
	}
	for(int i=b.size()+1;i<c.size();i++){
		ans2=ans2^(i-b.size())*(ans[i]+1);
	}
	cout<<ans1<<"\n"<<ans2<<"\n";
	return 0;
}