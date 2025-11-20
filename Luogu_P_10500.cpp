#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N];
bool b[40][N];
long long c1[40],c2[40],c3[40];
long double ans1,ans2,ans3;
signed main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1ll<<j)) b[j][i]=1;
			else b[j][i]=0;
		}
	}
	for(int i=0;i<=30;i++){
		int l1=0,l2=0,p=0,s=0;
		for(int j=1;j<=n;j++){
			if(b[i][j]){
				c1[i]+=j-l1-1;
				c2[i]+=j-1;
				c3[i]+=p;
			}
			else{
				c2[i]+=l2;
				c3[i]+=s;
			}
			p++;
			if(b[i][j]) swap(p,s);
			if(!b[i][j]) l1=j;
			else l2=j;
		}
	}
	for(int i=0;i<=30;i++){
		ans1+=c1[i]*(1<<(i+1));
		ans2+=c2[i]*(1<<(i+1));
		ans3+=c3[i]*(1<<(i+1));
	}
	ans1+=sum;
	ans2+=sum;
	ans3+=sum;
	cout<<fixed<<setprecision(3)<<ans3/n/n<<" "<<ans1/n/n<<" "<<ans2/n/n<<endl;
	return 0;
}