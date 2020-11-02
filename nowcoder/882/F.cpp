#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

struct haha {
    int msk;
    LL val;
};

vector<haha> f[2][22];
LL g[2][22][20010];

int n,a[33][33];

void dfs(int d,int p) {
    if(d == n) {
        int sz = 0;
        for(int i = 0;i < n;i ++) if(p >> i & 1) sz ++;
        LL v1 = 0,v2 = 0;
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < n;j ++) {
                if((p>>i&1) && !(p>>j&1)) {
                    v1 += a[i][j];
                    v2 += a[i+n][j+n];
                }
            }
        }
        f[0][sz].push_back((haha){p,v1});
        f[1][sz].push_back((haha){p,v2});
        for(int i = 0;i < n;i ++) {
            v1 = 0, v2 = 0;
            for(int j = 0;j < n;j ++) {
                if(p>>j&1) {
                    v1 += a[i][j+n];
                    v2 += a[i+n][j];
                }
            }
            g[0][i][p] = v1;
            g[1][i][p] = v2;
          //  printf("%d %d %lld\n",i,p,v2);
        }
        return ;
    }
    dfs(d+1,p | (1<<d));
    dfs(d+1,p);
}

int getgray(int x) {
    int bit[22] = {0};
    int len = 0;
    while(x) bit[len ++] = x & 1,x >>= 1;
    int ans = 0;
   // for(int i = len - 1;i >= 0;i --) printf("%d",bit[i]); puts("");
    for(int i = len - 1;i >= 0;i --) {
        int x = bit[i] ^ bit[i+1];
        ans |= x << i;
    }
    return ans;
}

int sx[SZ],lg[SZ];

bool cmpgray(haha x,haha y) {
    return sx[x.msk] < sx[y.msk];
}

void print(int x) {
    for(int i = n-1;i >= 0;i --) {
        printf("%d",x>>i&1);
    }
    puts("");
}

mt19937 rd(time(0));

int main() {
    n = read();
    /*for(int i = 0;i < 2 * n;i ++) {
        for(int j = 0;j < i;j ++) {
            a[i][j] = rd() % (1000000000+1);
        }
    }

    for(int i = 0;i < 2 * n;i ++) {
        for(int j = i+1;j < 2 * n;j ++) {
            a[i][j] = a[j][i];
        }
    }

    for(int i = 0;i < 2 * n;i ++) {
        for(int j = 0;j < 2 * n;j ++) {
            printf("%d ",a[i][j]);
        }
        puts("");
    }*/

    for(int i = 0;i < 2 * n;i ++) {
        for(int j = 0;j < 2 * n;j ++) {
            a[i][j] = read();
        }
    }

    dfs(0,0);
    for(int i = 0;i < (1<<n);i ++) sx[getgray(i)] = i;
    for(int i = 1;i < n;i ++) sort(f[1][i].begin(),f[1][i].end(),cmpgray);
   /* for(int i = 1;i < n;i ++) {
        for(haha s : f[1][i]) {
            printf("%d\n",s.msk);
        }
    }*/
    for(int i = 0;i < n;i ++) lg[1<<i] = i;
    LL ans = 0;
    for(int len = 0;len < n;len ++) {
        for(haha s1 : f[0][len]) {
            bool first = 0;
            LL sum = 0;
            int lst = 0;
            for(haha s2 : f[1][len]) {
                LL d = s1.val + s2.val;
                if(!first) {
                    for(int i = 0;i < n;i ++) {
                        for(int j = 0;j < n;j ++) {
                            if((s1.msk>>i&1) && (s2.msk>>j&1)) {
                                sum += a[i][j+n];
                            }
                            if(!(s1.msk>>i&1) && !(s2.msk>>j&1)) {
                                sum += a[i][j+n];
                            }
                        }
                    }
                    first = 1;
                }
                else {
                 //   printf("-- %d %d %d %lld %lld\n",lst,s2.msk,s1.msk,sum,d);
                    int S = lst ^ s2.msk;
                    while(S) {
                        int id = lg[S&-S];
                        int f = (lst>>id&1) ? -1 : 1;
                    //    printf("%d %d %lld %lld\n",id,f,g[1][id][s1.msk],g[1][id][(1<<n)-1-s1.msk]);
                        sum += f * g[1][id][s1.msk];
                        sum -= f * g[1][id][(1<<n)-1-s1.msk];
                        S ^= 1<<id;
                    }
                   // cout << sum << endl;
                }
              /*
                if(sum + d == 28) {
                    print(s1.msk);
                    print(s2.msk);
                }*/
                ans = max(ans,sum + d);
                lst = s2.msk;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}

/**

2
0 3 2 5
3 0 3 10
2 3 0 5
5 10 5 0

3
0 3 2 6 5 2
3 0 2 1 6 5
2 2 0 6 2 1
6 1 6 0 3 2
5 6 2 3 0 9
2 5 1 2 9 0

3
0 3 2 6 5 2
3 0 2 1 6 5
6 1 6 0 3 2
5 6 2 3 0 9
2 5 1 2 9 0

*/
