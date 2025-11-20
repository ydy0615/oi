#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
struct ma{
	int a[4][4];
	ma operator*(const ma &b) const {
		ma res;
		res.a[1][1]=(a[1][1]*b.a[1][1]+a[1][2]*b.a[2][1])%mod;
		res.a[1][2]=(a[1][1]*b.a[1][2]+a[1][2]*b.a[2][2])%mod;
		res.a[2][1]=(a[2][1]*b.a[1][1]+a[2][2]*b.a[2][1])%mod;
		res.a[2][2]=(a[2][1]*b.a[1][2]+a[2][2]*b.a[2][2])%mod;
		return res;
	}
}ones,a1,a2;
ma qmi(ma a,string b){
	int c=b.size()-1;
	ma ans=ones;
	while(c>=0){
		int p=b[c]-'0';
		ma l=a;
		for(int i=1;i<=p;i++) ans=ans*l;
		for(int i=1;i<=9;i++) a=a*l;
		c--;
	}
	return ans;
}
signed main(){
	string n,m;
	int a,b,c,d;
	cin>>n>>m>>a>>b>>c>>d;
	for(int i=m.size()-1;i>=0;i--){
		if(m[i]>'0'){
			m[i]--;
			break;
		}
		m[i]='9';
	}
	for(int i=n.size()-1;i>=0;i--){
		if(n[i]>'0'){
			n[i]--;
			break;
		}
		n[i]='9';
	}
	ones.a[1][1]=1;
	ones.a[1][2]=0;
	ones.a[2][1]=0;
	ones.a[2][2]=1;
	a1.a[1][1]=a;
	a1.a[1][2]=b;
	a1.a[2][1]=0;
	a1.a[2][2]=1;

	a2.a[1][1]=c;
	a2.a[1][2]=d;
	a2.a[2][1]=0;
	a2.a[2][2]=1;
	ma ans=qmi(a1,m)*qmi(a2*qmi(a1,m),n);
	cout<<(ans.a[1][1]+ans.a[1][2])%mod<<"\n";
	return 0;
}