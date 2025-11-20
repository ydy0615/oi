#include<bits/stdc++.h>
using namespace std;
int a[30],n,m;
double ans,pre,sum;
priority_queue<int> q;
double count(){
	q={};
	for(int i=1;i<=m;i++) q.push(0);
	for(int i=1,x;i<=n;i++){
		x=-q.top();
		x+=a[i];
		q.pop();
		q.push(-x);
	}
	double num,s=0;
	num=1.0*sum/m;
	for(int i=1,x;i<=m;i++){
		x=-q.top();
		s+=(x-num)*(x-num);
		q.pop();
	}
	s/=m;
	return sqrt(s);
}
void sa(){
	for(double temp=2899;temp>1e-15;temp*=0.999){
		int x=rand()%n+1,y=rand()%n+1;
		swap(a[x],a[y]);
		double res=count();
		double d=res-ans;
		if(d<0 || exp(-d/temp)*RAND_MAX>rand()){
			if(res<ans){
				ans=res;
			}
		}
		else{
			swap(a[x],a[y]);
		}
	}
	return ;
}
int main(){
	ans=0x3f3f3f3f;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ans=pre=count();
	for(int i=1;i<=n;i++) sa();
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}