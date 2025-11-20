#include <bits/stdc++.h>
using namespace std;
double f[10010],g[10010];
int main(){
	int n;
	cin>>n;
	for(int i=n-1;i>=0;i--) {
		f[i]=f[i+1]+(1.0*n)/(1.0*(n-i));
		g[i]=(1.0*i)/(1.0*(n-i))*(f[i]+1)+g[i+1]+f[i+1]+1;
	}
	cout<<fixed<<setprecision(2)<<g[0]<<endl;
	return 0;
}