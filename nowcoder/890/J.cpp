#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

struct haha {
    LL w,h;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.h > b.h;
}

int q[SZ];

LL f[5010][2010],s[5010];

int main() {
    int n = read(),K = read();
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        a[i].w = read();
        a[i].h = read();
        ans += a[i].w * a[i].h;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i <= n;i ++) s[i] = s[i-1] + a[i].w;
    for(int k = 1;k <= K;k ++) {
        int t = 1,w = 1;
        q[1] = 0;
        for(int i = 1;i <= n;i ++) {
            while(t < w && f[q[t+1]][k-1]-f[q[t]][k-1] >
                  a[i].h * ((__int128)s[q[t+1]] - s[q[t]])) t ++;
            int j = q[t];
            f[i][k] = f[j][k-1] + a[i].h * (s[i] - s[j]);
            while(t < w && ((__int128)f[q[w]][k-1]-f[q[w-1]][k-1]) * (s[i] - s[q[w]]) <
                  ((__int128)f[i][k-1] - f[q[w]][k-1]) * (s[q[w]] - s[q[w-1]]) ) w --;
            q[++ w] = i;
        }
    }
    cout << ans - f[n][K] << endl;
}
