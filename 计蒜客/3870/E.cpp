#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 100003;
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

int ans[40001000];
int f[40001000];

int main(){
    int T = read();
    while(T --) {
        int n = read(),k = read() + 1;

        int answer;
        if (k == 1) {
          answer = m - 1;
        } else {
          answer = (k - 1) % (n - m + 1);
          for (long long i = n - m + 2; i <= n; ) {
            if (answer + k >= i) {
              answer = (answer + k) % i;
              ++i;
            } else {
              long long t = min(n - i + 1, (i - answer - 2) / (k - 1));
              answer += t * k;
              i += t;
            }
            cout << answer + 1 << endl;
          }
        }
        //for(int i = 1;i <= n;i ++) printf("%d ",ans[i]); puts("");
      /*  int q = read();
        while(q --) {
            int x = read();
            int t = ans[x];
            printf("%d\n",ans[x]);
        }*/
    }
}
