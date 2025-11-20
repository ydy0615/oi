#include<bits/stdc++.h>
using namespace std;
#define N 1010
int a[N],b[N],c[N],s[N],n,ans,pre;
int cnt(){
	int na=0,nb=0;
	for(int i=1;i<=n;i++){
		na+=a[i];
		nb=max(na,nb);
		nb+=b[i];
	}
	return nb;
}
void SA(){
	int x,y,sum,d;
	for(double Temp=99;Temp>=1e-8;Temp*=0.99){
		x=rand()%n+1;
		y=rand()%n+1;
		swap(a[x],a[y]);
		swap(b[x],b[y]);
		sum=cnt();
		d=sum-pre;
		if(d<0 || exp(-d/Temp)*RAND_MAX>rand()){
			swap(c[x],c[y]);
			pre=sum;
			if(sum<ans){
				ans=sum;
				for(int i=1;i<=n;i++) s[i]=c[i];
			}
		}
		else{
			swap(a[x],a[y]);
			swap(b[x],b[y]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s[i]=c[i]=i;
	}
	ans=pre=cnt();
	while ((double)clock()/CLOCKS_PER_SEC<0.95) SA();
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n";
	return 0;
}