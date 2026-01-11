#include <bits/stdc++.h>
using namespace std;
#define N 30000010
int ans[N];
int main(){
	string s,t;
	cin>>s;
	int n=s.size();
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
		if(i+ans[i]-1>k){
			p=i;
			k=i+ans[i]-1;
		}
		R=max(R,ans[i]-1);
	}
	cout<<R<<"\n";
	return 0;
}