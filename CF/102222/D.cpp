#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

int id[SZ],n;
int zw[SZ];

double work(int f) {
    int t1 = 0,t2 = 0;
    for(int N = 1;N <= 10000000;N ++) {
        for(int i = 1;i <= n;i ++) id[i] = i;
        if(f == 1) random_shuffle(id+1,id+1+n);
        for(int i = 1;i <= n;i ++) zw[i] = 0;
        for(int i = 1;i <= n;i ++) {
            int x = id[i];
            if(x == 1) {
                int k = rand()%(n-(i-1))+1;
                for(int j = 1;j <= n;j ++) {
                    if(zw[j] == 0) {
                        k --;
                        if(k == 0) {
                            zw[j] = x;
                            break;
                        }
                    }
                }
            }
            else {
                if(!zw[x]) zw[x] = x;
                else {
                    int k = rand()%(n-(i-1))+1;
                    for(int j = 1;j <= n;j ++) {
                        if(zw[j] == 0) {
                            k --;
                            if(k == 0) {
                                zw[j] = x;
                                break;
                            }
                        }
                    }
                }
            }
        }
        //puts("----------");
        //for(int i = 1;i <= n;i ++) printf("%d ",id[i]); puts("");
        //for(int i = 1;i <= n;i ++) printf("%d ",zw[i]); puts("");
        t1 ++;
        if(zw[id[n]] == id[n]) t2 ++;
    }
    return 1.0 * t2 / t1;
}
/*
int main() {
    while(cin >> n) {
        printf("%.5f %.5f\n",work(0),work(1));
    }
}*/

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read();
        int m = read();
        double ans = n == 1 ? 1 : 0.5;
        printf("Case #%d: %.6f %.6f\n",cc,ans,(m+1.0)/(2*m));
        //printf("%.6f\n",work(1));
    }
}
