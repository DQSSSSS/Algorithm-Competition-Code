#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e6 + 3;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans %mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int gauss(int mat[12][12],int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++)
            if(mat[j][i]!=0) {
                for(int k = i; k <= n; k++)
                    swap(mat[i][k],mat[j][k]);
                if(i != j)
                    res = (-res+mod)%mod;
                break;
            }
        if(mat[i][i] == 0) {
            res = 0;
            break;
        }
        for(int j = i+1; j <= n; j++) {
            int mut = (1ll*mat[j][i]*ksm(mat[i][i],mod-2))%mod;
            for(int k = i; k <= n; k++)
                mat[j][k] = (mat[j][k]-(1ll*mat[i][k]*mut)%mod+mod)%mod;
        }
        res = (1ll*res * mat[i][i])%mod;
    }
    /*for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= n;j ++)
            cout << mat[i][j] << " ";*/
    return res;
}

int ask(int x) {
    printf("? %d\n",x); fflush(stdout);
    //return (1+1ll*x*x)%mod;
    //return (1000002+1ll*x*x)%mod;
        return read();
}

int g[12][12];
int a[12][12];
int xs[12],b[12],dd[12];
const int N = 11;
mt19937 rd(time(0));

int get_ans() {
//    for(int i = 1;i <= N;i ++) b[i] = (1ll*pri[i] * pri[i] + 1000002) % mod;
 //   for(int i = 1;i <= N;i ++) cout << b[i] << " "; puts("");
    for(int i = 1;i <= N;i ++) dd[i] = i,b[i] = ask(i);

    for(int i = 1;i <= N;i ++) {
        LL t = 1;
        for(int j = 1;j <= N;j ++,t *= dd[i]) {
            a[i][j] = (t %= mod);
        }
    }

    for(int i = 1;i <= N;i ++)
        for(int j = 1;j <= N;j ++)
            g[i][j] = a[i][j];

  // for(int i = 1;i <= N;i ++) cout << dd[i] << " "; puts("");
  /* for(int i = 1;i <= N;i ++) {
        for(int j = 1;j <= N;j ++)
            cout << g[i][j] << " ";
        cout << b[i] << endl;
   }
*/
    LL di = gauss(g,N);
    //cout << di << endl;

    for(int k = 1;k <= N;k ++) {
        for(int i = 1;i <= N;i ++)
            for(int j = 1;j <= N;j ++)
                g[i][j] = a[i][j];
        for(int i = 1;i <= N;i ++)
            g[i][k] = b[i];
      /*  for(int i = 1;i <= N;i ++,puts(""))
            for(int j = 1;j <= N;j ++)
                cout << g[i][j] << " ";
        puts("");*/
        LL tmp = gauss(g,N);
       //cout << tmp << endl;
     //   if(tmp == -1) return -1;
        xs[k-1] = tmp * ksm(di,mod-2) % mod;
    }

   // for(int i = 0;i < N;i ++) cout << xs[i] << " ";
    for(int i = 0;i < mod;i ++) {
        LL x = 1,ans = 0;
        for(int j = 0;j < N;j ++) {
            ans += x * xs[j] % mod;
            ans %= mod;
            x *= i; x %= mod;
        }
        if(ans == 0) return i;
    }
    return -1;
}

int main() {
    for(int i = 1;i <= 1;i ++) {
        int ans = get_ans();
        if(ans == -1) continue;
        else {
            printf("! %d\n",ans);
            return 0;
        }
    }
    printf("! %d\n",-1);
}

