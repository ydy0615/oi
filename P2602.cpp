#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[20],f[20][20];
int check(int x,int y){
	int sum=1,flg=0,tmp,ans=0,flag=0,c=x;
	for(;sum<=x;sum*=10) flg++;
	sum/=10;
	flg--;
	while(sum){
		tmp=(x/sum)-1;
		for(int i=0;i<=tmp;i++){
			if(i==y) ans+=f[y][flg]+s[flg];
			else ans+=f[y][flg];
		}
		if(y==0 && tmp>=0) ans-=s[flg];
		//cout<<ans<<endl;
		tmp++;
		if(tmp==y && flg && y){
			ans+=x%sum+1;
		}
		//cout<<ans<<endl;
		x=x%sum;
		sum/=10;
		flg--;
		flag=1;
	}
	for(int i=0;i<=c%10;i++){
		if(i==y) ans++; 
	}
	return ans;
}
signed main(){
	int a,b;
	cin>>a>>b;
	s[1]=10;
	for(int i=2;i<=14;i++){
		s[i]=s[i-1]*10;
	}
	for(int i=0;i<=9;i++){
		f[i][1]=1;
		for(int j=2;j<=14;j++){
			f[i][j]=f[i][j-1]*10+s[j-1];
		}
	}
	//cout<<check(1234,0)<<endl;
	for(int i=0;i<=9;i++){
		cout<<check(b,i)-check(a-1,i)<<" ";
	}
	return 0;
}