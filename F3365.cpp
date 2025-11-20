#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
int k[N],in[N],d[N],p;
void exgcd(int a,int b,int& x,int& y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int inv(int a){
  int x,y;
  exgcd(a,p,x,y);
  return (x%p+p)%p;
}
int C(int x,int y){
	return (k[y]*in[x]%p)*in[y-x]%p;
}
signed main(){
	int cs,n,m,ans=0;
	cin>>cs>>n>>m>>p;
	k[1]=k[0]=d[1]=d[0]=1;
	in[1]=in[0]=inv(1);
	for(int i=2;i<=100000;i++){
		k[i]=k[i-1]*i%p;
		in[i]=inv(k[i]);
	}
	for(int i=2;i<=n;i++){
		if(((i+1)/2)*((i+1)/2+1)<=m){
			d[i]=k[i];
		}
		else{
			for(int j=1;j<=i/2;j++){
				if((i-j+1)*j<=m){
					d[i]=(d[i]+d[i-j]*d[j-1]%p*C(i-j,i-1)*2%p)%p;
				}
				else break;
			}
		}
		cout<<i<<" "<<d[i]<<"\n";
	}
	cout<<d[n]%p<<"\n";
	return 0;
}