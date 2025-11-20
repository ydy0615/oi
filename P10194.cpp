#include<bits/stdc++.h>
using namespace std;
#define N 500010
int a[N*3],t=0,l[N],r[N];
pair<int,int> st[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
		a[i+n*2]=a[i];
	}
	for(int i=1;i<=n*3;i++){
		while(t && st[t].second>=a[i]) t--;
		l[i]=st[i].first;
		st[++t]={i,a[i]};
	}
	return 0;
}