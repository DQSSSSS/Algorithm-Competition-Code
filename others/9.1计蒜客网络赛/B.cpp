#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int a[SZ][110],num[110],S[110],L[110],R[110];
pii b[110];

LL sum[SZ][110];

int baoli(int n,int m) {
    for(int i = 1;i <= n;i ++)
    	for(int j = 1;j <= m;j ++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    int ans = 0;
    for(int a = 1;a <= n;a ++)
   		for(int b = 1;b <= m;b ++)
   			for(int c = a;c <= n;c ++)
   				for(int d = b;d <= m;d ++) {
                    if(sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1] == 0)
                        ans ++;
   				}
   	return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	int T = read(),cc = 0;
	while(T --) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
            	a[i][j] = 0;
		for(int i = 1;i <= k;i ++) {
			int x,y;
            scanf("%d%d",&x,&y);
            a[x][y] = 1;
		}
		//for(int i = 1;i <= n;i ++,puts(""))
      //      for(int j = 1;j <= m;j ++)
      //      	cout << a[i][j] << " ";
      //  puts("");
		//cout << n << " " << m << endl;
		for(int i = 1;i <= m;i ++) num[i] = 0;
		LL ans = 0;
		for(int d = 1;d <= n;d ++) {
            for(int i = 1;i <= m;i ++) {
                num[i] = a[d][i] == 0 ? num[i] + 1 : 0;
            }
          //  for(int i = 1;i <= m;i ++) cout << num[i] << " "; puts("");
            int top;
            S[top = 0] = 0;
            for(int i = 1;i <= m;i ++) {
                while(top && num[S[top]] > num[i]) top --;
                L[i] = top ? S[top] + 1 : 1;
                S[++ top] = i;
            }
            S[top = 0] = 0;
            for(int i = m;i >= 1;i --) {
                while(top && num[S[top]] >= num[i]) top --;
                R[i] = top ? S[top] - 1 : m;
                S[++ top] = i;
            }
            LL tmp = 0;
          //  for(int i = 1;i <= m;i ++) cout << L[i] << " "; puts("");
          //  for(int i = 1;i <= m;i ++) cout << R[i] << " "; puts("");
            for(int i = 1,lst = 1;i <= m;i ++) {
            	if(i == m || num[i + 1] != num[i]) {
					int r = R[i] - i + 1,l = lst - L[lst] + 1;
       	        	tmp += (l - 1) * (r - 1) * num[i];
       	        	int len = i - lst + 1;
       	        	tmp += (1ll * len * (l - 1)) * num[i];
       	        	tmp += (1ll * len * (r - 1)) * num[i];
       	        	tmp += (1ll * len * (len + 1) / 2) * num[i];
       	  //      	cout << i << " " << len << " " << l << " " << r << endl;
       	        	lst = i + 1;
				}
			}
            ans += tmp;
         //   cout << tmp << endl;
		}
		printf("Case #%d: %lld\n",++ cc,ans);
	//	int tmp = baoli(n,m);
	//	if(tmp != ans) {puts("fuck"); printf("%d\n",tmp); return 0;}
//
	}
    return 0;
}

/***
233
5 3 3
5 2
1 2
1 3

233
4 5 18
4 3
2 3
2 1
3 1
2 3
1 3
3 5
1 3
4 5
1 4
1 3
2 1
1 2
2 2
2 1
3 2
1 2
2 3

0 1 1 1 0
1 1 1 0 0
1 1 0 0 1
0 0 1 0 1
*/
