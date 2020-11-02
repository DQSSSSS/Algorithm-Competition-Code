#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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

int pri[10000100],tot;
short vis[100000010];
short mu[100000010];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++tot] = i,mu[i] = 1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
            }
            else {
                mu[m] = mu[i];
            }
        }
    }
    for(int i = 1;i <= 100;i ++) {
        bool flag = 0;
        for(int j = 2;j * j <= i;j ++) {
            if(i%(j*j) == 0) {
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("%d %d\n",i,mu[i]);
    }
    int B = 6;
    int tong[1<<B] = {};
    for(int i = 1;i + B - 1 <= n;i ++) {
        int t = 0;
        for(int j = 0;j < B;j ++) {
            t |= mu[i+j] << j;
        }
        tong[t] ++;
    }
    for(int i = 0;i < (1<<B);i ++) {
        printf("%d %d\n",i,tong[i]);
    }
    cout << tot << endl;
}

int main() {
    shai(1e7);
}

/**
111_1110011011101010
111_0100111011101110
111_0110001010101110
110_1110111011001110
011_1110101011101000
111_1110111011100110
011_010111011001110
111_1100101001101110
101_1110010011001110
111_1110011011101010
*/
