#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define N 1000010
ull h[N],hh[N],len,mod=233317,hsh;
char ans[N];
signed main(){
	string S,T;
	cin>>S>>T;
	S=" "+S;
	T=" "+T;
	h[0]=1;
	for(int i=1;i<T.size();i++){
		h[i]=h[i-1]*mod;
		hsh=hsh*mod+T[i];
	}
	for(int i=1;i<S.size();i++){
		ans[++len]=S[i];
		hh[len]=hh[len-1]*mod+S[i];
		if(hsh==hh[len]-hh[len-T.size()+1]*h[T.size()-1]){
			len-=T.size()-1;
		}
	}
	for(int i=1;i<=len;i++) cout<<ans[i];
	return 0;
}