#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define int unsigned long long
int a[N],h[100][N],f[N]={9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T,n,q,flg;
	cin>>T;
	while(T--){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=8;i++){
			for(int j=1;j<=n;j++){
				h[i][j]=h[i][j-1]^(a[j]*f[i]);
			}
		}
		for(int i=1,x,y;i<=q;i++){
			cin>>x>>y;
			if((y-x+1)%2) cout<<"NO\n";
			else{
				flg=1;
				for(int j=1;j<=8;j++){
					if((h[j][y]^h[j][x-1])){
						flg=0;
						break;
					}
				}
				if(flg) cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
	}
	return 0;
}