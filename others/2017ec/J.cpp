
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=2e5+10;
vector<int> v;
int n;
int a[MAXN],b[MAXN];
int main(){
	int T,cas=0; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans;
		if(n <= 6) ans = 0;
		else {
			if(n < 16) {
				if(n & 1) ans = 1;
				else ans = 0;
			}
			else {
				if(n & 1) ans = 1;
				else ans = -1;
			}
		}
		if(ans == -1) printf("Case #%d: Sheep\n",++cas);
		else if(ans == 0) printf("Case #%d: Draw\n",++cas);
		else printf("Case #%d: Panda\n",++cas);
	}
	return 0;
}
