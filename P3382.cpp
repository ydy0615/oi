#include<bits/stdc++.h>
using namespace std;
#define N 40
#define eps 1e-7
#define double long double
double a[N];
double qpow(double x,int y){
	double res=1;
	while(y){
		if(y&1) res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	double l,r;
	cin>>n>>l>>r;
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	double mid=(l+r)/2;
	while(r-l>eps){
		mid=(l+r)/2;
		double mid1=(l+mid)/2;
		double mid2=(mid+r)/2;
		//cout<<mid<<" "<<mid1<<" "<<mid2<<endl;
		double num1=0,num2=0;
		for(int i=1;i<=n;i++){
			num1+=qpow(mid1,n-i+1)*a[i];
			num2+=qpow(mid2,n-i+1)*a[i];
		}
		num1+=a[n+1];
		num2+=a[n+1];
		if(num1<num2){
			l=mid1;
		}
		else{
			r=mid2;
		}
	}
	cout<<fixed<<setprecision(5)<<mid<<"\n";
	return 0;
}