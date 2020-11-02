#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL f[22][22][5010];
char mp[22][22];
LL use[22];

void print(int x) {
	for(int i = 0;i <= 5;i ++) cout << (x >> i & 1);
}

int main() {
    int T = read();
    while(T --) {
		int n = read(),m = read(),K = read();
		memset(f,0,sizeof(f));
		memset(use,0,sizeof(use));

        for(int i = 1;i <= n;i ++)
        	scanf("%s",mp[i] + 1);

		for(int i = 1;i <= n;i ++) {
			use[i] = use[i - 1];
			for(int j = 1;j <= m;j ++)
				if(mp[i][j] == 'Q')
					use[i] |= (1 << (j - 1));
		}
        f[0][0][0] = 1;
        int maxs = (1 << m) - 1;
        for(int i = 1;i <= n;i ++){

			//for(int j = 1;j <= m;j ++)
           //     use[j] = mp[i][j] == 'Q';
			for(int j = 0;j <= K;j ++) {
				for(int S = 0;S <= maxs;S ++) {
					bool flag = 0;
					for(int k = 0;k < m;k ++) {
						if(!(S & (1 << k)) && mp[i][k + 1] == 'Q') {

							if(j == 0) {
								cout << i << " " << j + 1 << " "; print(S | (1 << k)); cout << " " << f[i][j + 1][S | (1 << k)] <<" ";
								cout << j << " "; print(S); cout << " " <<f[i - 1][j][S] << endl;
							}

							//cout << k << " " << !(S & (1 << k)) << " " << mp[i][k + 1] << endl;
                            f[i][j + 1][S | (1 << k)] += f[i - 1][j][S];
							flag = 1;
						}
					}
				//	if(!flag) {
						f[i][j][S] += f[i - 1][j][S];
						if(j == 1) {
	                		cout << i << " " << j << " "; print(S); cout << " " << f[i - 1][j][S] ;puts("");
                		}
                //	}
                }
			}
        }
        for(int i = 0;i <= n;i ++) {
        	for(int j = 0;j <= K;j ++) {
		        for(int S = 0;S <= maxs;S ++)
   		     		cout << f[i][j][S] << " ";
   		     	puts("");
   		    }
			puts("");
		}
        for(LL i = 1,fac = 1;i <= K;i ++){
        	LL ans = 0;
        	fac *= i;
        	for(int S = 0;S <= maxs;S ++) {
        		bool flag = 0;
				for(int k = 0;k < m;k ++) {
					if(!(S & (1 << k)) && mp[n][k + 1] == 'Q') {
						flag = 1; break;
					}
				}
				if(!flag)
					ans += f[n][i][S];//cout << S << endl;
        	}
        	printf("%lld\n",ans);
        }
    }
    return 0;
}
/**
233
3 3 3
.Q.
QQQ
.Q.
*/
