#include<bits/stdc++.h>
using namespace std;
int d[20][10];
int f[20],ans=0,n;

int check(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs(f[i]-f[d[i][1]]);
		ans+=abs(f[i]-f[d[i][2]]);
		ans+=abs(f[i]-f[d[i][3]]);
	}
	return ans;
}

void sa(){
	for(int temp=1899;temp>1e-15;temp*=0.99){
		int x=rand()%n+1,y=rand()%n+1;
		swap(f[x],f[y]);
		int res=check(),d=res-ans;
		if(d<0){
			ans=res;
		}
		else if(exp(-d/temp)*RAND_MAX>rand()){
			d--;
		}
		else{
			swap(f[x],f[y]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1,a,b,c;i<=n;i++){
		cin>>a>>b>>c;
		d[i][1]=a;
		d[i][2]=b;
		d[i][3]=c;
		f[i]=i;
	}
	ans=check();
	for(int i=1;i<=10000;i++) sa();
	cout<<ans/2<<"\n";
	return 0;
}