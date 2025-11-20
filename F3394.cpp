#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int a[N],b[N];
int p[N],c1[N],c2[N];
bool Sub4=1;
signed main(){
	int T,n,d,ans1,ans2;
	cin>>T;
	while(T--){
		ans1=inf;
		ans2=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>3)Sub4=false;
		}
		if(Sub4){
			
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int tmp=d-a[i];
			b[i]=upper_bound(a+1,a+1+n,tmp)-(a+1);
		}
		int x=n/2,y=n-x,s1,s2;
		for(int j=0;j<(1<<x);j++){
			s1=s2=c1[x+1]=c2[x+1]=0;
			for(int k=x-1;k>=0;k--){
				if((j&(1<<k))){
					p[k+1]=1;
					c1[k+1]=++s1;
				}
				else{
					p[k+1]=0;
					c2[k+1]=++s2;
				}
			}
			int tmp=0;
			for(int k=1;k<=x;k++){
				if(p[k]==0){
					if(b[k]<=x){
						if(b[k]<=k) tmp+=x-k+1-c1[k];
						else tmp+=x-b[k]+1-c1[k];
					}
				}
				else{
					if(b[k]<=x) tmp+=n-k+c1[b[k]]+1;
					else tmp+=n-b[k]+1;
				}
				cout<<j<<" "<<k<<" "<<tmp<<" "<<b[k]<<endl;
			}
			for(int k=x+1;k<=n;k++){
				if(b[k]<=x) tmp+=n-k+c1[b[k]];
				else tmp+=n-b[k]+1;
				cout<<j<<" "<<k<<" "<<tmp<<" "<<b[k]<<endl;
			}
			ans1=min(ans1,tmp);
			cout<<tmp<<endl;
		}
		cout<<ans1<<endl;
	}
	return 0;
}
/*
3
4 7
1 4 6 3
4 11
1 4 6 3
4 5
1 4 6 3


1
4 7
1 4 6 3
*/