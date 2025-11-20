#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
bool b[10000010];
signed main(){
	int l,r,cnt=0;
	long long ans=1;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		if(!b[i]){
			for(int j=i*2;j<=r;j+=i){
				b[j]=1;
			}
			cnt++;
		}
	}
	ans*=cnt;
	for(int i=1;i<=(r-l+1)+1;i++){
		if(i!=(cnt+1)) ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}