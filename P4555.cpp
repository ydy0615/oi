#include <bits/stdc++.h>
using namespace std;
#define N 300010
int ans[N];
int B[N],C[N];
char t[N];
int main(){
	string s;
	cin>>s;
	int n=s.size(),anss=0;
	t[0]='@';
	for(int i=0;i<n;i++){
		t[i*2+2]=s[i];
		t[i*2+1]='#';
	}
	t[n*2+1]='#';
	t[n*2+2]='$';
	n=n*2+2;
	int p=0,k=0;
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
		if(i+ans[i]>k){
			k=i+ans[i];
			p=i;
		}
		B[i+(ans[i]-1)]=max(B[i+(ans[i]-1)],ans[i]-1);
		C[i-(ans[i]-1)]=max(C[i-(ans[i]-1)],ans[i]-1);
	}
	for(int i=n-1;i>=1;i--){
		B[i]=max(B[i],B[i+2]-2);
	}
	for(int i=1;i<n;i++){
		C[i]=max(C[i],C[i-2]-2);
	}
	for(int i=1;i<n;i++){
		if(B[i] && C[i]) anss=max(anss,B[i]+C[i]);
	}
	cout<<anss<<"\n";
	return 0;
}