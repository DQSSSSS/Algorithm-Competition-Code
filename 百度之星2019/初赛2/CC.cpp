#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 3e6 + 10;
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

char s[SZ];

int main() {
  //  freopen("C.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        scanf("%s",s+1);
        int n = strlen(s+1);
        s[0] = '^'; s[n+1] = '^'; n ++;
        vector<int> g;
        int t = 0;
        for(int i = 1,lst = 0;i <= n;i ++) {
            if(s[i] == '^') {
                if(i-lst>1)
                    g.push_back(i-lst);
                t ^= (i-lst)&1;
                lst = i;
            }
        }
        /*int n = read(),t = 0;
        vector<int> g;
        for(int i = 0;i < n;i ++) g.push_back(read()),t ^= g[i]&1;*/
        for(int i = 1<<22;i > 1;i /= 2) {
            for(int &x :g) {
                if(x >= i) {
                    x -= i;
                    t |= i;
                    break;
                }
            }
        }
//        for(int x : g) printf("%d ",x); puts("");
        printf("%d\n",t);
    }
}

