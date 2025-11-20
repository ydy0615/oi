#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main(){
	int n,A,B,C;
	double ans=0;
	cin>>n>>A>>B>>C>>a[1];
	for(int i=2;i<=n;i++){
		a[i]=((long long)a[i-1]*A+B)%100000001;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]%C+1;
	}
	for(int i=1;i<n;i++){
		ans+=1.0/max(a[i],a[i+1]);
	}
	ans+=1.0/max(a[n],a[1]);
	//cout<<ans<<endl;
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}