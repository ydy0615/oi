#include <bits/stdc++.h>
using namespace std;
#define N 30000010
int ans[N];
int B[N],C[N];
int main(){
	//memset(B,0x3f,sizeof(B));
	string s,t;
	cin>>s;
	int n=s.size(),anss=0;
	t+='@';
	for(int i=0;i<n;i++){
		t+='#';
		t+=s[i];
	}
	t+='#';
	t+='$';
	n=t.size();
	int p=0,k=0,R=0;
	for(int i=1;i<n;i++){
		if(i<k){
			ans[i]=min(ans[2*p-i],k-i);
		}
		else{
			ans[i]=1;
		}
		while(i-ans[i]>=0 && i+ans[i]<n && t[i-ans[i]]==t[i+ans[i]]){
			ans[i]++;
		}
		//cout<<ans[i]<<" "<<t[i]<<endl;
		B[i+(ans[i]/2)]=max(B[i+(ans[i]/2)],ans[i]-1);
		C[i-(ans[i]/2)]=max(C[i-(ans[i]/2)],ans[i]-1);
	}
	cout<<"\n";
	for(int i=1;i<n;i++){
		B[i]=max(B[i],B[i-1]);
	}
	for(int i=n-1;i>=1;i--){
		C[i]=max(C[i],C[i+1]);
	}
	for(int i=1;i<n;i++){
		//cout<<B[i]<<" "<<C[i]<<endl;
		anss=max(anss,B[i]+C[i]);
	}
	//cout<<endl;
	cout<<anss<<"\n";
	return 0;
}