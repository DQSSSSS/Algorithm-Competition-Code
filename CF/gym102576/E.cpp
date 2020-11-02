#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2500010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

struct Point {
    int x,y;
    void Read() {
        x = read(); y = read();
    }
};

struct Circle {
    Point o;
    int r;
}C[SZ];

struct ASK {
    Point P,Q;
    int ymin,ymax;
}ask[SZ];

int A[SZ],B[SZ];
int stMax[22][SZ];
int stMin[22][SZ];

void get_max_st(int A[],int n) {
    for(int i = 1;i <= n;i ++) stMax[0][i] = A[i];
    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i+(1<<(j-1)) <= n;i ++) {
            stMax[j][i] = max(stMax[j-1][i],stMax[j-1][i+(1<<(j-1))]);
        }
    }
}

int ask_max(int l,int r) {
    int k = log2(r-l+1);
    return max(stMax[k][l],stMax[k][r-(1<<k)+1]);
}

void get_min_st(int A[],int n) {
    for(int i = 1;i <= n;i ++) stMin[0][i] = A[i];
    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i+(1<<(j-1)) <= n;i ++) {
            stMin[j][i] = min(stMin[j-1][i],stMin[j-1][i+(1<<(j-1))]);
        }
    }
}

int ask_min(int l,int r) {
    int k = log2(r-l+1);
    return min(stMin[k][l],stMin[k][r-(1<<k)+1]);
}

int lsh[3000010];

int main() {
    int n = read(),q = read();
    for(int i = 1;i <= n;i ++){
        C[i].o.Read(); C[i].r = read();
        lsh[++ lsh[0]] = C[i].o.x;
    }
    for(int i = 1;i <= q;i ++) {
        ask[i].P.Read();
        ask[i].Q.Read();
        ask[i].ymin = read();
        ask[i].ymax = read();
        lsh[++ lsh[0]] = ask[i].P.x;
        lsh[++ lsh[0]] = ask[i].Q.x;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0]) - lsh - 1;
    for(int i = 1;i <= lsh[0];i ++) B[i] = INF;
    for(int i = 1;i <= n;i ++){
        C[i].o.x = lower_bound(lsh+1,lsh+1+lsh[0],C[i].o.x) - lsh;
        A[C[i].o.x] = max(A[C[i].o.x],C[i].r + C[i].o.y);
        B[C[i].o.x] = min(B[C[i].o.x],-C[i].r + C[i].o.y);
    }
    for(int i = 1;i <= lsh[0];i ++) cout << A[i] << " "; puts("");
    for(int i = 1;i <= lsh[0];i ++) cout << B[i] << " "; puts("");

    get_max_st(A,lsh[0]);
    get_min_st(B,lsh[0]);

    for(int i = 1;i <= q;i ++){
        int l = ask[i].P.x = lower_bound(lsh+1,lsh+1+lsh[0],ask[i].P.x) - lsh;
        int r = ask[i].Q.x = lower_bound(lsh+1,lsh+1+lsh[0],ask[i].Q.x) - lsh;
        if(l>r) swap(l,r);
        int Max = ask_max(l,r);
        int Min = ask_min(l,r);
        cout << Max << " " << Min << endl;
        if(Max >= ask[i].ymax || Min <= ask[i].ymin) {
            puts("NO");
        }
        else {
            puts("YES");
        }
    }

}
/*
3 3
3 3 2
7 7 3
12 5 2
1 4 14 4 2 6
1 4 14 4 4 7
1 4 14 4 3 9
*/
