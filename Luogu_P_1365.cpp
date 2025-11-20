#include<bits/stdc++.h>
using namespace std;
long double f[300010];
int main(){
	int n;
	long double s=0;
	string str;
	cin>>n>>str;
	str=" "+str;
	for(int i=1;i<=n;i++){
		if(str[i]=='o'){
			f[i]=f[i-1]+s*2+1;
			s++;
		}
		if(str[i]=='x'){
			s=0;
			f[i]=f[i-1];
		}
		if(str[i]=='?'){
			f[i]=f[i-1]+(1.0*s*2+1)/2;
			s=(s+1)/2;
		}
	}
	cout<<fixed<<setprecision(4)<<f[n]<<endl;
	return 0;
}