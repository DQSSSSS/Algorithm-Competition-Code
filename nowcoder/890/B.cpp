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

LL f[SZ];

char s1[] = "COFFEE";
char s2[] = "CHICKEN";

char get(int n,LL k) {
    if(n > 58) return get(n-2,k);
   // assert(k >= 1);
    if(n == 1) {
     //   assert(1 <= k && k <= 6);
        return s1[k-1];
    }
    if(n == 2) {
      //  assert(1 <= k && k <= 7);
        return s2[k-1];
    }
   // assert(k <= f[n]);
    if(k > f[n-2]) return get(n-1,k-f[n-2]);
    else return get(n-2,k);
}

int main() {
    f[1] = 6;
    f[2] = 7;
    for(int i = 3;i <= 58;i ++) {
        f[i] = f[i-1] + f[i-2];
      //  printf("%d %lld\n",i,f[i]);
    }
    int T = read();
    while(T --) {
        int n = read();
        LL k = read();
        while(n>58) n-=2;
        vector<char> g;
        if(n <= 58) {
            for(int i = 0;i < 10 && i+k <= f[n];i ++)
                g.push_back(get(n,i+k));
        }
        else {
            for(int i = 0;i < 10;i ++) g.push_back(get(n,i+k));
        }
        for(int i = 0;i < g.size();i ++) {
            char c = g[i];
            printf("%c",c);
        }
        puts("");
    }
}
