#include<bits/stdc++.h>
using namespace std;
#define N 1010
double ansx,ansy,ans;
double anx,any;
int a[N][3],n,mx,my;
double count(double x,double y){
	double res=0;
	for(int i=1;i<=n;i++){
		res+=sqrt((x-a[i][1])*(x-a[i][1])+(y-a[i][2])*(y-a[i][2]))*a[i][0];
	}
	return res;
}
void sa(){
	for(double temp=1899;temp>1e-15;temp*=0.99){
		double x=fmod(ansx+(rand()*2.0-RAND_MAX)*temp,mx);
		double y=fmod(ansy+(rand()*2.0-RAND_MAX)*temp,my);
		double res=count(x,y);
		double d=res-ans;
		if(d<0){
			ansx=x;
			ansy=y;
			ans=res;
			anx=x;
			any=y;
		}
		else if(exp(-d/temp)*RAND_MAX > rand()){
			ansx=x;
			ansy=y;
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(NULL));
	cin>>n;
	for(int i=1,x,y,w;i<=n;i++){
		cin>>x>>y>>w;
		a[i][0]=w;
		a[i][1]=x;
		a[i][2]=y;
		mx=max(mx,x);
		my=max(my,y);
		ansx+=x;
		ansy+=y;
	}
	ansx/=n;
	ansy/=n;
	ans=count(ansx,ansy);
	anx=ansx;
	any=ansy;
	while (clock() * 1.0 / CLOCKS_PER_SEC < 0.90) sa();
	cout<<fixed<<setprecision(3)<<anx<<" "<<any<<"\n";
	return 0;
}